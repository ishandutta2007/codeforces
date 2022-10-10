#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
vector<vector<int>> v, col, ans;
int n, m, a, b;
 
void whee(int r) {
    deque<pair<int, int>> wind;
    int j = 0;
    for(int i = 0; i + b <= m; i++) {
        while(j < i + b) {
            while(wind.size() && wind.back().first >= v[r][j])
                wind.pop_back();
            wind.push_back({v[r][j], j});
            j++;
        }
        while(wind.size() && wind.front().second < i)
            wind.pop_front();
        col[r][i] = wind.front().first;
    }
}
 
void wheee(int c) {
    deque<pair<int, int>> wind;
    int j = 0;
    for(int i = 0; i + a <= n; i++) {
        while(j < i + a) {
            while(wind.size() && wind.back().first >= col[j][c])
                wind.pop_back();
            wind.push_back({col[j][c], j});
            j++;
        }
        while(wind.size() && wind.front().second < i)
            wind.pop_front();
        ans[i][c] = wind.front().first;
    }
}
 
int main() {
    cin >> n >> m >> a >> b;
    v.assign(n, vector<int>(m));
    col.assign(n, vector<int>(m - b + 1));
    ans.assign(n - a + 1, vector<int>(m - b + 1));
    ll g0, x, y, z;
    cin >> g0 >> x >> y >> z;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            v[i][j] = g0;
            g0 = (g0 * x + y) % z;
        }
    }
 
    for(int i = 0; i < n; i++)
        whee(i);
 
    for(int j = 0; j <= m - b; j++)
        wheee(j);
 
    ll tot = 0;
 
    for(int i = 0; i <= n - a; i++)
        for(int j = 0; j <= m - b; j++) 
            tot += ans[i][j];
 
    cout << tot << '\n';
}