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


void c1(ll a,ll b){
    cout<<1<<" "<<a<<" "<<b<<endl;
}
void c2(ll a){
    cout<<2<<" "<<a<<endl;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    
    ll n;cin>>n;
    ll a[n+1];rep(i,1,n)cin>>a[i];
    vector<ll> zero;
    vector<ll>pos,neg;
    rep(i,1,n){
        if(a[i]==0){
            zero.pb(i);
        }else if(a[i]>0){
            pos.pb(i);
        }else{
            neg.pb(i);
        }
    }
    
    int sz=zero.size();
    int sp=pos.size();
    int sn=neg.size();
    
    ll minpos=0;
    if(sn>=1){
        minpos=neg[0];
        rep(i,2,n){
            if(a[i]<0&&abs(a[i])<abs(a[minpos])){
                minpos=i;
            }
        }
    }
    
    if(sz==n){
        rep(i,1,n-1){
            c1(i,i+1);
        }
    }else if(sz==n-1){
        if(sp==1){
            rep(i,0,sz-2){
                c1(zero[i],zero[i+1]);
            }
            c2(zero[sz-1]);
        }else{
            c2(neg[0]);
            rep(i,0,sz-2){
                c1(zero[i],zero[i+1]);
            }
        }
    }else if(sz==0){
        if(sn%2==0){
            rep(i,1,n-1){
                c1(i,i+1);
            }
        }else{
            c2(minpos);
            vector<ll>v;
            rep(i,1,n){
                if(i!=minpos)v.pb(i);
            }
            ll vs=v.size();
            rep(i,0,vs-2){
                c1(v[i],v[i+1]);
            }
        }
    }else{
        if(sn%2==0){
            rep(i,0,sz-2){
                c1(zero[i],zero[i+1]);
            }
            vector<ll>v;
            for(auto x:pos)v.pb(x);
            for(auto x:neg)v.pb(x);
            ll sk=v.size();
            if(sk>=1)c2(zero[sz-1]);
            rep(i,0,sk-2){
                c1(v[i],v[i+1]);
            }
            
        }else{
            rep(i,0,sz-2){
                c1(zero[i],zero[i+1]);
            }
            c1(minpos,zero[sz-1]);
            vector<ll>v;
            for(auto x:pos)v.pb(x);
            for(auto x:neg){
                if(x!=minpos)v.pb(x);
            }
            ll sk=v.size();
            if(sk>=1)c2(zero[sz-1]);
            rep(i,0,sk-2){
                c1(v[i],v[i+1]);
            }
        }
    }
    
    
    return 0;
}