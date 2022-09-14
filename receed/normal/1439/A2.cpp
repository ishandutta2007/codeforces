#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 101;
int a[N][N];
vector<vector<int>> ans;

void q(int ax, int ay, int bx, int by, int cx, int cy) {
    a[ax][ay] ^= 1;
    a[bx][by] ^= 1;
    a[cx][cy] ^= 1;
    ans.push_back({ax, ay, bx, by, cx, cy});
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, m;
    cin >> t;
    rep(z, t) {
        cin >> n >> m;
        string s;
        rep(i, n) {
            cin >> s;
            rep(j, m)
                a[i][j] = s[j] - '0';
        }
        ans.clear();
        rep(i, n - 2)
            rep(j, m) {
                if (a[i][j])
                    q(i, j, i + 1, j, i + 1, j + (j == 0 ? 1 : -1));
            }
        rep(i, m - 2) {
            if (a[n - 2][i] && a[n - 1][i])
                q(n - 2, i, n - 1, i, n - 2, i + 1);
            else if (a[n - 2][i])
                q(n - 2, i, n - 2, i + 1, n - 1, i + 1);
            else if (a[n - 1][i])
                q(n - 1, i, n - 1, i + 1, n - 2, i + 1);
        }
        int ss = 0;
        rep(i, 2)
            rep(j, 2)
                ss ^= a[n - 2 + i][m - 2 + j];
        rep(i, 2) {
            rep(j, 2) {
                if (a[n - 2 + i][m - 2 + j] == ss)
                    continue;
                vector<int> cv;
                rep(i1, 2)
                    rep(j1, 2)
                        if (i1 != i || j1 != j) {
                            cv.push_back(n - 2 + i1);
                            cv.push_back(m - 2 + j1);
                        }
                ans.push_back(cv);
            }
        }
        cout << ans.size() << '\n';
        for (auto &pp : ans) {
            for (int i : pp)
                cout << i + 1 << ' ';
            cout << '\n';
        }
    }
}