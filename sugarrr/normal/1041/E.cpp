#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
////////////////////////////////////////


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    
    ll n;cin>>n;
    vector<ll>v;
    rep(i,1,n-1){
        ll b,c;cin>>b>>c;
        if(b>c)swap(b,c);
        if(c!=n){
            cout<<"NO"<<endl;
            return 0;
        }
        if(b==n){
            cout<<"NO"<<endl;
            return 0;
        }
        v.pb(b);
    }
    sort(v.begin(),v.end());
    ll a[n];
    rep(i,0,n-2){
        a[i+1]=v[i];
    }
    rep(i,1,n-1){
        if(a[i]<i){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    vector<l_l>ans;
    bool used[n];memset(used,false,sizeof(used));
    ll s=1,t=1;
    while(s<=n-1&&t<=n-1){
        while(t<=n-2&&a[t+1]==a[s]){
            t++;
        }
        if(s==t){
            ans.pb(l_l(a[s],n));
            used[a[s]]=true;
        }else{
            vector<int>v;
            int pos=1;
            
            ll c=t-s;
            while(c>0){
                while(pos<=n-2&&used[pos])pos++;
                v.pb(pos);
                used[pos]=true;
                c--;
            }
            int vsize=v.size();
            ans.pb(l_l(v[0],n));
            used[a[s]]=true;
            ans.pb(l_l(v[vsize-1],a[s]));
            if(vsize>=2){
                rep(i,0,vsize-2){
                    ans.pb(l_l(v[i],v[i+1]));
                }
            }
            
            
        }
        
        s=t+1;
        t=s;
    }
    cout<<"YES"<<endl;
    for(auto x:ans){
        cout<<x.first<<" "<<x.second<<endl;
    }
    
    
    return 0;
}