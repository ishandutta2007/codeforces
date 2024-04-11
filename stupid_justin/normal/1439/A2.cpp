
#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define endl "\n"
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int N=100+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,m;
int a[N][N];
char s[N][N];
struct op{int A,B,C,D,E,F;};
vector<op> ans;
void A(int X,int Y)
{
    if (a[X][Y]==0 && a[X][Y+1]==0) return;
    if (a[X][Y]==1 && a[X][Y+1]==1) ans.push_back({X,Y,X,Y+1,X+1,Y}),a[X][Y]^=1,a[X][Y+1]^=1,a[X+1][Y]^=1;
    if (a[X][Y]==1 && a[X][Y+1]==0) ans.push_back({X,Y,X+1,Y+1,X+1,Y}),a[X][Y]^=1,a[X+1][Y+1]^=1,a[X+1][Y]^=1;
    if (a[X][Y]==0 && a[X][Y+1]==1) ans.push_back({X+1,Y,X,Y+1,X+1,Y+1}),a[X+1][Y]^=1,a[X][Y+1]^=1,a[X+1][Y+1]^=1;
}
void B(int X,int Y)
{
    if (a[X][Y]==0 && a[X+1][Y]==0) return;
    if (a[X][Y]==1 && a[X+1][Y]==1) ans.push_back({X,Y,X,Y+1,X+1,Y}),a[X][Y]^=1,a[X][Y+1]^=1,a[X+1][Y]^=1;
    if (a[X][Y]==1 && a[X+1][Y]==0) ans.push_back({X,Y,X+1,Y+1,X,Y+1}),a[X][Y]^=1,a[X+1][Y+1]^=1,a[X][Y+1]^=1;
    if (a[X][Y]==0 && a[X+1][Y]==1) ans.push_back({X+1,Y,X,Y+1,X+1,Y+1}),a[X+1][Y]^=1,a[X][Y+1]^=1,a[X+1][Y+1]^=1;
}
void C(int X,int Y)
{
    int cnt=0;
    for (int i=X;i<=X+1;i++) for (int j=Y;j<=Y+1;j++) cnt+=a[i][j];
    int P[9],tot=0;
    if (cnt==0) return;
    if (cnt==3 || cnt==4) for (int i=X;i<=X+1;i++) for (int j=Y;j<=Y+1;j++) if (a[i][j]) P[++tot]=i,P[++tot]=j;
    if (cnt==2)
    {
        for (int i=X;i<=X+1;i++) for (int j=Y;j<=Y+1;j++) if (!a[i][j]) P[++tot]=i,P[++tot]=j; 
        for (int i=X;i<=X+1;i++) for (int j=Y;j<=Y+1;j++) if (a[i][j]) P[++tot]=i,P[++tot]=j; 
    }
    if (cnt==1)
    {
        for (int i=X;i<=X+1;i++) for (int j=Y;j<=Y+1;j++) if (a[i][j]) P[++tot]=i,P[++tot]=j; 
        for (int i=X;i<=X+1;i++) for (int j=Y;j<=Y+1;j++) if (!a[i][j]) P[++tot]=i,P[++tot]=j; 
    }
    ans.push_back({P[1],P[2],P[3],P[4],P[5],P[6]});
    a[P[1]][P[2]]^=1;a[P[3]][P[4]]^=1;a[P[5]][P[6]]^=1;
    C(X,Y);
}
void DOIT()
{
    ans.clear();
    rd(n);rd(m);
    for (int i=1;i<=n;i++) 
    {
        scanf("%s",s[i]+1);
        for (int j=1;j<=m;j++) a[i][j]=s[i][j]-'0';
    }
    for (int i=1;i<n;i++) for (int j=1;j<m;j+=2) A(i,j);
    for (int i=1;i<n-1;i++) A(i,m-1);
    for (int j=1;j<m-1;j++) B(n-1,j);
    C(n-1,m-1);
    cout<<ans.size()<<"\n";
    for (op x:ans) cout<<x.A<<" "<<x.B<<" "<<x.C<<" "<<x.D<<" "<<x.E<<" "<<x.F<<"\n";

}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();
}