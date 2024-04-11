#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_ll.hpp>
//typedef boost::multiprecision::cpp_ll ll;
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
ll inf=(ll)1E18;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define endl "\n"
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

struct Node{
    ll first;
    ll second;
    ll flag;
};

bool comp1(Node x,Node y){
    if(x.first!=y.first){
        return x.first<y.first;
    }else{
        return x.second<y.second;
    }
}
bool comp(Node x,Node y){
    if(x.first!=y.first){
        return x.first<y.first;
    }else{
        return x.second>y.second;
    }
}
ll func(ll x,ll y,ll z){
    return (x-y)*(x-y)+(z-y)*(z-y)+(x-z)*(x-z);
}

int main(){fastio
    ll t;cin>>t;
    rep(i,0,t-1){
        ll n[3];rep(i,0,2)cin>>n[i];
        vector<ll> a[3];
        ll x;
        vector<Node> all;
        rep(i,0,2){
            rep(j,0,n[i]-1){
                cin>>x;
                a[i].pb(x);
            }
        }
        rep(i,0,2){
            sort(a[i].begin(),a[i].end());
        }
        vector<ll> b[3];
        rep(i,0,2){
            rep(j,0,a[i].size()-1){
                if(j==0){
                    b[i].pb(a[i][j]);
                }else{
                    if(a[i][j]!=a[i][j-1]){
                        b[i].pb(a[i][j]);
                    }
                }
            }
        }
        rep(i,0,2){
            rep(j,0,b[i].size()-1){
                Node node;
                node.first=b[i][j];
                node.second=i;
                node.flag=0;
                all.pb(node);
            }
        }
        sort(all.begin(),all.end(),comp1);
        ll dp[2][3][(ll)all.size()];
        rep(i,0,(ll)all.size()-1){
            if(i==0){
                rep(j,0,2){
                    if(j==all[i].second){
                        dp[0][j][i]=all[i].first;
                    }else{
                        dp[0][j][i]=-inf;
                    }
                }
                all[i].flag=i;
            }else{
                rep(j,0,2){
                    if(j==all[i].second){
                        dp[0][j][i]=all[i].first;
                    }else{
                        dp[0][j][i]=dp[0][j][i-1];
                    }
                }
                all[i].flag=i;
            }
        }
        sort(all.begin(),all.end(),comp);
        unordered_map<ll,ll> mp;
        for(ll i=(ll)all.size()-1;i>=0;i--){
            if(i==(ll)all.size()-1){
                rep(j,0,2){
                    if(j==all[i].second){
                        dp[1][j][i]=all[i].first;
                    }else{
                        dp[1][j][i]=inf;
                    }
                }
                mp[all[i].flag]=i;
            }else{
                rep(j,0,2){
                    if(j==all[i].second){
                        dp[1][j][i]=all[i].first;
                    }else{
                        dp[1][j][i]=dp[1][j][i+1];
                    }
                }
                mp[all[i].flag]=i;
            }
        }
        ll ans=2*inf-1;
        rep(i,0,(ll)all.size()-1){
            ll sx,sy,bx,by,sz,bz;
            sx=dp[0][0][i];
            sy=dp[0][1][i];
            sz=dp[0][2][i];
            bx=dp[1][0][mp[i]];
            by=dp[1][1][mp[i]];
            bz=dp[1][2][mp[i]];
            if(all[i].second==2){
                ll z=all[i].first;
                if(-inf<bx && bx<inf && -inf<sy && sy<inf){
                    ans=min(ans,func(bx,sy,z));
                }
                if(-inf<by && by<inf && -inf<sx && sx<inf){
                    ans=min(ans,func(sx,by,z));
                }
            }else if(all[i].second==1){
                ll y=all[i].first;
                if(-inf<bx && bx<inf && -inf<sz && sz<inf){
                    ans=min(ans,func(bx,sz,y));
                }
                if(-inf<bz && bz<inf && -inf<sx && sx<inf){
                    ans=min(ans,func(sx,bz,y));
                }
            }else{
                ll x=all[i].first;
                if(-inf<by && by<inf && -inf<sz && sz<inf){
                    ans=min(ans,func(by,sz,x));
                }
                if(-inf<bz && bz<inf && -inf<sy && sy<inf){
                    ans=min(ans,func(sy,bz,x));
                }
            }
        }
        
        cout<<ans<<endl;
        
        
    }
    
    return 0;
}