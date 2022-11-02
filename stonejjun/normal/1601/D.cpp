#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double dl;
typedef pair<dl,dl> pdi;
typedef pair<ll,ll> pii;

#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back
#define all(x) (x).begin(), (x).end()
//cout<<fixed;
//cout.precision(12);


vector<pii> va;
vector<pii> vb;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t,T;
    ll i,j,k,l,m,n;
    cin>>n>>m;
    ll ans=0;
    for(i=1;i<=n;i++){
        ll a,b;
        cin>>a>>b;
        if(a<m) continue;
        if(a<b) vb.pb({b,a});
        else va.pb({a,b});
    }

    ll fl=0;
    ans=va.size();

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    for(i=0;i<vb.size();i++){
        while(fl<va.size()&&va[fl].ff<vb[i].ff){
            m=max(m,va[fl].ss);
            fl++;
        }
        if(m<=vb[i].ss){
            ans++;
            m=max(m,vb[i].ff);
        }
    }
    cout<<ans;

    

}