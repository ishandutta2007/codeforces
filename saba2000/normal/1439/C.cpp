#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long sum[300009];
const ll B = 101;
ll val[300009], tv[300009];
ll f[300009], tf[300009],no[300009];
ll get(ll i){
    if(tf[i] < tv[no[i]])
        return val[no[i]];
    else return f[i];
}

main(){
    ll n, q;
    scanf("%lld %lld", &n, &q);
    for(ll i = 1; i <=n ; i++){
        scanf("%lld", &f[i]);
        tf[i] = 1;
        no[i] = (i-1)/B;
        sum[no[i]] += f[i];
    }
    for(ll T = 2; T <= q+1; T++){
        ll t;
        scanf("%lld", &t);
        if(t == 1){
            ll x, y;
            scanf("%lld %lld", &x, &y);
            for(ll i = no[x] * B + 1; i <= x; i++){
                ll u = get(i);
                if(y > u){
                    sum[no[x]] += (y - u);
                    f[i] = y;
                    tf[i] = T;
                }
            }
            for(ll i = no[x] - 1; i >= 0; i--){
                if(get((i+1)*B) >= y) break;
                if(get(i*B+1) < y){
                    val[i] = y;
                    sum[i] = (long long)y*B;
                    tv[i] = T;
                    continue;
                }
                for(ll j = i * B + 1; j <= (i+1)*B; j++){
                    ll u = get(j);
                    if(y > u){
                        sum[i] += (y - u);
                        f[j] = y;
                        tf[j] = T;
                    }
                }
                break;
            }
        }
        else{
            ll x, y;
            scanf("%lld %lld", &x, &y);
            ll ans = 0;
            for(ll i = x; i <= min(n, (no[x] + 1)*B); i++){
                if(get(i) <= y){
                    ans++;
                    y -= get(i);
                }
            }
            for(ll i = no[x] + 1; i * B + 1 <= n; i++){
                if(sum[i] <= y){
                    if((i+1)*B < n) ans += B;
                    else ans += n - i*B;
                    y -= sum[i];
                }
                else if(get(min(n,(i+1)*B)) <= y){

                    for(ll j = i*B+1; j <= min(n, (i + 1)*B); j++){
                        if(get(j) <= y){
                            ans++;
                            y -= get(j);
                        }
                    }
                }
            }
            printf("%lld\n", ans);
        }
    }

}
/*10 6
10 10 10 6 6 5 5 5 3 1
2 3 50
2 4 10
1 7 7
2 2 36
1 4 11
2 2 17

*/