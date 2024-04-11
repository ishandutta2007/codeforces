#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E17;

#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
//void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
///////////////////////////////////////


bool anspro(){
    ll n;cin>>n;
    ll a[n];
    rep(i,0,n-1){
        cin>>a[i];
        a[i]--;
        if(a[i]==-2){
            a[i]=i+1;
        }
    }
    
    vector<ll>chi[n+1];
    rep(i,0,n-1){
        if(a[i]!=-2)chi[a[i]].pb(i);
        else{
            chi[i+1].pb(i);
        }
    }
    
    
    ll h[n+1];
    h[n]=n;
    ll now=n-1;
    for(ll i=n;i>=1;i--){
        for(auto x:chi[i]){
            h[x]=now;
            now--;
        }
    }
    stack<ll>s;
    rep(i,0,n-1){
        if(s.size()==0){
            s.push(a[i]);
            continue;
        }
        ll t=s.top();
        if(t==i){
            s.pop();
        }
        if(s.size()==0){
            s.push(a[i]);
            continue;
        }
        
        t=s.top();
        if(a[i]>t){
            cout<<-1<<endl;return 0;
        }else if(a[i]<t){
            s.push(a[i]);
        }
    }
    
   /*
    vector<l_l>v;
    rep(i,0,n-1){
        v.pb(l_l(h[i],i));
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    set<ll>s;
    s.insert(n);
    for(auto x:v){
        if(a[x.second]==-2){
            s.insert(x.second);
        }else{
            ll k=*upper_bound(s.begin(),s.end(),x.second);
            if(a[x.second]!=k){
                cout<<-1<<endl;
                return 0;
            }
            s.insert(x.second);
        }
    }*/
    
    
    rep(i,0,n-1){
        cout<<h[i]+1<<" ";
    }
    cout<<endl;
    
    return 0;
}


int main(){fastio
    ll qq;cin>>qq;
    while(qq--){
        anspro();
    }
    return 0;
}