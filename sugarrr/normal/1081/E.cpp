
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
ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll * pos,ll val){*pos=max(*pos,val);}//Max(&dp[i][j],dp[i-1][j]);
void Min(ll * pos,ll val){*pos=min(*pos,val);}
void Add(ll * pos,ll val){*pos=mod(*pos+val);}
const long double EPS=1E-8;
////////////////////////////////////////
#define MAX_N (ll)3E5///
vector<int>prime;
bool is_prime[MAX_N+1];
void precal(){
    rep(i,0,MAX_N)is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    rep(i,2,MAX_N){
        if(is_prime[i]){
            prime.pb(i);
            for(int j=2*i;j<=MAX_N;j+=i)is_prime[j]=false;
        }
    }
}
vector<i_i>v;
vector<ll>q;

void dfs(ll pos,ll now){
    if(pos==v.size()){
        q.pb(now);
        return;
    }
    rep(i,0,v[pos].second){
        dfs(pos+1,now);
        now*=v[pos].first;
    }
}

vector<ll> fact(ll n){//2<=n<=MAX_N^2
    v.clear();
    q.clear();

    for(int p:prime){
        if(p*p>n)break;
        int c=0;
        while(n%p==0){
            n/=p;
            c++;
        }
        if(c)v.pb(i_i(p,c));//pc
    }
    if(n!=1){
        int vsize=v.size();
        if(vsize>=1&&v[vsize-1].first==n)v[vsize-1].second++;
        else v.pb(i_i(n,1));
    }
    dfs(0,1);
    return q;
}
/////////////////////////////////////////////////////


int main(){
    precal();
    

    ll n;cin>>n;
    ll m=n/2;ll a[m];
    rep(i,0,m-1)cin>>a[i];

    ll p=0;
    ll ans[n];
    rep(i,0,m-1){
        ll ok=-1;
        vector<ll>res=fact(a[i]);
        for(auto j:res){
            if(j*j<=a[i]&&a[i]%j==0){
                ll k=a[i]/j;
                if((j+k)%2==0&&(k-j)/2>p){
                    if(ok<j)ok=j;
                }
            }
        }
        if(ok==-1){
            cout<<"No"<<endl;
            return 0;
        }
        ll k=a[i]/ok;
        ans[i*2]=(k-ok)/2;
        ans[i*2+1]=(k+ok)/2;
        p=(ok+k)/2;
    }

    //rep(i,0,n-1)cout<<ans[i]<<" ";cout<<endl;
   
    ll q[n];
    q[0]=ans[0]*ans[0];
    rep(i,1,n-1){
        q[i]=ans[i]*ans[i]-ans[i-1]*ans[i-1];
        if(q[i]<=0||q[i]>10000000000000){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    rep(i,0,n-1)cout<<q[i]<<" ";
    
    return 0;
}