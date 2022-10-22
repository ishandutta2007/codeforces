#include <bits/stdc++.h>
using namespace std;

long long a[101][101];
int main() {
    int n , m , x , y;
    long long k;
    cin >> n >> m >> k >> x >> y;
    vector< pair<int , int> > V;
    if (n == 1) {
        for (int i = 0 ; i < m ; ++ i) {
            V.push_back({1 , i + 1});
        }
    } else {
        for (int i = 1 ; i < n ; ++ i) {
            for (int j = 1 ; j <= m ; ++ j) {
                V.push_back({i , j});
            }
        }
        for (int i = 1 ; i < n ; ++ i) {
            for (int j = 1 ; j <= m ; ++ j) {
                V.push_back({n - i + 1 , j});
            }
        }
    }
    int T = V.size();
    long long P = k / T , mn = 1LL << 60 , mx = 0;
    for (auto it : V) {
        a[it.first][it.second] += P;
    }
    k %= T;
    for (auto it : V) {
        if (!k) break; -- k;
        a[it.first][it.second] ++;
    }
    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 1 ; j <= m ; ++ j) {
            mn = min(mn , a[i][j]);
            mx = max(mx , a[i][j]);
        }
    }
    cout << mx << ' ' << mn << ' ' << a[x][y] << endl;

}