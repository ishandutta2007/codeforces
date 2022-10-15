#include<bits/stdc++.h>
#define MAXN 1050
#define MAXC 14
#define INF 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n;
string t[MAXN];
int c[MAXN];
string s;
struct aho_corasick {
    int cnt = 0, kmp[MAXN], ch[MAXN][MAXC], nxt[MAXN][MAXC];
    long long dp[MAXN];
 
    void add(string &s, int c) {
        int cur = 0;
        for (char &c : s) {
            if (ch[cur][c - 'a'] == 0) {
                ch[cur][c - 'a'] = ++cnt;
            }
            cur = ch[cur][c - 'a'];
        }
        dp[cur] += c;
    }
 
    void BFS() {
        queue<int> q;
        for (q.push(0); !q.empty(); q.pop()) {
            int u = q.front();
            dp[u] += dp[kmp[u]];
            for (int i = 0; i < MAXC; i++) {
                if (ch[u][i] > 0) {
                    int v = ch[u][i];
                    q.push(v);
                    nxt[u][i] = v;
                    kmp[v] = nxt[kmp[u]][i];
                    if (kmp[v] == v) {
                        kmp[v] = 0;
                    }
                } else {
                    nxt[u][i] = nxt[kmp[u]][i];
                }
            }
        }
    }
 
    P traverse(string s, int st) {
        long long ret = 0;
        for (char &c : s) {
            st = nxt[st][c - 'a'];
            ret += dp[st];
        }
        return {ret, st};
    }
} acs;
vector<int> pos;
P pre[15][MAXN][15];
ll dp[(1<<14)][MAXN];
int save[(1<<14)];
void upd(ll &a,ll b) {a=max(a,b);}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
        cin>>t[i]; scanf("%d",&c[i]);
        acs.add(t[i],c[i]);
    }
    for(int i=0;i<(1<<14);i++) save[i]=__builtin_popcount(i);
    acs.BFS();
    cin>>s;
    for(int i=0;i<(int)s.size();i++) if(s[i]=='?') pos.push_back(i);
    for(int i=0;i<(int)pos.size();i++)
    {
        P tmp[1005];
        string str;
        if(i==(int)pos.size()-1) str=s.substr(pos[i]+1); else str=s.substr(pos[i]+1,pos[i+1]-pos[i]-1);
        for(int j=0;j<=acs.cnt;j++) tmp[j]=acs.traverse(str,j);
        for(int j=0;j<=acs.cnt;j++)
            for(int k=0;k<14;k++)
            {
                string s=""; s+=(char)('a'+k);
                P p=acs.traverse(s,j);
                pre[i][j][k]=P(p.F+tmp[p.S].F,tmp[p.S].S);
            }           
    }
    if(!pos.size()) 
    {
        printf("%lld\n",acs.traverse(s,0).F);
        return 0;
    }
    for(int mask=0;mask<(1<<14);mask++)
        for(int state=0;state<=acs.cnt;state++)
            dp[mask][state]=-INF;
    P p=acs.traverse(s.substr(0,pos[0]),0);
    dp[0][p.S]=p.F;
    ll ans=-INF;
    for(int i=0;i<(int)pos.size();i++)
    {
        for(int mask=0;mask<(1<<14);mask++)
        {
            if(save[mask]!=i) continue;
            for(int state=0;state<=acs.cnt;state++)
            {
                if(dp[mask][state]==-INF) continue;
                for(int nxtch=0;nxtch<14;nxtch++)
                {
                    if(mask&(1<<nxtch)) continue;
                    P p=pre[i][state][nxtch];
                    upd(dp[mask^(1<<nxtch)][p.S],dp[mask][state]+p.F);
                }
            }
        }
    }
    for(int mask=0;mask<(1<<14);mask++)
        for(int state=0;state<=acs.cnt;state++)
            if(save[mask]==(int)pos.size()) ans=max(ans,dp[mask][state]);
    printf("%lld\n",ans);
    return 0;
}