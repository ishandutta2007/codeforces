#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100005;
int n,k,i;
int x[maxn],r[maxn],f[maxn];
int p[maxn],q[maxn];
int ap[maxn*2],vp[maxn*2],aq[maxn*2];
long long ans;
bool cmp(int x,int y)
{
	return r[x]<r[y];
}
int val[10020];
void ins(int u,int v)
{
	for (int i=u;i<=10010;i+=i&(-i))
		val[i]+=v;
}
int qry(int u)
{
	if (u<0)
		return 0;
	int ret=0;
	for (int i=u;i;i-=i&(-i))
		ret+=val[i];
	return ret;
}
int query(int l,int r)
{
	return qry(r)-qry(l-1);
}
void cdq(int vl,int vr)
{
	if (vl==vr)
		return;
	int mid=(vl+vr)>>1;
	cdq(vl,mid);
	cdq(mid+1,vr);
	memset(val,0,sizeof(val));
	int ql,qr=mid;
	for (i=vl*2-1;i<=mid*2;i++)
	{
		while (qr<vr&&x[p[qr+1]]<=ap[vp[i]])
		{
			qr++;
			ins(f[p[qr]],1);
		}
		if (vp[i]&1)
			ans-=query(f[(vp[i]+1)/2]-k,f[(vp[i]+1)/2]+k);
		else
			ans+=query(f[(vp[i]+1)/2]-k,f[(vp[i]+1)/2]+k);
	}
	ql=vl;
	qr=mid+1;
	for (i=vl;i<=vr;i++)
		if (qr>vr||(ql<=mid&&x[p[ql]]<x[p[qr]]))
			q[i]=p[ql++];
		else
			q[i]=p[qr++];
	for (i=vl;i<=vr;i++)
		p[i]=q[i];
	ql=vl*2-1;
	qr=mid*2+1;
	for (i=vl*2-1;i<=vr*2;i++)
		if (qr>vr*2||(ql<=mid*2&&ap[vp[ql]]<ap[vp[qr]]))
			aq[i]=vp[ql++];
		else
			aq[i]=vp[qr++];
	for (i=vl*2-1;i<=vr*2;i++)
		vp[i]=aq[i];
}
int main()
{
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x[i],&r[i],&f[i]);
		ap[i*2-1]=x[i]-r[i]-1;
		ap[i*2]=x[i]+r[i];
		p[i]=i;
	}
	sort(p+1,p+n+1,cmp);
	for (i=1;i<=n;i++)
	{
		vp[i*2-1]=p[i]*2-1;
		vp[i*2]=p[i]*2;
	}
	cdq(1,n);
	printf("%lld\n",ans);
	return 0;
}