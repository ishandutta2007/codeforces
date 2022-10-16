#include<bits/stdc++.h>
#define int long long
#define ls (rt<<1)
#define rs (rt<<1|1)
#define pii pair<int,int>
#define fi first
#define se second
#define rd(x) x=read()
#define endl '\n'
using namespace std;

const int N=1e6+5;
const int M=1e7+5;
const int mod=1e9+7;
const int inf=3e18;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x);x=(x*x);y>>=1;}return ret;}

int T,n,k;
int t=1;
char s[5][N];
int a[4];
bool get(char *s1,char *s2,int c1,int c2)
{
	t=0;
	if (c1<=n && c2<=n) 
	{
		int p1=1,p2=1;
		for (int i=1;i<=min(2*n-c1,2*n-c2);i++)
		{
			while (s1[p1]=='1') s[4][++t]='1',p1++;
			while (s2[p2]=='1') s[4][++t]='1',p2++;
			p1++;p2++;s[4][++t]='0';
		}
		while (p1<=2*n) s[4][++t]=s1[p1],p1++;
		while (p2<=2*n) s[4][++t]=s2[p2],p2++;
		return 1;
	} else
	if (c1>=n && c2>=n)
	{
		int p1=1,p2=1;
		for (int i=1;i<=min(c1,c2);i++)
		{
			while (s1[p1]=='0') s[4][++t]='0',p1++;
			while (s2[p2]=='0') s[4][++t]='0',p2++;
			p1++;p2++;s[4][++t]='1';
		}
		while (p1<=2*n) s[4][++t]=s1[p1],p1++;
		while (p2<=2*n) s[4][++t]=s2[p2],p2++;
		return 1;
	}
	return 0;
}
signed main()
{
	
	rd(T);
	while (T--)
	{
		rd(n);
		for (int i=1;i<=3*n;i++) s[4][i]='0';
		for (int i=1;i<=3;i++) scanf("%s",s[i]+1);
		a[1]=a[2]=a[3]=0;
		for (int i=1;i<=3;i++) for (int j=1;j<=2*n;j++) if (s[i][j]=='1') a[i]++;
		if (get(s[1],s[2],a[1],a[2])) {for (int i=1;i<=3*n;i++) putchar(s[4][i]);puts("");continue;}
		if (get(s[1],s[3],a[1],a[3])) {for (int i=1;i<=3*n;i++) putchar(s[4][i]);puts("");continue;}
		if (get(s[2],s[3],a[2],a[3])) {for (int i=1;i<=3*n;i++) putchar(s[4][i]);puts("");continue;}
	}
}