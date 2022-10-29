#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_int.hpp>
//typedef boost::multiprecision::cpp_int ll;
typedef long double dd;
//#define i_7 (ll)(1E9+7)
#define i_7 998244353
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

ll ask(ll a,ll b,ll c,ll d){
    if(a+b>c+d){
        swap(a,c);swap(b,d);
    }
    cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    fflush(stdout);
    ll res;cin>>res;return res;
}
#define N 100
ll n;
ll ans[N][N];
bool find(){
    for(ll i=1;i<=n;i+=2){
        for(ll j=1;j+4<=n;j+=2){
            if(ans[i][j]==1&&ans[i][j+4]==0){
                ll res=ask(i,j,i,j+3);
                if(res==1){
                    ans[i][j+1]=ans[i][j+2];
                    ans[i][j+3]=ans[i][j];
                    return 0;
                }
                res=ask(i,j+1,i,j+4);
                if(res==1){
                    ans[i][j+1]=ans[i][j+4];
                    ans[i][j+3]=ans[i][j+2];
                    return 0;
                }
                res=ask(i,j+1,i,j+3);
                if(ans[i][j+2]==1){
                    if(res==1){
                        ans[i][j+1]=0;
                        ans[i][j+3]=0;
                    }else{
                        ans[i][j+1]=1;
                        ans[i][j+3]=0;
                    }
                }else{
                    if(res==1){
                        ans[i][j+1]=1;
                        ans[i][j+3]=1;
                    }else{
                        ans[i][j+1]=1;
                        ans[i][j+3]=0;
                    }
                }
                return 0;
            }
        }
    }
    for(ll j=1;j<=n;j+=2){
        for(ll i=1;i+4<=n;i+=2){
            if(ans[i][j]==1&&ans[i][j+4]==0){
                ll res=ask(i,j,i+3,j);
                if(res==1){
                    ans[i+1][j]=ans[i+2][j];
                    ans[i+3][j]=ans[i][j];
                    return 0;
                }
                res=ask(i+1,j,i+4,j);
                if(res==1){
                    ans[i+1][j]=ans[i+4][j];
                    ans[i+3][j]=ans[i+2][j];
                    return 0;
                }
                res=ask(i+1,j,i+3,j);
                if(ans[i+2][j]==1){
                    if(res==1){
                        ans[i+1][j]=0;
                        ans[i+3][j]=0;
                    }else{
                        ans[i+1][j]=1;
                        ans[i+3][j]=0;
                    }
                }else{
                    if(res==1){
                        ans[i+1][j]=1;
                        ans[i+3][j]=1;
                    }else{
                        ans[i+1][j]=1;
                        ans[i+3][j]=0;
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}

void extend(ll sx,ll sy){
    for(ll j=sy;j+2<=n;j+=2){
        if(ans[sx][j+2]!=-1)continue;
        ll res=ask(sx,j,sx,j+2);
        if(res==1){
            ans[sx][j+2]=ans[sx][j];
        }else{
            ans[sx][j+2]=1-ans[sx][j];
        }
    }
    for(ll j=sy;j-2>=1;j-=2){
        if(ans[sx][j-2]!=-1)continue;
        ll res=ask(sx,j,sx,j-2);
        if(res==1){
            ans[sx][j-2]=ans[sx][j];
        }else{
            ans[sx][j-2]=1-ans[sx][j];
        }
    }
    rep(j,1,n){
        for(ll i=sx;i+2<=n;i+=2){
            if(ans[i+2][j]!=-1)continue;
            ll res=ask(i,j,i+2,j);
            if(res==1){
                ans[i+2][j]=ans[i][j];
            }else{
                ans[i+2][j]=1-ans[i][j];
            }
        }
        for(ll i=sx;i-2>=1;i-=2){
            if(ans[i-2][j]!=-1)continue;
            ll res=ask(i,j,i-2,j);
            if(res==1)ans[i-2][j]=ans[i][j];
            else ans[i-2][j]=1-ans[i][j];
        }
    }
}
bool findmini(){
    if(ans[2][2]!=ans[1][3]){
        ll res=ask(1,1,2,3);
        if(res==1)ans[2][3]=ans[1][1];
        else ans[2][3]=1-ans[1][1];
        return 0;
    }
    if(ans[2][2]!=ans[3][1]){
        ll res=ask(1,1,3,2);
        if(res==1)ans[3][2]=ans[1][1];
        else ans[3][2]=1-ans[1][1];
        return 0;
    }
    ll res=ask(1,1,2,3);
    if(res==1){
        ans[2][3]=ans[1][1];
        return 0;
    }
    res=ask(1,2,3,3);
    if(res==1){
        ans[1][2]=0;
        return 0;
    }
    if(ans[2][2]==1){
        ans[2][3]=0;
    }else{
        ans[1][2]=1;
    }
    return 0;
}
int main(){fastio
    cin>>n;
    memset(ans,-1,sizeof(ans));
    ans[1][1]=1;ans[n][n]=0;
    ans[2][2]=ask(1,1,2,2);
    for(ll j=1;j<=n-2;j+=2){
        ll res=ask(1,j,1,j+2);
        if(res==1)ans[1][j+2]=ans[1][j];
        else ans[1][j+2]=1-ans[1][j];
    }
    for(ll j=2;j<=n-2;j+=2){
        ll res=ask(2,j,2,j+2);
        if(res==1)ans[2][j+2]=ans[2][j];
        else ans[2][j+2]=1-ans[2][j];
    }
    
    rep(i,1,n-2){
        ll s=-1;
        if(i%2==1){
            s=1;
        }else{
            s=2;
        }
        for(ll j=s;j<=n;j+=2){
            if(i==n-2&&j==n)continue;
            ll res=ask(i,j,i+2,j);
            if(res==1)ans[i+2][j]=ans[i][j];
            else ans[i+2][j]=1-ans[i][j];
        }
    }
    if(n==3)findmini();
    else find();
    
    ll sx,sy;
    rep(i,1,n){
        rep(j,1,n){
            if((i+j)%2==0)continue;
            if(ans[i][j]!=-1){
                sx=i;sy=j;
                break;
            }
        }
    }
    extend(sx,sy);
    bool flag=false;
    for(ll dx=-1;dx<=1;dx+=2){
        ll dy=dx;
            ll nx=dx+sx;
            ll ny=dy+sy;
            if(1<=nx&&nx<=n&&1<=ny&&ny<=n){
                ll res=ask(sx,sy,nx,ny);
                if(res==1)ans[nx][ny]=ans[sx][sy];
                else ans[nx][ny]=1-ans[sx][sy];
                extend(nx,ny);
                flag=true;
            }
            if(flag)break;
        
        if(flag)break;
    }
    cout<<"!"<<endl;
    rep(i,1,n){
        rep(j,1,n){
            cout<<ans[i][j];
        }cout<<endl;
    }
    return 0;
}