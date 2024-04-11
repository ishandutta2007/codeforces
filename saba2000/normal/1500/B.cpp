#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500009],b[500009], A[1000009],B[1000009],G[1000009];
ll pos[1000009];
ll n,m,k,g,d, n1, m1;
ll Cnt(ll L){
    ll S = 0;
    ll f = L / n1, rm = L % n1;
    for(ll i = 1; i <= g; i++){
        if(!A[i] || !B[i]) continue;
        if((A[i] - B[i]) % d) continue;
        S += f;
        if(G[i] < rm) S++;
    }
    return (ll)m*L - S;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
     d = __gcd(n, m);
    g = 2*max(n, m);
    n1 = n / d; m1 = m / d;
    for(ll i = 0; i < n; i++){
            cin>>a[i];
        A[a[i]] = i+1;
    }
    for(ll i = 0; i < m; i++){
        cin>>b[i];
        B[b[i]] = i+1;
    }
    for(ll i = 0; i < n1; i++){
        pos[i*m1 % n1] = i;
    }
    for(ll i = 1; i <= g; i++){
        G[i] = pos[(((A[i]-1)/d - (B[i]-1)/d) % n1 + n1)%n1];
    }
    ll lo = 1, hi = max(k, n*k/m+10);
    while(lo < hi){
        ll L = (lo + hi) / 2;
        ll S= Cnt(L);
        if(S >= k) hi = L;
        else lo = L + 1;
    }
    ll ans = m * (lo - 1), j =0;
     k -= Cnt(lo - 1);
    for(ll i = m*(lo-1) % n; k; i = (i + 1) % n){
        ans++;
        if(a[i] != b[j]) k--;
        j = (j + 1) % m;
        if(j == 0) break;
    }
    cout<<ans<<endl;


}