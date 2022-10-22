#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 100000000000000000;

ll s[1000005];
ll l[1000005];

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) scanf("%lld", &s[i]);
    if(m > 0 && s[0] == 0){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++) l[i] = i;
    for(int i = 0; i < m; i++) l[s[i]] = l[s[i] - 1];
    ll ans = INF;
    for(int i = 1; i <= k; i++){
        ll c = 0;
        ll j = 0;
        bool f = true;
        while(true){
            if(j + i >= n){
                c++;
                break;
            }
            if(l[j + i] == j){
                f = false;
                break;
            }
            j = l[j + i];
            c++;
        }
        ll a;
        scanf("%lld", &a);
        if(f) ans = min(ans, c * a);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}