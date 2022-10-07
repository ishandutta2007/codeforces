#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll A[100009],B[100009],C[100009];
ll f(ll a, ll b, ll c){
    return a*a+b*b+c*c-a*b-b*c-c*a;
}
void solve(){
    ll a,b,c;
    cin >> a >> b>> c;
    set<ll> aa,bb,cc;
    for(ll i= 1; i <= a; i++){
        scanf("%lld", &A[i]);
        aa.insert(A[i]);
    }
    for(ll i = 1; i <= b; i++){
        scanf("%lld", &B[i]);
        bb.insert(B[i]);
    }
    for(ll i = 1; i <= c; i++){
        scanf("%lld", &C[i]);
        cc.insert(C[i]);
    }
    ll ans = f(A[1],B[1],C[1]);

    for(ll i =1; i <= a; i++){
        auto itb = bb.lower_bound(A[i]);
        if(itb == bb.end()) continue;
        auto itc = cc.lower_bound(A[i]+1);
        if(itc == cc.begin()) continue;
        itc--;
        ans = min(ans, f(*itb,*itc, A[i]));

    }
    for(ll i =1; i <= a; i++){
        auto itb = bb.lower_bound(A[i]+1);
        if(itb == bb.begin()) continue;
        auto itc = cc.lower_bound(A[i]);
        if(itc == cc.end()) continue;
        itb--;
        ans = min(ans, f(*itb,*itc, A[i]));

    }


    for(ll i =1; i <= b; i++){
        auto ita = aa.lower_bound(B[i]);
        if(ita == aa.end()) continue;
        auto itc = cc.lower_bound(B[i]+1);
        if(itc == cc.begin()) continue;
        itc--;
        ans = min(ans, f(*ita,*itc, B[i]));

    }
    for(ll i =1; i <= b; i++){
        auto ita = aa.lower_bound(B[i]+1);
        if(ita == aa.begin()) continue;
        auto itc = cc.lower_bound(B[i]);
        if(itc == cc.end()) continue;
        ita--;
        ans = min(ans, f(*ita,*itc, B[i]));

    }
    for(ll i =1; i <= c; i++){
        auto itb = bb.lower_bound(C[i]);
        if(itb == bb.end()) continue;
        auto ita = aa.lower_bound(C[i]+1);
        if(ita == aa.begin()) continue;
        ita--;
        ans = min(ans, f(*itb,*ita, C[i]));

    }
    for(ll i =1; i <= c; i++){
        auto itb = bb.lower_bound(C[i]+1);
        if(itb == bb.begin()) continue;
        auto ita = aa.lower_bound(C[i]);
        if(ita == aa.end()) continue;
        itb--;
        ans = min(ans, f(*itb,*ita, C[i]));

    }
    cout<<2*ans<<endl;
}

main(){
   ll t;
   cin>>t;
   while(t--){
        solve();
   }

}