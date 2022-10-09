#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

const int mod = 998244353;

bool g[20][20];
int pc1[3500][14][70];
int pc2[3500][14][70];
int pc3[3500][130][70];
int pc4[3500][14];

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    //n = 14;
    forn (i, n) {
        string s;
        cin >> s;
        forn (j, n) {
            g[i][j] = s[j] == '1';
            //g[i][j] = rand() % 2;
        }
    }
    int n1 = n / 2, n2 = n - n / 2;
    vector<int> masks1, masks2;
    forn (mask, 1 << n) {
        if (__builtin_popcount(mask) == n1) {
            masks1.push_back(mask);
            masks2.push_back(mask ^ ((1 << n) - 1));
            forn (j, n) {
                if (!(mask & (1 << j))) {
                    continue;
                }
                for (int k = n - 1; k >= 0; --k) {
                    if (!(mask & (1 << k))) {
                        pc4[masks1.size() - 1][j] <<= 1;
                        pc4[masks1.size() - 1][j] += g[j][k];
                    }
                }
            }
        }
    }
    forn (i, masks1.size()) {
        vector<int> ind;
        forn (j, n) {
            if (masks1[i] & (1 << j)) {
                ind.push_back(j);
            }
        }
        do {
            int res = 0;
            for (int j = 0; j < (int)(ind.size()) - 1; ++j) {
                res <<= 1;
                res += g[ind[j]][ind[j + 1]];
            }
            pc1[i][ind.back()][res]++;
        } while (next_permutation(ind.begin(), ind.end()));
    }
    //cerr << "!" << endl;
    forn (i, masks2.size()) {
        vector<int> ind;
        forn (j, n) {
            if (masks2[i] & (1 << j)) {
                ind.push_back(j);
            }
        }
        do {
            int res = 0;
            for (int j = 0; j < (int)(ind.size()) - 1; ++j) {
                res <<= 1;
                res += g[ind[j]][ind[j + 1]];
            }
            pc2[i][ind[0]][res]++;
        } while (next_permutation(ind.begin(), ind.end()));
        ind.clear();
        forn (j, n) {
            if (masks2[i] & (1 << j)) {
                ind.push_back(j);
            }
        }
        forn (m, (1 << n2)) {
            forn (res, (1 << (n2 - 1))) {
                forn (j, n2) {
                    if (m & (1 << j)) {
                        pc3[i][m][res] += pc2[i][ind[j]][res];
                    }
                }
            }
        }
    }
    //cerr << "!" << endl;
    vector<int> ans(1 << (n - 1));
    /*forn (i, masks1.size()) {
        forn (from, n) {
            if (!((1 << from) & masks1[i])) {
                continue;
            }
            forn (to, n) {
                if (!((1 << to) & masks2[i])) {
                    continue;
                }
                forn (res1, (1 << (n1 - 1))) {
                    int cur_m = (res1 << n2) + ((int)(g[from][to]) << (n2 - 1));
                    forn (res2, (1 << (n2 - 1))) {
                        //cerr << (res1 << n2) + ((int)(g[from][to]) << (n2 - 1)) + res2  << " " << pc1[masks1[i]][from][res1] << " " << pc2[masks2[i]][to][res2] << endl;
                        ans[cur_m++] += pc1[i][from][res1] * pc2[i][to][res2];
                    }
                }
            }
        }
    }*/
    forn (i, masks1.size()) {
        forn (from, n) {
            if (!((1 << from) & masks1[i])) {
                continue;
            }
            forn (res1, (1 << (n1 - 1))) {
                int cur_m = (res1 << n2) + (1 << (n2 - 1));
                int neigh = pc4[i][from];
                int cnt = pc1[i][from][res1];
                forn (res2, (1 << (n2 - 1))) {
                    ans[cur_m++] += cnt * pc3[i][neigh][res2];
                }
                cur_m = (res1 << n2);
                int not_neigh = ((1 << n2) - 1) ^ pc4[i][from];
                forn (res2, (1 << (n2 - 1))) {
                    ans[cur_m++] += cnt * pc3[i][not_neigh][res2];
                }
            }
        }
    }
    //cerr << "!" << endl;
    for (int x: ans) {
        cout << x << ' ';
    }
    cout << endl;
}