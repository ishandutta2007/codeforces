#include<bits/stdc++.h>
#define MAXN 50020
#define MAXC 26
#define INF 1000000000
#define MOD 998244353
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
int n,m;
string s;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
mat mul(mat A,mat B)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<A.size();i++)
        for(int k=0;k<B.size();k++)
            for(int j=0;j<B[0].size();j++)
                add(C[i][j],1LL*A[i][k]*B[k][j]%MOD);
    return C;
}
mat pow_mod(mat A,int n)
{
    mat B(A.size(),vec(A.size()));
    for(int i=0;i<A.size();i++)
        B[i][i]=1;
    while(n>0)
    {
        if(n&1) B=mul(B,A);
        A=mul(A,A);
        n>>=1;
    }
    return B;
}
struct aho_corasick {
    int cnt=0,link[MAXN],ch[MAXN][MAXC],nxt[MAXN][MAXC];
    bool term[MAXN];
    int top[MAXN];
    void add(string &s) {
        int cur=0;
        for(char &c:s) {
            if(ch[cur][c-'a']==0) ch[cur][c-'a']=++cnt;
            cur=ch[cur][c-'a'];
        }
        term[cur]=true;
    }
    void BFS() {
        queue<int> q;
        for(q.push(0);!q.empty();q.pop()) {
            int u=q.front();
            top[u]=(term[link[u]]?link[u]:top[link[u]]);
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
int num,tot,id[MAXN];
bool vis[MAXN];
void dfs(int u,int v)
{
    if(vis[u*num+v]) return;
    vis[u*num+v]=true;
    id[u*num+v]=tot++;
    for(int ch=0;ch<26;ch++)
    {
        int ni=acs.ch[u][ch],nj=acs.ch[v][ch];
        if((!ni)||(!nj)) continue;
        dfs(ni,nj);
        if(acs.term[ni]) dfs(0,nj);
        if(acs.term[nj]) dfs(ni,0);
    }
}
string str;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        acs.add(str);
    }
    acs.BFS();
    num=acs.cnt+1;
    dfs(0,0);
    mat trans(tot,vec(tot,0));
    for(int i=0;i<num;i++)
        for(int j=0;j<num;j++)
        {
            int state=i*num+j;
            if(!vis[state]) continue;
            for(int ch=0;ch<26;ch++)
            {
                if(acs.ch[i][ch]&&acs.ch[j][ch])
                {
                    int ni=acs.ch[i][ch],nj=acs.ch[j][ch];
                    assert(ni&&nj);
                    trans[id[state]][id[ni*num+nj]]++;
                    if(acs.term[ni]) trans[id[state]][id[nj]]++;
                    if(acs.term[nj]) trans[id[state]][id[ni*num]]++;
                    if(acs.term[ni]&&acs.term[nj]) trans[id[state]][id[0]]++; 
                }
            }
        }
    mat v(1,vec(tot)); 
    v[0][0]=1;
    trans=pow_mod(trans,m);
    v=mul(v,trans);
    printf("%d\n",v[0][0]);
    return 0;
}