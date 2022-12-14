#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 2048, MaxL = 512, MaxA = 26;

int to[MaxA][MaxL], pi[MaxL], ans[MaxN];
vector < bitset <MaxN> > bitDp[2][MaxL];

int main() {
//    freopen("input.txt", "r", stdin);
    string s, p;
    cin >> s >> p;
    p += "$";
    for (int i = 0; i < (int)p.length(); ++i) {
        if (i > 0) {
            int j = pi[i - 1];
            while (j > 0 && p[j] != p[i]) {
                j = pi[j - 1];
            }
            pi[i] = j + (p[i] == p[j]);
        }
        for (int c = 0; c < MaxA; ++c) {
            int j = i;
            while (j > 0 && c != p[j] - 'a') {
                j = pi[j - 1];
            }
            to[c][i] = j + (c == p[j] - 'a');
        }
    }
    int sl = (int)s.length(), pl = (int)p.length();
    for (int i = 0; i <= pl; ++i) {
        int len = sl / (pl - 1) + 2;
        bitDp[0][i].resize(len);
        bitDp[1][i].resize(len);
        for (int j = 0; j < len; ++j) {
            bitDp[0][i][j].reset();
            bitDp[1][i][j].reset();
        }
    }
    int tot = 0;
    for (int i = 0; i <= sl; ++i) {
        int cur = i & 1, nxt = 1 - (i & 1);
        if (i < sl) {
            bitDp[cur][to[s[i] - 'a'][0]][0].set(i);
        }
        if (i == sl) {
            for (int k = 0; k < pl; ++k) {
                for (int l = 0; l < (int)bitDp[cur][k].size(); ++l) {
                    for (int j = bitDp[cur][k][l]._Find_first(); j < sl; j = bitDp[cur][k][l]._Find_next(j)) {
                        if (ans[j] < l) {
                            ans[j] = l;
                        }
                    }
                }
            }
        }
        int c = i + 1 < sl ? s[i + 1] - 'a' : 0;
        for (int k = 0; k + 1 < pl; ++k) {
            for (int l = 0; l < (int)bitDp[cur][k].size(); ++l) {
                if (bitDp[cur][k][l].any()) {
                    bitDp[nxt][to[c][k]][l] |= bitDp[cur][k][l];
                    bitDp[nxt][k][l] |= bitDp[cur][k][l] << 1;
                } else {
                    break;
                }
            }
        }
        {
            int k = pl - 1;
            for (int l = 0; l < (int)bitDp[cur][k].size(); ++l) {
                if (bitDp[cur][k][l].any()) {
                    bitDp[nxt][to[c][0]][l + 1] |= bitDp[cur][k][l];
                    bitDp[nxt][k][l] |= bitDp[cur][k][l] << 1;
                }
            }
        }
        for (int k = 0; k < pl; ++k) {
            for (int l = 0; l < (int)bitDp[cur][k].size(); ++l) {
                bitDp[cur][k][l].reset();
            }
        }
    }
    for (int i = 0; i <= sl; ++i) {
        printf("%d%c", (int)ans[i], i == sl ? '\n' : ' ');
    }
    return 0;
}