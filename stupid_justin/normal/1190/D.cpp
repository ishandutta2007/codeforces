#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define endl "\n"
#define int long long
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define y1 _
#define pii pair<int,int> 
#define mp make_pair
using namespace std;
const int N=1e6+5;
const int M=12505;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
struct treearray
{
    int a[N],n;
    void clear(int m){n=m;for (int i=0;i<=m;i++) a[i]=0;}
    void add(int i,int x){for (;i<=n;i+=i&-i) a[i]+=x;}
    int query(int i){int ret=0;for (;i;i^=i&-i) ret+=a[i];return ret;}
    int operator[](int x) {return query(x);}
}T;
int n,ans;
struct P{int x,y;}p[N];
int X[N],m;
bool cmp(P a,P b){return a.y!=b.y?a.y>b.y:a.x<b.x;}
int vis[N];
signed main()
{
    rd(n);for (int i=1;i<=n;i++) rd(p[i].x),rd(p[i].y),X[i]=p[i].x;
    sort(X+1,X+n+1);m=unique(X+1,X+n+1)-X-1;
    for (int i=1;i<=n;i++) p[i].x=lower_bound(X+1,X+m+1,p[i].x)-X;
    sort(p+1,p+n+1,cmp);T.clear(n);
    for (int i=1;i<=n;i++) 
    {
        int r=n;
        if (i!=n && p[i].y==p[i+1].y) r=p[i+1].x-1;
        int A=T[p[i].x-1],B=T[r]-T[p[i].x];
        ans+=(A+1)*(B+1);
        if (!vis[p[i].x]) T.add(p[i].x,1),vis[p[i].x]=1;
    }
    cout<<ans<<endl;

    
}
/*

    for(i=0;i++<n;)
	{
		REP(w[i].x,1);
		if(w[i].y^w[i+1].y)z=n;
		else z=w[i+1].x-1;
		s+=sum(w[i].x)*LR(w[i].x,z);
	}
	cout<<s;
    
*/