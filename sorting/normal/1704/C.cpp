#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        ll n, m;
        cin >> n >> m;
        vector<ll> a(m);
        for(int i = 0; i < m; ++i)
            cin >> a[i];
        sort(all(a));
        vector<ll> d(m);
        for(int i = 1; i < m; ++i)
            d.push_back(a[i] - a[i - 1] - 1);
        d.push_back(a[0] - a[m - 1] + n - 1);
        sort(all(d), greater<ll>());

        ll day = 0, ans = 0;
        for(int i = 0; i < m; ++i){
            ll curr = d[i] - 2 * day;
            if(curr > 0){
                if(curr == 1){
                    ans += 1;
                    day += 1;
                }
                else{
                    ans += curr - 1;
                    day += 2;
                }
            }
        }

        cout << n - ans << "\n";
    }
}