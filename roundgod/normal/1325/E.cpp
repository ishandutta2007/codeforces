#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],fa[MAXN];
bool single[MAXN];
bool is_square[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
vector<int> v[MAXN];
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int prime[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
vector<int> G[MAXN];
int ans,cnt;
int d[MAXN];
vector<int> tmp;
void solve(int x)
{
    tmp.clear();
    d[x]=0;
    queue<int> que;
    que.push(x);
    while(que.size())
    {
        int v=que.front(); que.pop(); 
        tmp.push_back(v);
        for(auto to:G[v])
        {
            if(d[to]==INF)
            {
                d[to]=d[v]+1;
                fa[to]=v;
                que.push(to);
            }
            else if(to!=fa[v]&&v!=fa[to])  ans=min(ans,d[v]+d[to]+1);
        }
    }
    for(auto x:tmp) {d[x]=INF; fa[x]=-1;}
}
int main()
{
    int p=sieve(1000000);
    scanf("%d",&n);
    memset(is_square,false,sizeof(is_square));
    for(int i=1;i<=1000;i++) is_square[i*i]=true;
    ans=INF;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(is_square[x]) {ans=1; continue;}
        for(int j=0;j<p;j++)
        {
            if(is_prime[x]) break;
            if(x%prime[j]==0)
            {
                int cnt=0;
                while(x%prime[j]==0) x/=prime[j],cnt++;
                if(cnt&1) v[i].push_back(prime[j]);
            }
        }
        if(x>1) v[i].push_back(x);
        if(v[i].size()==1) 
        {
            G[v[i][0]].push_back(0);
            G[0].push_back(v[i][0]);
        }
        else
        {
            G[v[i][0]].push_back(v[i][1]);
            G[v[i][1]].push_back(v[i][0]);
        }
    }
    for(int i=0;i<=1000000;i++)
    {
        sort(G[i].begin(),G[i].end());
        int sz1=(int)G[i].size();
        G[i].erase(unique(G[i].begin(),G[i].end()),G[i].end());
        int sz2=(int)G[i].size();
        if(sz1!=sz2) ans=min(ans,2);
    }
    fill(d,d+1000001,INF);
    memset(fa,-1,sizeof(fa));
    solve(0);
    for(int i=0;i<p;i++)
        if(prime[i]<=1000) solve(prime[i]);
    if(ans==INF) puts("-1"); else printf("%d\n",ans);
    return 0;
}