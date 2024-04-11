#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,cnt;
string str;
vector<int> G[30];
map<P,int> mp;
string ans;
bool vis[30];
void dfs(int v,int p)
{
    cnt++;
    ans+=(char)(v+'a'-1);
    vis[v]=true;
    for(auto to:G[v])
    {
        if(!vis[to]) dfs(to,v);
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        cin>>str;
        int n=str.size();
        for(int i=1;i<=26;i++) G[i].clear();
        mp.clear();
        for(int i=1;i<n;i++)
        {
            int u=str[i]-'a'+1,v=str[i-1]-'a'+1;
            if(u==v) continue;
            if(u>v) swap(u,v);
            if(mp.find(P(u,v))!=mp.end()) continue;
            mp[P(u,v)]=true;
            G[u].push_back(v); G[v].push_back(u);
        }
        bool f=true;
        for(int i=1;i<=26;i++)
            if((int)G[i].size()>2) f=false;
        ans=""; cnt=0;
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=26;i++)
        {
            if((int)G[i].size()==0||(int)G[i].size()==1&&(!vis[i])) dfs(i,0);
        }
        if(cnt!=26) f=false;
        if(!f) puts("NO");
        else
        {
            puts("YES");
            cout<<ans<<endl;
        }
        
    }
    return 0;
}