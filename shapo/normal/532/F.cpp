#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <tuple>
#include <utility>

using namespace std;

const int MLEN = 200500;
const int NB = 2;

const int MODS[] = {1236823303, 1000000007};
const int BASES[] = {123479, 345791};

char s[MLEN], t[MLEN];
int slen, tlen;
int sfpos[MLEN][26];
int tfpos[26];
int get_pos[MLEN];
int hsh[NB][26][MLEN];
int thsh[NB][26];
int pows[NB][MLEN];
int tmppos[26];

inline pair< int, int >
get_hash(int from, int to, int c_id)
{
    int res[2];
    for (int it = 0; it < 2; ++it) {
        int a = hsh[it][c_id][to], b = (from == 0) ? 0 : 
            1ll * hsh[it][c_id][from - 1] * pows[it][to - from + 1] % MODS[it];
        res[it] = (a - b);
        if (res[it] < 0) {
            res[it] += MODS[it];
        }
    }
    return {res[0], res[1]};
}

int
main()
{
    for (int it = 0; it < 2; ++it) {
        pows[it][0] = 1;
        for (int i = 1; i < MLEN; ++i) {
            pows[it][i] = 1ll * pows[it][i - 1] * BASES[it] % MODS[it];
        }
    }
    scanf("%d%d", &slen, &tlen);
    scanf(" %s %s", s, t);
    { // hashes for t
        for (int it = 0; it < 2; ++it) {
            for (int c_id = 0; c_id < 26; ++c_id) {
                thsh[it][c_id] = 0;
                for (int i = 0; i < tlen; ++i) {
                    int add = ((t[i] - 'a') == c_id) ? 1 : 0;
                    thsh[it][c_id] = (add + 1ll * BASES[it] * thsh[it][c_id]) % MODS[it];
                }
            }
        }
    }
    { // hashes for s
        for (int it = 0; it < 2; ++it) {
            for (int c_id = 0; c_id < 26; ++c_id) {
                int cur_hsh = 0;
                for (int i = 0; i < slen; ++i) {
                    int add = ((s[i] - 'a') == c_id) ? 1 : 0;
                    cur_hsh = (add + 1ll * BASES[it] * cur_hsh) % MODS[it];
                    hsh[it][c_id][i] = cur_hsh;
                }
            }
        }
    }
    { // calc tfpos by brute force
        for (int i = 0; i < 26; ++i) {
            tfpos[i] = tlen;
        }
        for (int i = 0; i < tlen; ++i) {
            if (tfpos[t[i] - 'a'] == tlen) {
                tfpos[t[i] - 'a'] = i;
            }
        }
    }
    for (int i = 0; i <= tlen; ++i) {
        get_pos[i] = 0;
    }
    { // calc sfpos using dp
        for (int i = 0; i < 26; ++i) {
            sfpos[slen][i] = -1;
        }
        for (int i = slen - 1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j) {
                sfpos[i][j] = sfpos[i + 1][j];
            }
            sfpos[i][s[i] - 'a'] = i;
        }
    }
    vector< int > ans;
    for (int pos = 0; pos + tlen <= slen; ++pos) {
        for (int i = 0; i < 26; ++i) {
            get_pos[tfpos[i]] = 0;
        }
        for (int i = 0; i < 26; ++i) {
            get_pos[tfpos[i]]++;
        }
        bool ok = true;
        for (int i = 0; i < 26 && ok; ++i) {
            int dlen = sfpos[pos][i] - pos;
            if (dlen < 0 || dlen >= tlen) {
                dlen = tlen;
            }
            tmppos[i] = dlen;
            if (!get_pos[dlen]) {
                ok = false;
            } else {
                get_pos[dlen]--;
            }
        }
        for (int i = 0; i < 26; ++i) {
            get_pos[tfpos[i]] = i;
        }
        for (int i = 0; i < 26 && ok; ++i) {
            if (tmppos[i] >= tlen) {
                continue;
            }
            int imp_ind = get_pos[tmppos[i]];
            if (imp_ind != i) {
                if (tmppos[imp_ind] != tfpos[i]) {
                    ok = false;
                    break;
                }
            }
            if (get_hash(pos, pos + tlen - 1, i) != 
                    make_pair(thsh[0][imp_ind], thsh[1][imp_ind])) {
                ok = false;
            }
        }
        if (ok) {
            ans.push_back(pos + 1);
        }
    }
    printf("%d\n", int(ans.size()));
    for (auto x : ans) {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}