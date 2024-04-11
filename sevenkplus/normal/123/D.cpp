#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define pb push_back
#define N 100010
#define P 1000000007
char s[1000010];int n,p[N],a[N],A[N],b[N],f[N],g[N];ll S=0,T=0;vector<int> B[N];
int hh(int x,int y)
{
    return a[y]-a[x-1]*p[y-x+1];
}
int lcp(int x,int y)
{
    int L=1,R=min(n-x+1,n-y+1);
    while(L<=R)
    {
        int M=(L+R)/2;
        if(hh(x,x+M-1)==hh(y,y+M-1))L=M+1;else R=M-1;
    }
    return R;
}
bool cmp(int x,int y)
{
    int p=lcp(x,y);
    if(n-x+1==p)return 1;
    if(n-y+1==p)return 0;
    return s[x+p]<s[y+p];
}
int fa(int x)
{
    if(f[x]==x)return x;
    f[x]=fa(f[x]),g[f[x]]+=g[x],g[x]=0;
    return f[x];
}
int ga(int x)
{
    if(f[x]==x)return g[x];
    f[x]=fa(f[x]),g[f[x]]+=g[x],g[x]=0;
    return g[f[x]];
}
ll gg2(int x){return (ll)x*(x+1)/2;}
void ff2(int x,int y)
{
    int A=ga(x),B=ga(y);
    T-=gg2(A),T-=gg2(B),T+=gg2(A+B);
    g[fa(x)]=0,f[fa(x)]=fa(y),g[fa(y)]+=A;
}
int main()
{
    scanf("%s",s+1);n=strlen(s+1);
    p[0]=1;for(int i=1;i<N;i++)p[i]=p[i-1]*P;
    a[0]=0;for(int i=1;i<=n;i++)a[i]=a[i-1]*P+s[i];
    for(int i=1;i<=n;i++)A[i]=i;
    sort(A+1,A+n+1,cmp);
    for(int i=1;i<=n;i++)b[n-A[i]+1]=i;
    for(int i=1;i<n;i++)B[lcp(A[i],A[i+1])].pb(i);
    for(int i=n;i>=1;i--)
    {
        int x=b[i];
        f[x]=x,g[x]=1,T++;
        for(vector<int>::iterator j=B[i].begin();j!=B[i].end();j++)ff2(*j,*j+1);
        S+=T;
    }
    cout<<S<<endl;
    return 0;
}