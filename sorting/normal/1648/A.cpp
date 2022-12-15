#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const int C = 1e5 + 3;

vector<pair<int, int>> c[C];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            int x;
            cin >> x;
            c[x].push_back({i, j});
        }

    ll ans = 0;
    for(int i = 0; i < C; ++i){
        sort(all(c[i]));
        ll sum = 0;
        for(int j = 0; j < c[i].size(); ++j){
            ans += (ll)c[i][j].first * j - sum;
            sum += c[i][j].first;
        }

        sort(all(c[i]), [&](auto l, auto r){return l.second < r.second;});
        sum = 0;
        for(int j = 0; j < c[i].size(); ++j){
            ans += (ll)c[i][j].second * j - sum;
            sum += c[i][j].second;
        }
    }
    cout << ans << "\n";
}