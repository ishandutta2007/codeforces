#include<bits/stdc++.h>
#define ll long long
using namespace std;
main(){
    ll n;
    ll X=0,Y=0;
    cin >> n;
    set<pair<ll,ll> > s;
    for(int i = 1; i <= n; i++){
        int a,b;
        scanf("%d %d", &a,&b);
        X+=a, Y+=b;
        s.insert({n*a, n*b});
    }
    for(auto it = s.begin(); it!=s.end(); it++){
        ll a = it->first, b = it->second;
        pair<ll,ll> op = {2*X - a, 2*Y-b};
        if(s.find(op) == s.end()){
            cout<<"NO"<<endl;
            return 0;
        }

    }
    cout<<"YES"<<endl;
}