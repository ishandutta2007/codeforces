#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+2,M=1<<20;
ll ans[N],na;
int a[N],cnt[M],bel[N];
int n,m,k,i,j,x,c,ksiz,l,r;
struct Q
{
	int z,y,wz;
	Q(int a=0,int b=0,int c=0):z(a),y(b),wz(c){}
	bool operator<(const Q& x) const {return (bel[z]<bel[x.z])||(bel[z]==bel[x.z])&&((y<x.y)&&(bel[z]&1)||(y>x.y)&&(1^bel[z]&1));}
};
Q q[N];
inline void read(int &x)
{
	c=getchar();
	while ((c<48)||(c>57)) c=getchar();
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
}
int main()
{
	read(n);read(m);++n;read(k);ksiz=sqrt(n);
	bel[1]=1;
	for (i=2;i<=n;i++) {read(a[i]);bel[i]=(i-1)/ksiz+1;a[i]^=a[i-1];}
	for (i=1;i<=m;i++) {read(q[i].z);read(q[q[i].wz=i].y);++q[i].y;}
	sort(q+1,q+m+1);
	l=q[1].z;r=l-1;
	for (i=1;i<=m;i++)
	{
		while (l>q[i].z) {na+=cnt[a[--l]^k];++cnt[a[l]];}
		while (r<q[i].y) {na+=cnt[a[++r]^k];++cnt[a[r]];}
		while (l<q[i].z) {--cnt[a[l]];na-=cnt[a[l++]^k];}
		while (r>q[i].y) {--cnt[a[r]];na-=cnt[a[r--]^k];}
		ans[q[i].wz]=na;
	}
	for (i=1;i<=m;i++) printf("%lld\n",ans[i]);
}