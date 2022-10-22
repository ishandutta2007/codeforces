#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,q,c,res,ans,s[N],t[N],BIT[N],fen[N];
vector<int> g[N],G[N];

void update(int x,int val) { ++x;  while(x<=N)  {  BIT[x]+=val;  x+=(x&-x);  } }
int query(int x) {  ++x;  int res=0;  while(x>0)  {  res+=BIT[x];  x-=(x&-x);  } return res; }

void update1(int x,int val) { ++x;  while(x<=N)  {  fen[x]+=val;  x+=(x&-x);  } }
int query1(int x) {  ++x;  int res=0;  while(x>0)  {  res+=fen[x];  x-=(x&-x);  } return res; }

void dfs1(int x,int par){
    s[x]=++c;
    f(i,0,G[x].size())
        if(G[x][i]!=par)
            dfs1(G[x][i],x);
    t[x]=c+1;
}
void dfs2(int x,int par){
    int p=query(s[x]),e=0;
//    f(i,1,n+1) cout<<query(i)<<" ";
  //  cout<<endl;
    if(query1(s[x]-1)==query1(t[x]-1)){
       if(p){
           update(s[p],-p);
           update(t[p],p);
           update(s[x],x);
           update(t[x],-x);
       }
       else{
           res++,e=-1;
           update(s[x],x);
           update(t[x],-x);
       }
    }
    update1(s[x],1);
    maxm(ans,res);
//    cout<<x<<" "<<res<<endl;
    f(i,0,g[x].size())
        if(g[x][i]!=par)
            dfs2(g[x][i],x);
    update1(s[x],-1);
    if(query1(s[x]-1)==query1(t[x]-1)){
       if(p){
           update(s[p],p);
           update(t[p],-p);
           update(s[x],-x);
           update(t[x],x);
       }
       else{
           res+=e;
           update(s[x],-x);
           update(t[x],x);
       }
    }
}

int main(){
    cin>>q;
    while(q--){
        cin>>n;
        f(i,1,n+1) g[i].clear(),G[i].clear();
        f(i,2,n+1){
            int u;
            gett(u);
            g[u].pb(i);
        }
        f(i,2,n+1){
            int u;
            gett(u);
            G[u].pb(i);
        }
        res=ans=0;
        dfs1(1,0);
        dfs2(1,0);
        cout<<ans<<endl;
    }
}