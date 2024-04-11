#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
string str;
int lson[MAXN],rson[MAXN],fa[MAXN];
char nxtch[MAXN];
int dp[MAXN],cnt;
vector<int> ord;
void dfs(int v)
{
    if(lson[v]) dfs(lson[v]);
    ord.push_back(v);
    if(rson[v]) dfs(rson[v]);
}
int solve(int v,int k)
{
    if(!v) return 0;
    if(!k) return dp[v]=0;
    int sum=0;
    int lused=solve(lson[v],k-1);
    if(lused)
    {
        dp[v]=1;
        return lused+1+solve(rson[v],k-lused-1);
    }
    else 
    {
        if(nxtch[v]>str[v-1]) { dp[v]=1;  return 1+solve(rson[v],k-1);}
        else return 0;
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    cin>>str;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d",&lson[i],&rson[i]);
        if(lson[i]) fa[lson[i]]=i;
        if(rson[i]) fa[rson[i]]=i;
    }
    dfs(1);
    nxtch[ord[n-1]]=str[ord[n-1]-1];
    for(int i=n-2;i>=0;i--)
    {
        int cur=ord[i],nxt=ord[i+1];
        if(str[nxt-1]==str[cur-1]) nxtch[cur]=nxtch[nxt]; else nxtch[cur]=str[nxt-1];
    }
    solve(1,k);
    for(auto x:ord) 
    {
        printf("%c",str[x-1]);
        if(dp[x]==1) printf("%c",str[x-1]);
    }
    return 0;
}