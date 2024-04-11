#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k;
int a[300005],b[300005],use[300005],cnt[600005];
int Inc,inc[300005],inc_val[300005];
long long ans,tmp;

struct node
{
	int x,id,id2;
}t[600005];
inline bool cmp(const node &a,const node &b)
{
	if(a.x!=b.x)return a.x<b.x;
	if(a.id2!=b.id2)return a.id2<b.id2;
	return a.id<b.id;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",&a[i],&b[i]);
		a[i]<<=1;b[i]<<=1;
		if(b[i]-a[i]<a[i])t[i].x=t[i+n].x=b[i]>>1,t[i].id2=i*2,t[i+n].id2=i*2+1;
		else t[i].x=a[i],t[i+n].x=b[i]-a[i];
		t[i].id=i;t[i+n].id=i+n;
	}
	sort(t+1,t+n+n+1,cmp);
	for(i=1;i<=m;++i)ans+=t[i].x,++cnt[t[i].id];
	if(t[m].id<=n&&!cnt[t[m].id+n]&&t[m].x!=a[t[m].id])
	{
		tmp=ans-t[m].x;
		ans=ans-t[m].x+a[t[m].id];
		--cnt[t[m].id];
		Inc=1;inc[Inc]=t[m].id;inc_val[Inc]=1;
		for(i=1;i<=n;++i)
		if(i!=t[m].id)
		{
			if(!cnt[i])
			{
				if(a[i]+tmp<ans)
				{
					Inc=0;
					inc[++Inc]=i;inc_val[Inc]=1;
					ans=a[i]+tmp;
				}
			}
			if(cnt[i]&&!cnt[i+n])
			{
				if(tmp+b[i]-a[i]<ans)
				{
					Inc=0;
					inc[++Inc]=i+n;inc_val[Inc]=1;
					ans=tmp+b[i]-a[i];
				}
				if(tmp-a[i]+b[t[m].id]<ans)
				{
					Inc=0;
					inc[++Inc]=i;inc_val[Inc]=-1;
					inc[++Inc]=t[m].id;inc_val[Inc]=1;
					inc[++Inc]=t[m].id+n;inc_val[Inc]=1;
					ans=tmp-a[i]+b[t[m].id];
				}
			}
			if(cnt[i]&&cnt[i+n])
			{
				if(tmp-b[i]+a[i]+b[t[m].id]<ans)
				{
					Inc=0;
					inc[++Inc]=i+n;inc_val[Inc]=-1;
					inc[++Inc]=t[m].id;inc_val[Inc]=1;
					inc[++Inc]=t[m].id+n;inc_val[Inc]=1;
					ans=tmp-b[i]+a[i]+b[t[m].id];
				}
			}
		}
		for(;Inc;--Inc)cnt[inc[Inc]]+=inc_val[Inc];
	}
	printf("%I64d\n",ans>>1);
	for(i=1;i<=n;++i)printf("%d",cnt[i]+cnt[i+n]);
	printf("\n");
}