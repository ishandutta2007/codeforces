#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }

const int N = 6000 + 3;

int n;
pair<int, int> p[N];
ll cnt[2][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> p[i].first >> p[i].second;
        p[i].first /= 2;
        p[i].first &= 1;
        p[i].second /= 2;
        p[i].second &= 1;
        ++cnt[p[i].first][p[i].second];
    }

    ll ans = 0;
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j){
            ll x = cnt[i][j];
            if(x >= 3) ans += x * (x - 1) * (x - 2) / 6;
            if(x >= 2) ans += x * (x - 1) / 2 * (n - x);
         }
    cout << ans << "\n";
}