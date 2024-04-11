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
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////////////////////////////


bool comp(l_l a,l_l b){
    return a.first<b.first;
}
ll calbor(ll n){
    ll q=(ll)sqrt(n);
    ll u=0;
    if(q*q==n)u=q;
    else u=q+1;
    //u
    ll res=(n+u-1)/u;
    return res;
}
ll calbor2(ll n){
    ll res=1;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0)res=i;
    }
    return res;
}

int main(){fastio
    ll n;cin>>n;
    ll a[n];rep(i,0,n-1)cin>>a[i];
    sort(a,a+n);
    vector<l_l>b;
    rep(i,0,n-1){
        ll c=1;
        while(i<=n-2&&a[i]==a[i+1]){
            c++;
            i++;
        }
        b.pb(l_l(c,a[i]));
    }
    //for(auto x:b)cout<<x.first<<" "<<x.second<<endl;
    sort(b.begin(),b.end(),comp);
    //for(auto x:b)cout<<x.first<<" "<<x.second<<endl;
    ll bs=b.size();
    ll sum[bs+1];sum[0]=0;
    rep(i,0,bs-1)sum[i+1]=sum[i]+b[i].first;
    vector<ll>c;
    c.pb(0);
    rep(i,0,bs-1)c.pb(b[i].first);
    /*
    ll sok=1,sng=500000;
    //rep(i,0,bs)cout<<sum[i]<<" ";cout<<endl;
    //for(auto x:c)cout<<x<<" ";cout<<endl;
    //cout<<c.size()<<endl;
    /*
    while(abs(sok-sng)>1){
        ll smid=(sok+sng)/2;
        ll border=calbor(smid);
        ll pos=lower_bound(c.begin(),c.end(),border)-c.begin();
        ll su=sum[pos-1]+(bs-pos+1)*border;
        if(smid<=su){
            sok=smid;
        }else{
            sng=smid;
        }
    }
     */
    ll init=(ll)sqrt(n);
    ll maxans=0,malen=0;
    rep(i,1,init){
        ll pos=lower_bound(c.begin(),c.end(),i)-c.begin();
        ll su=sum[pos-1]+(bs-pos+1)*i;
        su=su/i*i;
        if(i*i<=su){
            if(su>maxans){
                maxans=su;
                malen=i;
            }
        }
    }
    ll sho=malen;
    ll pos=lower_bound(c.begin(),c.end(),sho)-c.begin();
    ll su=sum[pos-1]+(bs-pos+1)*sho;
    ll lon=su/sho;
    
    ll ans[sho][lon];memset(ans,0,sizeof(ans));
    l_l po=l_l(0,0);ll rownum=1;
    
    
    cout<<sho*lon<<endl;
    cout<<sho<<" "<<lon<<endl;
    for(ll i=bs-1;i>=0;i--){
        rep(count,1,min(sho,b[i].first)){
            if(ans[po.first][po.second]!=0){
                rep(xx,0,sho-1){
                    rep(yy,0,lon-1){
                        cout<<ans[xx][yy]<<" ";
                    }cout<<endl;
                }
                return 0;
            }
            ans[po.first][po.second]=b[i].second;
            if(po.first==sho-1){
                po.first=0;
                po.second=rownum;
                rownum++;
            }else{
                po.first=(po.first+1)%sho;
                po.second=(po.second+1)%lon;
            }
        }
    }
    
    
    
    rep(xx,0,sho-1){
        rep(yy,0,lon-1){
            cout<<ans[xx][yy]<<" ";
        }cout<<endl;
    }
    
    return 0;
}