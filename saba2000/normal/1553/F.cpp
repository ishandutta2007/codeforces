#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long a[300009], f[300009],p[300009];
ll N = 3e5 + 1;
void upd(ll x, ll d){
    while(x <= N){
        f[x] +=d;
        x += (x & -x);
    }
}
ll cnt(ll x){
    if(x > N) x = N;
    ll ans = 0;
    while(x > 0){
        ans += f[x];
        x -= (x & -x);
    }
    return ans;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    //sum(a[i]) - a[i]*sum(a[j]/a[i])
    ll ans = 0, sum = 0;
    for(ll i = 1; i <= n; i++){
        ans += sum;
        sum += a[i];
        for(ll j = 0; a[i]*j <= N; j++){
            ans -= a[i] * j * (cnt((j+1)* a[i] - 1) - cnt(j*a[i]-1));
        }
        upd(a[i], 1);
        p[i] = ans;
    }

    sum = 0;
    for(ll i = 1; i <= N; i++)
        f[i] = 0;
    ans = 0;
   for(ll i = 1; i <= n; i++){
        ans += a[i] * (i - 1);

        ll j = 0;
        for (j = 0; j * j < a[i]; j++){
            ll L, R;
            if(j == 0) R = N; else R = a[i] / j;
            L = a[i] / (j + 1) + 1;
            ans -= j * (cnt(R) - cnt(L-1));
        }
        for(ll x = 1; a[i] / x >= j; x++){
            ans -= (a[i] / x) * (cnt(x) - cnt(x-1));
        }
        upd(a[i],a[i]);
        cout<<ans + p[i]<<" ";
    }
    cout<<endl;


}