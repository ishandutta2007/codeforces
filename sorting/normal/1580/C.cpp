#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const ll N = 2e5 + 3;
const ll T = 450;
const ll P = max(N / T, T) + 3;

ll n, m;
ll x[N], y[N], start[N];
ll pr[N];
ll cnt[P][P];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(ll i = 1; i <= n; ++i)
        cin >> x[i] >> y[i];

    ll ans = 0;
    for(ll i = 1; i <= m; ++i){
        ll op, k;
        cin >> op >> k;

        for(ll j = 2; j < T; ++j)
            ans += cnt[j][i % j];
        ans += pr[i];

        if(op == 1){
            if(x[k] + y[k] >= T){
                ll t = i + x[k];
                while(t <= m){
                    pr[t] += 1;
                    t += y[k];
                    if(t > m) continue;
                    pr[t] -= 1;
                    t += x[k];
                }
                start[k] = i;
            }
            else{
                ll sum = x[k] + y[k];
                ++cnt[sum][(i + x[k]) % sum];
                --cnt[sum][i % sum];
                start[k] = i;
            }
        }
        else{
            if(x[k] + y[k] >= T){
                ll t = start[k] + x[k];
                while(t <= m){
                    pr[t] -= 1;
                    t += y[k];
                    if(t > m) continue;
                    pr[t] += 1;
                    t += x[k];
                }
                if((i - start[k]) % (x[k] + y[k]) >= x[k]) --ans;
            }
            else{
                ll sum = x[k] + y[k];
                if((i - start[k]) % sum >= x[k]) --ans;
                --cnt[sum][(start[k] + x[k]) % sum];
                ++cnt[sum][start[k] % sum];
            }
        }

        cout << ans << "\n";
    }
}