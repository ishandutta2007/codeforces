#include <bits/stdc++.h>
using namespace std;
const int N=3e5,M=1e3;
vector<int> pos[N];
int bel[N],a[N],l[M],r[M],s[M],cs[N];
bool app[N];
int n,i,j,k,x,ksiz,lp,rp,qs,ans,mx;
struct Q
{
	int z,y,wz;
	Q(int a=0,int b=0,int c=0):z(a),y(b),wz(c){}
	bool operator<(const Q &o) {return (bel[z]<bel[o.z])||(bel[z]==bel[o.z])&&((bel[z]&1)&&(y<o.y)||(1^bel[z]&1)&&(o.y>y));}
};
Q q[N];
inline void read(register int &x)
{
	register int c=getchar();
	while ((c<48)||(c>57)) c=getchar();
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
}
inline void add(const int x)
{
	if (++cs[x]==1) ++s[bel[x]];
}
inline void del(const int x)
{
	if (--cs[x]==0) --s[bel[x]];
}
int main()
{
	read(n);ksiz=sqrt(n);
	for (i=1;i<=n;i++) {read(a[i]);pos[a[i]].push_back(i);mx=max(mx,a[i]);}
	for (i=1;i<=n;i++) if (a[i]!=1) break;
	if (i>n) return puts("1"),0;
	for (i=1;i<=n;i++) {bel[i]=(i-1)/ksiz+1;r[bel[i]]=i;if (!l[bel[i]]) l[bel[i]]=i;}
	for (i=2;i<=mx+1;i++) if (pos[i].size())
	{
		for (j=1;j<pos[i].size();j++) if (pos[i][j-1]+1!=pos[i][j]) q[++qs]=Q(pos[i][j-1]+1,pos[i][j]-1,i);
		if (pos[i][0]>1) q[++qs]=Q(1,pos[i][0]-1,i);
		if (pos[i][pos[i].size()-1]<n) q[++qs]=Q(pos[i][pos[i].size()-1]+1,n,i);
	} else q[++qs]=Q(1,n,i);
	sort(q+1,q+qs+1);lp=q[1].z;rp=lp-1;
	for (i=1;i<=qs;i++)
	{
		while (rp<q[i].y) add(a[++rp]);
		while (lp>q[i].z) add(a[--lp]);
		while (rp>q[i].y) del(a[rp--]);
		while (lp<q[i].z) del(a[lp++]);
		for (j=1;j<=bel[n];j++) if (s[j]!=r[j]-l[j]+1)
		{
			for (k=l[j];k<=r[j];k++) if (!cs[k]) break;
			break;
		}if (j>bel[n]) k=n+1;
		app[q[i].wz]|=(k==q[i].wz);
	}
	for (i=2;i<=n+2;i++) if (!app[i]) break;
	printf("%d",i);
}