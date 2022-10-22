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

const int N=2e5+99;

int n,m,q,c,mark[N];
ll l[N],gcd[N];
vector<pair<int,int> > g[N];
vector<int> v,gb[N];

void dfs1(int u){
    mark[u]=1;
    f(i,0,gb[u].size())
        if(!mark[gb[u][i]])
            dfs1(gb[u][i]);
    v.pb(u);
}
void dfs2(int u){
    mark[u]=c;
 //   cout<<u<<" "<<c<<endl;
    f(i,0,g[u].size())
        if(!mark[g[u][i].F]){
            l[g[u][i].F]=l[u]+g[u][i].S;
            dfs2(g[u][i].F);
        }
}
void find_strongly(){
    f(i,1,n+1)
        if(!mark[i])
            dfs1(i);
    fill(mark,mark+N,0);
    f_(i,n-1,0)
        if(!mark[v[i]]){
            c++;
            dfs2(v[i]);
        }
}

int main(){
	cin>>n>>m;
	f(i,0,m){
	    int u,v,w;
	    Gett(u,v);
	    gett(w);
	    g[u].pb(mp(v,w));
	    gb[v].pb(u);
	}
	find_strongly();
	f(u,1,n+1)
	    f(i,0,g[u].size())
	        if(mark[u]==mark[g[u][i].F])
	            gcd[mark[u]]=__gcd(1ll*gcd[mark[u]],abs(l[u]+g[u][i].S-l[g[u][i].F]));
	cin>>q;
	f(i,0,q){
	    int u,g,mod,r;
	    Gett(u,r);
	    gett(mod);
	    r=(mod-r);
	    r=__gcd(r,mod);
	    if(r==mod) r=0;
	    g=__gcd(gcd[mark[u]],1ll*mod);
	    if(r!=0 && (g==mod || __gcd(g,r)!=g)) cout<<"NO"<<endl;
	    else cout<<"YES"<<endl;
	}
}