#include<map>
#include<cstdio>
#include<algorithm>

using namespace std;

map<int,int>cnt;

int n,a[1010],now,last,q[1010],Now;

int main()
{
	int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),cnt[a[i]]++;
	ans=cnt[0];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(i^j)
			{
				if(!a[i]&&!a[j])continue;
				now=a[i]+a[j];int l=0;
				last=a[j];q[++l]=a[j];q[++l]=a[i];
				cnt[a[i]]--;cnt[a[j]]--;
				now=a[i]+last;
				while(cnt[now])cnt[now]--,q[++l]=now,Now=now,now=last+now,last=Now;
				for(int k=1;k<=l;k++)
					cnt[q[k]]++;
				ans=max(ans,l);
			}
	}
	printf("%d\n",ans);
}