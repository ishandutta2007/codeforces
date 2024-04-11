#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXL = 100500;
const int MAXV = 20 * MAXL;

// Parameters for trie
int root = 1, ind = 1;
int to[MAXV][4];

// string itself
char t[MAXL];
int tlen;

ll n;

// minimal len of string which isn't present in trie,
// started with one symbols and ended with another
int min_lost_len[4][4];
int used[4];
int len[4];

// for maxtrix multiplication
const int MAXD = 60;
ll val[MAXD][4][4];

void
add(char *s, int all_len)
{
    /*
     * Added substring of length min(all_len, rest_len) to trie
     */
    int cur_v = root;
    for (int i = 0; i < all_len && s[i]; ++i) {
        if (to[cur_v][s[i] - 'A'] == 0) {
            ++ind;
            to[cur_v][s[i] - 'A'] = ind;
        }
        cur_v = to[cur_v][s[i] - 'A'];
    }
}

int
get_depth(int v, int symb)
{
    if (v == 0 || to[v][symb] == 0) {
        return 0;
    }
    auto tmp_arr = {get_depth(to[v][0], symb), get_depth(to[v][1], symb),
            get_depth(to[v][2], symb), get_depth(to[v][3], symb)};
    return *min_element(tmp_arr.begin(), tmp_arr.end()) + 1;
}

bool
can_get_len(ll el_time, ll len)
{
    ll res_val[4][4] = {};
    ll tmp_val[4][4];
    for (int bit = MAXD - 1; bit >= 0; --bit) {
        if (el_time & (1ll << bit)) {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    ll &res = tmp_val[i][j] = -1ll;
                    for (int k = 0; k < 4; ++k) {
                        ll cur_val = res_val[i][k] + val[bit][k][j];
                        if (res == -1 || res > cur_val) {
                            res = cur_val;
                        }
                    }
                }
            }
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j) {
                    res_val[i][j] = tmp_val[i][j];
                }
            }
        }
        ll min_val = len;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                min_val = min(min_val, res_val[i][j]);
            }
        }
        if (min_val >= len) {
            return true;
        }
    }
    return false;
}

int
main()
{
    scanf("%lld %s", &n, t);
    tlen = strlen(t);
    // Added strings with little length to trie,
    for (int i = 0; i < tlen; ++i) {
        add(t + i, 11);
    }
    for (int start_symb = 0; start_symb < 4; ++start_symb) {
        for (int end_symb = 0; end_symb < 4; ++end_symb) {
            val[0][start_symb][end_symb] = get_depth(to[root][start_symb], end_symb) + 1;
        }
    }
    for (int level = 1; level < MAXD; ++level) {
        for (int start_symb = 0; start_symb < 4; ++start_symb) {
            for (int end_symb = 0; end_symb < 4; ++end_symb) {
                // initval
                ll &res = val[level][start_symb][end_symb];
                res = -1ll;
                for (int inter_symb = 0; inter_symb < 4; ++inter_symb) {
                    ll cur_val = val[level - 1][start_symb][inter_symb] +
                        val[level - 1][inter_symb][end_symb];
                    if (res == -1ll || res > cur_val) {
                        res = cur_val;
                    }
                }
            }
        }
    }
    ll l_bord = 0, r_bord = n + 1;
    while (l_bord < r_bord - 1) {
        ll m_bord = (l_bord + r_bord) / 2;
        if (can_get_len(m_bord, n)) {
            r_bord = m_bord;
        } else {
            l_bord = m_bord;
        }
    }
    cout << r_bord << '\n';
    return 0;
}