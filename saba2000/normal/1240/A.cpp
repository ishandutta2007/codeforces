#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p[200009];
ll x,y,a,b,k,n;
bool check(ll lo){
    ll j =1;
    ll s = 0;
    for(ll i = 1; i <= lo; i++)
        if(i % a == 0 && i % b == 0 && j <= lo)
            s+= (x+y)*p[j], j++;
    for(ll i = 1; i <= lo ;i++)
        if(i % a == 0 && i%b != 0 && j <=lo)
            s+= x*p[j], j++;
    for(ll i = 1; i <= lo ; i++)
        if(i % a != 0 && i % b== 0 && j <= lo)
         s+=y*p[j],j++;
    return s>= k;
}
void solve(){
    cin >> n;
    for(ll i = 1; i <= n; i++)
        {int q ; scanf("%d",&q); p[i] = q /= 100;}
    cin>>x>>a>>y>>b>>k;
    if(x< y) swap(x,y),swap(a,b);
    sort(p+1,p+n+1);
    reverse(p+1,p+n+1);
    ll lo = 1, hi = n;
    if(!check(n)) {cout<<-1<<endl; return;}
    while(lo < hi){

        ll mid= (lo + hi)/2;
        if(check(mid)) hi = mid;
        else lo = mid+1;

    }
    cout<<lo<<endl;

}
main(){
    ll q;
    cin >> q;
    while(q--){
        solve();
    }


}