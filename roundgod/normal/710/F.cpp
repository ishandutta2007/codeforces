#include<bits/stdc++.h>
#define MAXN 300005
#define MAXC 26
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int m;
struct aho_corasick {
    int cnt=0;
    vector<int> kmp;
    vector<vector<int> > ch,nxt;
    vector<ll> dp;
    void init()
    {
        kmp.clear(); ch.clear(); nxt.clear(); dp.clear(); cnt=0;
        ch.push_back(vector<int>(26,0)); nxt.push_back(vector<int>(26,0)); dp.push_back(0);
    }
    void add(string &s) {
        int cur=0;
        for(char &c:s) {
            if(!ch[cur][c-'a']) {ch.push_back(vector<int>(26,0)); nxt.push_back(vector<int>(26,0)); dp.push_back(0); ch[cur][c-'a']=++cnt;}
            cur=ch[cur][c-'a'];
        }
        dp[cur]++;
    }
    void BFS() {
        kmp.resize(ch.size());
        queue<int> q;
        for(q.push(0);!q.empty();q.pop()) {
            int u=q.front(); dp[u]+=dp[kmp[u]];
            for(int i=0;i<MAXC;i++) {
                if(ch[u][i]>0) {
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
    pair<long long,int> traverse(string s,int st) {
        long long ret=0;
        for (char &c:s) {
            st=nxt[st][c-'a'];
            ret+=dp[st];
        }
        return {ret,st};
    }
} acs[19],acsdel[19];
vector<string> v[19];
vector<string> vdel[19];
int main()
{
    for(int i=0;i<19;i++) acs[i].init(),acsdel[i].init();
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int t;
        string str;
        cin>>t>>str;
        if(t==1)
        {
            v[0].push_back(str);
            int now=0;
            while(v[now].size()>(1<<now))
            {
                for(auto &x:v[now]) v[now+1].push_back(x);
                acs[now].init();
                v[now].clear(); now++;
            }
            acs[now].init();
            for(auto &x:v[now]) acs[now].add(x);
            acs[now].BFS();
        }
        else if(t==2)
        {
            vdel[0].push_back(str);
            int now=0;
            while(vdel[now].size()>(1<<now))
            {
                for(auto &x:vdel[now]) vdel[now+1].push_back(x);
                acsdel[now].init();
                vdel[now].clear(); now++;
            }
            acsdel[now].init();
            for(auto &x:vdel[now]) acsdel[now].add(x);
            acsdel[now].BFS();
        }
        else
        {
            int ans=0;
            for(int i=0;i<19;i++) if(v[i].size()) ans+=acs[i].traverse(str,0).F;
            for(int i=0;i<19;i++) if(vdel[i].size()) ans-=acsdel[i].traverse(str,0).F;
            printf("%d\n",ans);
            fflush(stdout);
        }
    }
    return 0;
}