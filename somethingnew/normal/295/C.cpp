#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "queue"
#define all(x) (x).begin(), (x).end()

using namespace std;
struct pos{
    int ap, bp, turn, cntt;
};
long long mod = 1e9 + 7;
bool add(pair<int, long long> &a, int b, long long c) {
    if (a.first > b) {
        a.first = b;
        a.second = c;
        return 1;
    }
    if (a.first == b) {
        a.second += c;
        if (a.second >= mod)
            a.second -= mod;
    }
    return 0;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int a = 0, b = 0;
    k /= 50;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 50)
            a++;
        else
            b++;
    }
    vector<vector<long long>> cnk(200, vector<long long>(200));
    for (int l = 0; l < 200; ++l) {
        cnk[0][l] = 1;
        cnk[l][0] = 1;
    }
    for (int i = 1; i < 200; ++i) {
        for (int j = 1; j < 200; ++j) {
            cnk[i][j] = cnk[i][j-1] + cnk[i-1][j];
            if (cnk[i][j] >= mod)
                cnk[i][j] %= mod;
        }
    }
    vector<vector<vector<pair<int, long long>>>> dp(a + 1, vector<vector<pair<int, long long>>>(b + 1, vector<pair<int, long long>>(2, {1e9 + 7, 0})));
    queue<pos> que;
    que.push({a, b, 0, 0});
    dp[a][b][0] = {0, 1};
    while (!que.empty()) {
        auto [anum, bnum, side, chch] = que.front();
        que.pop();
        if (dp[anum][bnum][side].first != chch) {
            continue;
        }
        long long val = dp[anum][bnum][side].second;
        //cout << anum << ' ' << bnum << ' ' << side << ' ' << chch << " " << val << endl;
        if (side == 0) {
            for (int i = 0; i <= anum; ++i) {
                for (int j = 0; j <= bnum; ++j) {
                    if (i + j * 2 > k)
                        break;
                    if (i + j == 0)
                        continue;
                    if (add(dp[anum - i][bnum - j][1], chch + 1, val * cnk[i][anum - i] % mod * cnk[j][bnum - j] % mod)) {
                        que.push({anum - i, bnum - j, 1, chch + 1});
                    }
                }
            }
        } else {
            for (int i = 0; i + anum <= a; ++i) {
                for (int j = 0; j + bnum <= b; ++j) {
                    if (i + j * 2 > k)
                        break;
                    if (i + j == 0)
                        continue;
                    if (add(dp[anum + i][bnum + j][0], chch + 1, val * cnk[i][a - anum - i] % mod * cnk[j][b - bnum - j] % mod)) {
                        que.push({anum + i, bnum + j, 0, chch + 1});
                    }
                }
            }
        }
    }
    if (dp[0][0][1].second == 0) {
        cout << "-1\n0";
        return 0;
    }
    cout << dp[0][0][1].first << '\n' << dp[0][0][1].second;
}