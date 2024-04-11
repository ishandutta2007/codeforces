#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define x0 fuckhel
#define y0 fuckoscar
#define x1 fucksub
#define y1 fuckzzy
#define st first
#define nd second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
typedef vector<int> vi;
const int N=2e5+5;
int T,n,m;
vi t[N];
vector<pair<int,int>>g[N];
map<pair<int,int>,int>ans;
void add(int x,int y,int z){
    if(x>y)swap(x,y);
    if(ans.find(mp(x,y))!=ans.end())return;
    ans[mp(x,y)]=z;
}
int c[N];
bool flag;
void dfs(int x){
    for(auto p:g[x])if(c[p.st]==0)c[p.st]=(p.nd==1?-c[x]:c[x]),dfs(p.st);
    else if(c[p.st]!=(p.nd==1?-c[x]:c[x])){flag=1;return;}
}
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&m);
        ans.clear();
        rep(i,n)t[i].clear(),g[i].clear();
        rep(i,n)c[i]=0;
        rep(i,n-1){
            int x,y,z;scanf("%d%d%d",&x,&y,&z);
            t[x].pb(y),t[y].pb(x);
            if(z!=-1){
                add(x,y,z);
                g[x].pb(mp(y,__builtin_parity(z)));
                g[y].pb(mp(x,__builtin_parity(z)));
            }
        }
        rep(i,m){
            int x,y,z;scanf("%d%d%d",&x,&y,&z);
            g[x].pb(mp(y,z));
            g[y].pb(mp(x,z));
        }
        flag=0;
        rep(i,n)if(c[i]==0){
            c[i]=1;dfs(i);
            if(flag)break;
        }
        if(flag){
            puts("NO");
            continue;
        }
        puts("YES");
        rep(i,n)for(int v:t[i])add(i,v,c[i]!=c[v]);
        for(auto p:ans)printf("%d %d %d\n",p.st.st,p.st.nd,p.nd);
    }
    return 0;
}
/*


*/