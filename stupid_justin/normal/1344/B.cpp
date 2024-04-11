#include<bits/stdc++.h>
#define endl "\n"
#define rd(x) x=read()
#define wt(x) write(x)
#define pii pair<int,int>
#define pq priority_queue<int>
using namespace std;
const int N=1000+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if (x<0){putchar('-');x=-x;}if (x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,m;
int a[N];
char s[N][N];
bool hn[N],hm[N];
int id(int x,int y){return (x-1)*m+y;}
int fa[N*N];
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
void merge(int u,int v){u=getfa(u);v=getfa(v);if (u!=v) fa[u]=v;}
void DOIT()
{
    // #...# 
    rd(n);rd(m);
    for (int i=0;i<=n+1;i++) for (int j=0;j<=m+1;j++) s[i][j]='.';
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) fa[id(i,j)]=id(i,j);
    for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for (int i=1;i<=n;i++)
    {
        int flag=0;
        for (int j=1;j<=m;j++)
        {
            if (s[i][j]=='#' && flag==2) {puts("-1");return;}else 
            if (s[i][j]=='#' && flag==0) {flag=1;}else 
            if (s[i][j]=='.' && flag==1) {flag=2;} 
        }
    }
    for (int j=1;j<=m;j++)
    {
        int flag=0;
        for (int i=1;i<=n;i++)
        {
            if (s[i][j]=='#' && flag==2) {puts("-1");return;}else 
            if (s[i][j]=='#' && flag==0) {flag=1;}else 
            if (s[i][j]=='.' && flag==1) {flag=2;} 
        }
    }
    for (int i=1;i<=n;i++) hn[i]=0;
    for (int j=1;j<=m;j++) hm[j]=0;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (s[i][j]=='#') hn[i]=hm[j]=1;
    int f1=0,f2=0;
    for (int i=1;i<=n;i++) if (hn[i]==0) f1=1;
    for (int i=1;i<=m;i++) if (hm[i]==0) f2=1;
    if (f1+f2==1) {puts("-1");return;}
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (s[i][j]=='#')
    {
        if (s[i+1][j]=='#') merge(id(i,j),id(i+1,j));
        if (s[i-1][j]=='#') merge(id(i,j),id(i-1,j));
        if (s[i][j+1]=='#') merge(id(i,j),id(i,j+1));
        if (s[i][j-1]=='#') merge(id(i,j),id(i,j-1));
    }
    int ans=0;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (s[i][j]=='#') if (getfa(id(i,j))==id(i,j)) ans++;
    cout<<ans<<"\n";

}
signed main()
{
    DOIT();
}
/*
2*3*5  

*/