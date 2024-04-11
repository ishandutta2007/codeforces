#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#include<set>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define pb push_back

using namespace std;
const int N=300005;
bool vis[N];
int n,m,p[N],f[N],g[N],d[N],s[N],t[N],ans;
vector <int> vt1[N],vt2[N];
set <int> st;

int getint()
{
    char ch;
    while(!isdigit(ch=getchar()));
    int x=ch-48;
    while(isdigit(ch=getchar())) x=x*10+ch-48;
    return x;
}

bool check(int x)
{
    return (f[x]==1 && g[x]==1) || (f[x]==2 && g[x]==1) || (f[x]==1 && g[x]==2);
}

void dfs(int x)
{
    vis[x]=1;
    int sz=vt1[x].size();
    rep(i,0,sz-1) if(!vis[vt1[x][i]]) dfs(vt1[x][i]);
    p[++*p]=x;
}

void solve()
{
    memset(d,0,sizeof(d));
    memset(s,0,sizeof(s));
    st.clear();
    rep(i,1,n)
    {
        int x=p[i],sz=vt1[x].size();
        rep(j,0,sz-1)
        {
            int y=vt1[x][j];
            if((++d[y])==1)
            {
                ++s[x],t[y]=x;
                st.erase(y);
            }
            if(d[y]==2) --s[t[y]];
        }
        if(st.size()==0) f[i]=1;
        else if(st.size()==1 && !s[*st.begin()]) f[i]=2;
    	st.insert(x);
	}
    
    memset(d,0,sizeof(d));
    memset(s,0,sizeof(s));
    st.clear();    
    repd(i,n,1)
    {
        int x=p[i],sz=vt2[x].size();
        rep(j,0,sz-1)
        {
            int y=vt2[x][j];
            if((++d[y])==1)
            {
                ++s[x],t[y]=x;
                st.erase(y);
            }
            if(d[y]==2) --s[t[y]];
        }
        if(st.size()==0) g[i]=1;
        else if(st.size()==1 && !s[*st.begin()]) g[i]=2;
		st.insert(x);
    }
}

int main()
{
    n=getint(),m=getint();
    rep(i,1,m)
    {
        int u=getint(),v=getint();
        vt1[u].pb(v),vt2[v].pb(u);
    }
    rep(i,1,n) if(!vis[i]) dfs(i);
    solve();
    rep(i,1,n) ans+=check(i);
    printf("%d\n",ans);
    return 0;
}