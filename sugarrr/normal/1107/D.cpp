
#include <bits/stdc++.h>
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
ll inf=(ll)1E17;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
long double EPS=1E-8;
////////////////////////////////////////

#define MAX_N 1000000//
int par[MAX_N],dep[MAX_N];//deprank
//n//
void init(int n){
    for(int i=0;i<=n-1;i++){//0~n-1
        par[i]=i;
        dep[i]=0;
    }
}
//
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
//xy
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(dep[x]<dep[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(dep[x]==dep[y])dep[x]++;
    }
}
//xy
bool same(int x,int y){
    return find(x)==find(y);
}

//////////////////////////////////////

vector<ll> bun(ll n){
    vector<ll>v;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            v.pb(i);
            if(i*i!=n)v.pb(n/i);
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    return v;
}
struct aa{
    string s;ll pos;
};
bool comp(aa x,aa y){
    return x.s<y.s;
}

int main(){
    ll n;scanf("%lld",&n);
    char s[n][n/4+1];
    rep(i,0,n-1)scanf("%s",s[i]);
    vector<bool>vec[n];
    ll count=0;
    rep(i,0,n-1){
        rep(j,0,n/4-1){
            ll m;
            if('0'<=s[i][j]&&s[i][j]<='9')m=s[i][j]-'0';
            else m=s[i][j]-'A'+10;
            rep(k,0,3){
                vec[count].pb((m>>(3-k))&1);
            }
        }
        count++;
    }
    aa a[n];
    rep(i,0,n-1){
        aa a1;a1.pos=i;
        a1.s="";
        rep(j,0,n-1){
            if(vec[i][j])a1.s+='1';
            else a1.s+='0';
        }
        a[i]=a1;
    }
    sort(a,a+n,comp);
    init(n);
    rep(i,0,n-2){
        if(a[i].s==a[i+1].s){
            unite(a[i].pos,a[i+1].pos);
        }
    }vector<ll>v=bun(n);
    ll ans;
    for(auto x:v){
        bool flag=true;
        rep(i,0,n-2){
            if(i%x!=x-1&&!same(i,i+1))flag=false;
        }
        if(flag){
            ans=x;break;
        }
    }
    init(n);
    
    rep(i,0,n-1){
        rep(j,i+1,n-1){
            swap(vec[i][j],vec[j][i]);
        }
    }
    rep(i,0,n-1){
        aa a1;a1.pos=i;
        a1.s="";
        rep(j,0,n-1){
            if(vec[i][j])a1.s+='1';
            else a1.s+='0';
        }
        a[i]=a1;
    }
    sort(a,a+n,comp);
    rep(i,0,n-2){
        if(a[i].s==a[i+1].s){
            unite(a[i].pos,a[i+1].pos);
        }
    }
    for(auto x:v){
        bool flag=true;
        rep(i,0,n-2){
            if(i%x!=x-1&&!same(i,i+1))flag=false;
        }
        if(flag){
            cout<<min(ans,x)<<endl;return 0;
        }
    }
    
    
    
    cout<<1<<endl;
    return 0;
}