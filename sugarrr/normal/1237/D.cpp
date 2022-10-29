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
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
////////////////////////////
 
 
int main(){
    
    //inf=100;
    
    ll n;cin>>n;
    ll minv=inf,maxv=-inf;
    
    ll N=3*n;
    ll a[N];
    rep(i,0,n-1){
        cin>>a[i];
        Min(minv,a[i]);
        Max(maxv,a[i]);
        a[i]*=-1;
    }
    rep(i,0,N-1){
        a[i]=a[i%n];
    }
    if(minv*2>=maxv){
        rep(i,0,n-1){
            cout<<"-1 ";
        }cout<<endl;
        return 0;
    }
    ll b[N];rep(i,0,N-1)b[i]=inf;
    ll c[N];memset(c,-1,sizeof(c));
    ll depos=0;
    ll ans[N];rep(i,0,N-1)ans[i]=inf;
    rep(i,0,N-1){
        ll pos=lower_bound(b,b+N,a[i])-b;
        if(pos<0){
            continue;
        }
        b[pos]=a[i];
        c[pos]=i;
        
        if(b[depos]<a[i]*2){
            ll lb=lower_bound(b,b+N,a[i]*2)-b-1;
            ll lc=c[lb];
            depos=lb+1;
            while(lb>=0){
                if(b[lb]==-inf)break;
                b[lb]=-inf;
                Max(lc,c[lb]);
                lb--;
            }
            while(lc>=0){
                if(ans[lc]>i-lc)ans[lc]=i-lc;
                else break;
                lc--;
            }
        }
        /*
        cout<<i<<endl;
        rep(j,0,N-1)cout<<b[j]<<" ";cout<<endl;
        rep(j,0,N-1)cout<<c[j]<<" ";cout<<endl;
        rep(j,0,N-1)cout<<ans[j]<<" ";cout<<endl;
        cout<<endl;
         */
        
    }
    rep(i,0,n-1){
        rep(j,0,1){
            Min(ans[i],ans[i+j*n]);
        }
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    
    return 0;
}

/*
 10
 8 5 4 5 4
 7 8 9 7 1
 
 25
 854951 182889 717162 644763 747236
 884170 806535 506676 489450 531232
 468184 707349 821451 988886 777549
 156730 401143 255804 357356 683049
 269889 935183 377045 803800 288629 417134 695306
 */