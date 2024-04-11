#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 8005
#define MAXC 13
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,c[MAXN];
string str;
struct aho_corasick {
    int cnt=0,link[MAXN],ch[MAXN][MAXC],nxt[MAXN][MAXC];
    int dp[MAXN];
    int top[MAXN];
    void add(string &s,int c) {
        int cur=0;
        for(char &c:s) {
            if(ch[cur][c-'a']==0) ch[cur][c-'a']=++cnt;
            cur=ch[cur][c-'a'];
        }
        dp[cur]+=c;
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
set<int> s[13];
string x;
int f[(1<<12)][8005];
P pre[(1<<12)][8005];
void dfs(int v,int p)
{
    x+='a'+v;
    for(auto to:s[v])
    {
        if(to==p) continue;
        dfs(to,v);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&c[i]);
        cin>>str;
        int m=(int)str.size();
        for(int i=0;i<12;i++) s[i].clear();
        for(int j=1;j<m;j++)
        {
            s[str[j-1]-'a'].insert(str[j]-'a');
            s[str[j]-'a'].insert(str[j-1]-'a');
        }
        bool f=true;
        int id=-1;
        for(int i=0;i<12;i++) if(s[i].size()>2) f=false;
        for(int i=0;i<12;i++) if(s[i].size()==1) id=i;
        if(id==-1) f=false;
        if(!f) continue;
        x="";
        dfs(id,-1);
        acs.add(x,c[i]);
        reverse(x.begin(),x.end());
        acs.add(x,c[i]);
    }
    acs.BFS();
    memset(f,-1,sizeof(f));
    f[0][0]=0;
    for(int mask=0;mask<(1<<12);mask++)
    {
        for(int state=0;state<=acs.cnt;state++)
        {
            if(f[mask][state]==-1) continue;
            for(int i=0;i<12;i++)
            {
                if(mask&(1<<i)) continue;
                int nxt=acs.nxt[state][i];
                if(f[mask][state]+acs.dp[nxt]>f[mask^(1<<i)][nxt])
                {
                    f[mask^(1<<i)][nxt]=f[mask][state]+acs.dp[nxt];
                    pre[mask^(1<<i)][nxt]=P(mask,state);
                }
            }
        }
    }
    int mask=(1<<12)-1,state=0;
    for(int i=0;i<=acs.cnt;i++) if(f[mask][i]>f[mask][state]) state=i;
    x="";
    while(mask)
    {
        P p=pre[mask][state]; int dif=p.F^mask;
        int cnt=0; while(dif>1) {cnt++; dif/=2;}
        x+=(char)('a'+cnt);
        mask=p.F; state=p.S;
    }
    reverse(x.begin(),x.end());
    cout<<x<<endl;
    return 0;
}