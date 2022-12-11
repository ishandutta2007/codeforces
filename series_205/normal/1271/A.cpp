#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll a,b,c,d,e,f;

int main(){
    cin>>a>>b>>c>>d>>e>>f;
    ll x=min(b,c);
    ll ans=0;
    if(e>f){
        ans+=e*min(a,d);
        d-=min(a,d);
        ans+=f*min(x,d);
    }
    else{
        ans+=f*min(x,d);
        d-=min(x,d);
        ans+=e*min(a,d);
    }
    cout<<ans<<endl;
}