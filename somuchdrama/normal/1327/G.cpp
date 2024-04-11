#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back
// #define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sqr(x) ((x)*(x))
struct init{init(){cin.tie(0);iostream::sync_with_stdio(0);cout<<fixed<<setprecision(10);cerr<<fixed<<setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}

const int N=1002,A=26;ll OO;
struct node{
    ll sum=0;//<--
    int32_t go[A]={0};
    int32_t ju[A]={0};
    int32_t up=1,kak=0,link=0;
    node(){}
}t[N];
int f=2;
void add(string s,int cost){
    int v=1;
    for(char c:s){
        c-='a';
        if(!t[v].go[c]){
            t[v].go[c]=f;
            t[f].up=v;
            t[f].kak=c;
            f++;
        }
        v=t[v].go[c];
    }
    t[v].sum+=cost;//<--
}
int link(int v);
int ju(int v,int x){
    if(!t[v].ju[x]){
        if(t[v].go[x])t[v].ju[x]=t[v].go[x];
        else if(v==1)t[v].ju[x]=1;
        else t[v].ju[x]=ju(link(v),x);
    }
    return t[v].ju[x];
}
int link(int v){
    if(!t[v].link){
        if(v==1||t[v].up==1)t[v].link=1;
        else t[v].link=ju(link(t[v].up),t[v].kak);
    }
    return t[v].link;
}
void zk(){//       
    vector<int>q(f-1);
    int l=0,r=0;
    q[r++]=1;
    while(l<r){
        int v=q[l++];
        if(t[v].up==1)t[v].link=1;
        else t[v].link=t[t[t[v].up].link].ju[t[v].kak];
        forn(x,A){
            if(t[v].go[x])t[v].ju[x]=t[v].go[x];
            else if(v==1)t[v].ju[x]=1;
            else t[v].ju[x]=t[t[v].link].ju[x];
        }
        t[v].sum+=t[t[v].link].sum;//<--
        forn(x,A)if(t[v].go[x])q[r++]=t[v].go[x];
    }
}
ll dp[N][1<<14],tdp[N][1<<14],g[N];
int w[N];
vector<int> ma[15];
int32_t main(){
    int n;
    cin>>n;
    forn(i,n){
        string t;
        int c;
        cin>>t>>c;
        add(t,c);
    }
    zk();
    string s;
    cin>>s;
    int m=14;
    forn(i,1<<m){
        ma[__builtin_popcount(i)].pb(i);
    }
    memset(dp,128,sizeof dp);
    memset(tdp,128,sizeof tdp);
    dp[1][0]=0;
    for(int i=1;i<f;++i){
        w[i]=i;
        g[i]=0;
    }
    int z=0;
    for(char c:s){
        if(c=='?'){
            for(int i=1;i<f;++i){
                int to=w[i];
                for(int mask:ma[z]){
                    upx(tdp[to][mask],dp[i][mask]+g[i]);
                }
            }
            for(int i=1;i<f;++i){
                forn(j,m){
                    int to=ju(i,j);
                    ll ad=t[to].sum;
                    for(int mask:ma[z]){
                        if(mask>>j&1)continue;
                        int tom=mask|(1<<j);
                        upx(dp[to][tom],tdp[i][mask]+ad);
                    }
                }
            }
            for(int i=1;i<f;++i){
                w[i]=i;
                g[i]=0;
            }
            z++;
        }else{
            for(int i=1;i<f;++i){
                w[i]=ju(w[i],c-'a');
                g[i]+=t[w[i]].sum;
            }
        }
    }
    for(int i=1;i<f;++i){
        int to=w[i];
        for(int mask:ma[z]){
            upx(tdp[to][mask],dp[i][mask]+g[i]);
        }
    }
    ll ans=dp[0][0];
    for(int i=1;i<f;++i){
        for(int mask:ma[z]){
            upx(ans,tdp[i][mask]);
        }
    }
    cout<<ans<<'\n';
    return 0;
}