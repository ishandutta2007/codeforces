#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        ll w;
        cin>>n>>w;
        multiset<ll> s;
        for (int i=1;i<=n;i++) {
            ll l;
            cin>>l;
            s.insert(l);
        }
        int ans=1, cur=0;
        while (s.size()){
            auto it = s.upper_bound(w-cur);
            if (it==s.begin()) {
                cur=0;
                ans++;
            } else {
                it--;
                ll x = *it;
                cur += x;
                s.erase(it);
            }
        }
        cout<<ans<<endl;
    }
}