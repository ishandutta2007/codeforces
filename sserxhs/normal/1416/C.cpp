#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
const int N=3e5+2;
pa g[N];
int a[N],f[N],b[N];
ll ans[30],tot[30],ta;
int n,c,fh,i,anss;
inline void read(int &x)
{
	c=getchar();fh=1;
	while ((c<48)||(c>57))
	{
		if (c=='-') {c=getchar();fh=-1;break;}
		c=getchar();
	}
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	x*=fh;
}
void sol(int l,int r,int m)
{
	if ((l>r)||(m==-1)) return;
	int i;
	f[l-1]=0;
	for (i=l;i<=r;i++) f[i]=f[i-1]+(a[i]>>m&1);
	for (i=l;i<=r;i++) ans[m]+=(1^(a[i]>>m&1))*f[i];
	for (i=l;i<=r;i++) g[i]=make_pair(a[i]>>m&1,i);
	sort(g+l,g+r+1);
	for (i=l;i<=r;i++) b[i]=a[g[i].second];
	for (i=l;i<=r;i++) a[i]=b[i];
	for (i=l;i<=r;i++) if (a[i]>>m&1) break;
	tot[m]+=(ll)(r-i+1)*(i-l);
	sol(l,i-1,m-1); sol(i,r,m-1);
}
int main()
{
	read(n);
	for (i=1;i<=n;i++) read(a[i]);
	sol(1,n,29);
	for (i=0;i<=29;i++) if ((ans[i]<<1)>(tot[i]))
	{
		anss|=(1<<i);ta+=tot[i]-ans[i];
	} else ta+=ans[i];
	printf("%lld %d",ta,anss);
}