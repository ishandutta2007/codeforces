#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXC 26
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k[MAXN];
string str;
string s[MAXN];
vector<int> pos[MAXN];
struct aho_corasick 
{
    int cnt=0,kmp[MAXN],ch[MAXN][MAXC],nxt[MAXN][MAXC],id[MAXN],last[MAXN];
 
    void add(string &s,int i) 
    {
        int cur=0;
        for(char &c:s) 
        {
            if(ch[cur][c-'a']==0) ch[cur][c-'a']=++cnt;
            cur=ch[cur][c-'a'];
        }
        assert(!id[cur]);
        id[cur]=i;
    }
 
    void BFS() 
    {
        queue<int> q;
        for(q.push(0);!q.empty();q.pop()) 
        {
            int u=q.front();
            last[u]=(id[kmp[u]]?kmp[u]:last[kmp[u]]);
            for(int i=0;i<MAXC;i++) 
            {
                if(ch[u][i]>0) 
                {
                    int v=ch[u][i];
                    q.push(v);
                    nxt[u][i]=v;
                    kmp[v]=nxt[kmp[u]][i];
                    if (kmp[v]==v) kmp[v]=0;
                } 
                else nxt[u][i]=nxt[kmp[u]][i];
            }
        }
    }
 
    void solve(string &s) 
    {
        int st=0,cnt=0;
        for (char &c:s) 
        {
            st=nxt[st][c-'a'];
            int tmp=st;
            while(tmp)
            {
                if(id[tmp]) pos[id[tmp]].push_back(cnt);
                tmp=last[tmp];
            }
            cnt++;
        }
    }
} acs;
int main()
{
    cin>>str>>n;
    for(int i=1;i<=n;i++) {cin>>k[i]>>s[i]; acs.add(s[i],i);}
    acs.BFS(); acs.solve(str);
    for(int i=1;i<=n;i++)
    {
        if(pos[i].size()<k[i]) puts("-1");
        else
        {
            int ans=INF;
            for(int j=0;j+k[i]-1<(int)pos[i].size();j++)
                ans=min(ans,pos[i][j+k[i]-1]-pos[i][j]+(int)s[i].size());
            printf("%d\n",ans);
        }
    }
    return 0;
}