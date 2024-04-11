#include<bits/stdc++.h>
#define int long long 
#define ri register int
#define rd(x) x=read()
using namespace std;
const int N=2e5+5;
const int M=1e6+5;
const int maxn=1e7+5;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y,int z){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
inline int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
inline int INV(int x){return ksm(x,mod-2);}
int cnt;

int n,c;
char s[N],a[N],b[N];
signed main()
{
	int T;cin>>T;while (T--)
	{
		rd(n);scanf("%s",s);
		cnt=0;

		if (s[0]=='0' || s[n-1]=='0') {puts("NO");continue;}
		for (int i=0;i<n;i++)
		{
			a[i]=b[i]='(';
			if (s[i]=='0') {cnt++;if (cnt&1) a[i]=')';else b[i]=')';}
		}
		if (cnt%2==1) {puts("NO");continue;}
		cnt=(n-cnt)/2;
		for (int i=n-1;i>=0;i--)
		{
			if (s[i]=='1' && cnt) cnt--,a[i]=b[i]=')';
		}
		if (cnt) {puts("NO");continue;}
		puts("YES");
		for (int i=0;i<n;i++) putchar(a[i]);puts("");
		for (int i=0;i<n;i++) putchar(b[i]);puts("");
	}
}