#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXC 10
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x;
int sum[25];
void upd(int &a,int b) {a=min(a,b);}
string s,str;
struct aho_corasick {
    int cnt=0,link[MAXN],ch[MAXN][MAXC],nxt[MAXN][MAXC];
    int dp[MAXN];
    void add(string &s) {
        int cur=0;
        for(char &c:s) {
            if(ch[cur][c-'1']==0) ch[cur][c-'1']=++cnt;
            cur=ch[cur][c-'1'];
        }
        dp[cur]++;
    }
    void BFS() {
        queue<int> q;
        for(q.push(0);!q.empty();q.pop()) {
            int u=q.front();
            dp[u]+=dp[link[u]];
            for(int i=0;i<MAXC;i++) {
                if(ch[u][i]>0) {
                    int v=ch[u][i];
                    q.push(v);
                    nxt[u][i]=v;
                    link[v]=nxt[link[u]][i];
                    if (link[v]==v) link[v]=0;
                } 
                else nxt[u][i]=nxt[link[u]][i];
            }
        }
    }
} acs;
void dfs(int now)
{
    if(sum[now]==x) {acs.add(str); return;}
    for(int i=1;i<=9;i++)
    {
        if(sum[now]+i>x) continue;
        bool f=true;
        for(int j=0;j<=now;j++) if((sum[now]+i-sum[j]!=x)&&(x%(sum[now]+i-sum[j])==0)) f=false;
        if(!f) continue;
        sum[now+1]=sum[now]+i;
        str+=(char)('0'+i);
        dfs(now+1);
        str.pop_back();
    }
}
int dp[1005][20005];
int main()
{
    cin>>s;
    n=(int)s.size();
    scanf("%d",&x);
    dfs(0);
    acs.BFS();
    for(int i=0;i<=n;i++)
        for(int j=0;j<=acs.cnt;j++)
            dp[i][j]=INF;
    dp[0][0]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<=acs.cnt;j++)
        {
            if(dp[i][j]==INF) continue;
            int nxt=acs.nxt[j][s[i]-'1'];
            upd(dp[i+1][j],dp[i][j]+1);
            if(!acs.dp[nxt]) upd(dp[i+1][nxt],dp[i][j]);
        }
    int ans=INF;
    for(int i=0;i<=acs.cnt;i++) ans=min(ans,dp[n][i]);
    printf("%d\n",ans);
    return 0;
}