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
///////////////////////////////////////


void yes(){cout<<"YES"<<endl;}
void no(){cout<<"NO"<<endl;}

bool ansp(){
    ll h,w;cin>>h>>w;
    string s[h];rep(i,0,h-1)cin>>s[i];
    ll l[26],r[26],u[26],d[26];
    rep(i,0,25)l[i]=u[i]=inf;
    rep(i,0,25)r[i]=d[i]=-inf;
    
    ll last=-1;
    rep(i,0,h-1)rep(j,0,w-1){
        if(s[i][j]=='.')continue;
        ll k=s[i][j]-'a';
        Min(l[k],j);
        Min(u[k],i);
        Max(r[k],j);
        Max(d[k],i);
        Max(last,k+1);
    }
    
    rep(i,0,25){
        if(l[i]==inf)continue;
        if(l[i]!=r[i]&&u[i]!=d[i]){
            no();return 0;
        }
    }
    if(last==-1){
        yes();
        cout<<0<<endl;return 0;
    }
    ll sx=-1,sy=-1;
    rep(i,0,h-1)rep(j,0,w-1)if(s[i][j]=='a'+last-1){sx=i;sy=j;break;}
    ll ans[last][4];
    rep(i,0,last-1){
        if(l[i]==inf){
            ans[i][0]=ans[i][2]=sx;
            ans[i][1]=ans[i][3]=sy;
        }else{
            if(l[i]==r[i]){
                ans[i][0]=u[i];
                ans[i][1]=ans[i][3]=l[i];
                ans[i][2]=d[i];
            }else{
                ans[i][0]=ans[i][2]=u[i];
                ans[i][1]=l[i];
                ans[i][3]=r[i];
            }
        }
    }
    string man[h];
    rep(i,0,h-1){
        rep(j,0,w-1)man[i]+='.';
    }
    rep(i,0,last-1){
        if(ans[i][0]==ans[i][2]){
            rep(j,ans[i][1],ans[i][3]){
                man[ans[i][0]][j]=('a'+i);
            }
        }else{
            rep(j,ans[i][0],ans[i][2]){
                man[j][ans[i][1]]=('a'+i);
            }
        }
    }
    /*rep(i,0,h-1){
        rep(j,0,w-1){
            cout<<man[i][j];
        }cout<<endl;
    }cout<<endl;*/
    
    rep(i,0,h-1)rep(j,0,w-1){
        if(s[i][j]!=man[i][j]){
            no();return 0;
        }
    }
    yes();
    cout<<last<<endl;
    rep(i,0,last-1){
        rep(j,0,3){
            cout<<ans[i][j]+1<<" ";
        }cout<<endl;
    }
    return 0;
}

int main(){fastio
    
    ll qq;cin>>qq;
    while(qq--){
        ansp();
    }
    return 0;
}