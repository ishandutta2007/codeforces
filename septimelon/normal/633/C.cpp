#pragma GCC optimize("O3")

#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

using namespace std;

typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ld INFLD = 1e20;
const ll INFL = 2e18;
const int INF = 2e9 + 7;
const ld PI = acos(-1);
const ld E = exp(1);

//mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(123876);

double ReadDouble() {
    string s;
    cin >> s;
    return stol(s);
}

namespace AhoCorasick {
    const int MAXN = 1000100;
    const int ALPH = 26;

    int size;
    int h[MAXN], root[MAXN], char_ind[MAXN], prev[MAXN], prev_str[MAXN], is_str[MAXN];
    int next[MAXN][ALPH];

    void AddNode(int ch, int c_root, int char_i) {
        h[size] = ch;
        root[size] = c_root;
        char_ind[size] = char_i;
        prev[size] = 0;
        prev_str[size] = 0;
        is_str[size] = -1;
        for (int i = 0; i < ALPH; ++i) {
            next[size][i] = -1;
        }
        ++size;
    }

    void Init() {
        size = 0;
        AddNode(0, 0, 0);
    }

    void AddString(const string& s, int string_ind) {
        int cn = 0;
        for (char c : s) {
            if (next[cn][c - 'a'] == -1) {
                AddNode(h[cn] + 1, cn, c - 'a');
                next[cn][c - 'a'] = size - 1;
            }
            cn = next[cn][c - 'a'];
        }
        is_str[cn] = string_ind;
    }

    void ConstructAho() {
        queue<int> que;
        // Insert all root's children into queue
        for (int i = 0; i < ALPH; ++i) {
            if (next[0][i] == -1) {
                next[0][i] = 0;
            }
            else {
                que.push(next[0][i]);
            }
        }

        // Go through the nodes with BFS, set their 'prev', 'prev_string' and 'next' values
        while (!que.empty()) {
            int cn = que.front();
            que.pop();
            prev[cn] = next[prev[root[cn]]][char_ind[cn]];
            if (prev[cn] == cn) {
                prev[cn] = 0;
            }
            if (is_str[prev[cn]] >= 0) {
                prev_str[cn] = prev[cn];
            }
            else {
                prev_str[cn] = prev_str[prev[cn]];
            }
            for (int i = 0; i < ALPH; ++i) {
                if (next[cn][i] == -1) {
                    next[cn][i] = next[prev[cn]][i];
                }
                else {
                    que.push(next[cn][i]);
                }
            }
        }
    }
};

vector<int> Prefix(string s) {
    int n = s.length();
    vector<int> pr(n);
    for (int i = 1; i < n; i++) {
        int j = pr[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pr[j - 1];
        if (s[i] == s[j])
            j++;
        pr[i] = j;
    }
    return pr;
}

void Solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s_rev = s;
    reverse(s_rev.begin(), s_rev.end());

    int m;
    cin >> m;
    vector<string> ns(m);
    vector<string> low_n(m);
    vector<int> siz(m);
    for (int i = 0; i < m; ++i) {
        cin >> ns[i];
        siz[i] = ns[i].size();
        low_n[i] = ns[i];
        for (char& c : low_n[i]) {
            c = tolower(c);
        }
    }

    //cerr << "Constructing Aho...\n";
    AhoCorasick::Init();
    for (int i = 0; i < m; ++i) {
        AhoCorasick::AddString(low_n[i], i);
    }
    //cerr << "Added strings...\n";
    AhoCorasick::ConstructAho();

    //cerr << "Constructed Aho\n";

    vector<int> last(n + 1, -1);
    last[n] = 0;

    int cn = 0;
    for (int i = n - 1; i >= 0; --i) {
        char c = s_rev[n - 1 - i];
        cn = AhoCorasick::next[cn][c - 'a'];
        //cerr << c << "[" << cn << "] -> ";
        assert(cn >= 0);
        
        if (AhoCorasick::is_str[cn] >= 0 && last[i + AhoCorasick::h[cn]] >= 0) {
            last[i] = AhoCorasick::is_str[cn];
        }
        int ind = AhoCorasick::prev_str[cn];
        while (ind > 0) {
            if (last[i + AhoCorasick::h[ind]] >= 0) {
                last[i] = AhoCorasick::is_str[ind];
            }
            ind = AhoCorasick::prev_str[ind];
        }
    }
    //cerr << "\n";

    //cerr << "Found prevs\n";

    assert(last[0] >= 0);
    vector<int> ans;
    for (int i = 0; i < n; i += siz[last[i]]) {
        ans.push_back(last[i]);
    }

    for (int i = 0; i <= ans.size() - 1; ++i) {
        cout << ns[ans[i]] << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL

    int t = 1;
    //cin >> t;
    for (int q = 0; q < t; ++q) {
        Solve();
    }

    return 0;
}