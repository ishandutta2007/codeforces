

#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> namespace mp = boost::multiprecision; //mp::cpp_int
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
//ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
void Add(ll * pos,ll val){*pos=*pos+val;}
//const long double EPS=1E-8;
////////////////////////////////////////



int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    
    ll n,k;cin>>n>>k;
    string s[n];rep(i,0,n-1)cin>>s[i];
    int dp[n][n];
    if(s[0][0]=='a')dp[0][0]=0;
    else dp[0][0]=1;
    rep(x,1,2*n-1){
        for(int j=0;j<=n-1;j++){
            int i=x-j;
            if(i<0||n-1<i)continue;
            if(i==0)dp[i][j]=dp[i][j-1];
            else if(j==0)dp[i][j]=dp[i-1][j];
            else dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
            if(s[i][j]!='a')dp[i][j]++;
        }
    }
    string ans;
    queue<i_i>q;
   // rep(i,0,n-1){rep(j,0,n-1){cout<<dp[i][j]<<" ";}cout<<endl;}
    int y=0;
    if(k>=1){
        rep(q,max(k-1,0),2*n-1){
            bool flag=false;
            rep(j,0,n-1){
                int i=q-j;
                if(i<0||n-1<i)continue;
                if(dp[i][j]<=k){
                    flag=true;break;
                }
            }
            if(!flag){
                break;
            }
            y=q;
        }
        if(k>=2*n-1)y=2*n-2;
        //cout<<y<<endl;
        rep(i,1,y+1)ans+='a';
        rep(j,0,n-1){
            int i=y-j;
            if(i<0||n-1<i)continue;
            if(dp[i][j]==k)q.push(i_i(i,j));
        }
    }else{
        ans+=s[0][0];
        q.push(i_i(0,0));
    }
    
    
    
    bool used[n][n];memset(used,false,sizeof(used));
    rep(x,y+1,2*n-2){
        char min='{';
        vector<i_i>v;
        while(!q.empty()){
            i_i t=q.front();q.pop();
            int ti=t.first,tj=t.second;
            if(ti+1<=n-1){
                if(!used[ti+1][tj]){
                    if(min>s[ti+1][tj]){
                        v.clear();
                        min=s[ti+1][tj];
                        v.pb(i_i(ti+1,tj));
                        used[ti+1][tj]=true;
                    }else if(min==s[ti+1][tj]){
                        v.pb(i_i(ti+1,tj));
                        used[ti+1][tj]=true;
                    }
                }
            }
            if(tj+1<=n-1){
                if(!used[ti][tj+1]){
                    if(min>s[ti][tj+1]){
                        v.clear();
                        min=s[ti][tj+1];
                        v.pb(i_i(ti,tj+1));
                        used[ti][tj+1]=true;
                    }else if(min==s[ti][tj+1]){
                        v.pb(i_i(ti,tj+1));
                        used[ti][tj+1]=true;
                    }
                }
            }
        }
        ans+=min;
        for(auto x:v)q.push(x);
    }
    cout<<ans<<endl;
    
    return 0;
}
//ios::sync_with_stdio(false);cin.tie(0);