#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200009], d[200009], G[200009][19], LG[200009];
ll n;
ll Q(ll l, ll r){
    ll d = LG[r - l + 1];
    return __gcd(G[l][d], G[r - (1<<d) + 1][d]);
}
main(){
    ios_base::sync_with_stdio(false);
    srand(time(0));
    cin.tie(0);
    ll t;
    cin >>t;
    while(t--){
        ll ans = 0;
        cin >> n;
        for(ll i = 1; i <= n; i++){
            cin >> a[i];
            LG[i] = LG[i-1];
            if((1<<(LG[i]+1))<=i) LG[i]++;
        }
        n--;

        for(ll i = 1; i <= n; i++){
            d[i] = abs(a[i + 1] - a[i]);
        }

        for(ll i = 0; i < 19; i++){
            for(ll j = 1; j + (1<<i) - 1 <= n; j++){
                if(i == 0) G[j][i] = d[j];
                else G[j][i] = __gcd(G[j][i-1], G[j+(1<<(i-1))][i-1]);
            }
        }
        ll j = 1;
        for(ll i = 1; i <= n; i++){

            while(j <= n && (j < i || Q(i, j) > 1)) j++;
            ans = max(ans, j - i);
        }


        cout << ans + 1<< endl;
    }

}