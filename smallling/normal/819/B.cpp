#include<bits/stdc++.h>

using namespace std;

int n,id,ne,po,now;
int p[2000020],pool[8000080],*cnt=pool+4000040;

int main()
{
	scanf("%d",&n);
	long long nowans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&p[i]);
		if(p[i]-i<0)ne++;
		else po++;
		cnt[p[i]-i]++;
		nowans+=abs(p[i]-i);
	}
	long long ans=1ll<<60;
	for(int i=n;i;i--)
	{
		if(nowans<ans)
		{
			ans=nowans;
			id=n-i;
		}
		cnt[p[i]-n+now]--;
		nowans-=abs(p[i]-n);
		if(p[i]-n<0)ne--;
		else po--;
		ne+=cnt[now];
		po-=cnt[now];
		now++;
		nowans+=ne-po+p[i]-1;
		cnt[p[i]-1+now]++;
		if(p[i]-1<0)ne++;
		else po++;
	}
	printf("%I64d %d\n",ans,id);
}