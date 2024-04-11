#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 155
#define INF 1000000007
int n,a[N],f[N][N],f2[N][N],g[N][N][N],h[N][N][N];char s[N];
int ff(int l,int r);
int ff2(int l,int r);
int gg(int l,int r,int w);
int hh(int l,int r,int w);
int ff(int l,int r)
{
    if(l>=r)return 0;
    if(f[l][r]!=-1)return f[l][r];
    int&S=f[l][r]=0;
    if(l==r-1){if(a[1]!=-1)S=a[1];return S;}
    for(int i=l;i<r;i++)S=max(S,ff(l,i)+ff(i,r));
    S=max(S,ff2(l,r));
    return S;
}
int ff2(int l,int r)
{
    if(l>=r)return 0;
    if(f2[l][r]!=-1)return f2[l][r];
    int&S=f2[l][r]=-INF;
    if(l==r-1){if(a[1]!=-1)S=a[1];return S;}
    for(int i=l;i<r;i++)S=max(S,ff2(l,i)+ff2(i,r));
    if(s[l]==s[r-1])
        for(int i=2;i<=r-l;i++)if(a[i]!=-1)
            S=max(S,gg(l+1,r-1,i-2)+a[i]);
    return S;
}
int gg(int l,int r,int w)
{
    if(w==0)return ff2(l,r);
    if(l>=r)return -INF;
    if(r-l<w)return -INF;
    if(g[l][r][w]!=-1)return g[l][r][w];
    int&S=g[l][r][w]=-INF;
    if(w==1)
    {
        for(int i=l;i<r;i++)S=max(S,ff2(l,i)+ff2(i+1,r));
        return S;
    }
    for(int i=l;i<r;i++)S=max(S,ff2(l,i)+hh(i,r,w));
    return S;
}
int hh(int l,int r,int w)
{
    if(h[l][r][w]!=-1)return h[l][r][w];
    int&S=h[l][r][w]=-INF;
    for(int j=l+1;j<r;j++)
        if(s[l]==s[j])S=max(S,gg(l+1,j,w-2)+ff2(j+1,r));
    return S;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    scanf("%s",s);
    memset(f,-1,sizeof f),
    memset(f2,-1,sizeof f2),
    memset(g,-1,sizeof g),
    memset(h,-1,sizeof h);
    printf("%d\n",ff(0,n));
    return 0;
}