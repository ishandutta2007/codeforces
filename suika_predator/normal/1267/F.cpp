#include<bits/stdc++.h>
using namespace std;
int a[233333],b[233333],cnt[233333];
priority_queue<int,vector<int>,greater<int> > pq;
int main()
{
	int n,m,ka,kb;
	scanf("%d%d%d%d",&n,&m,&ka,&kb);
	if(ka>=m||kb>=n)return puts("No"),0;
	puts("Yes");
	for(int i=1;i<=ka;i++)scanf("%d",&a[i]),cnt[a[i]]++;
	for(int i=ka+1;i<m;i++)a[i]=n,cnt[a[i]]++;
	for(int i=1;i<=kb;i++)scanf("%d",&b[i]),cnt[b[i]]++;
	for(int i=kb+1;i<n;i++)b[i]=m+n,cnt[b[i]]++;
	a[m]=n;b[n]=m+n;
	for(int i=1;i<=n+m;i++)
	{
		if(!cnt[i])pq.push(i);
	}
	int ia=1,ib=1,fl=0;
	while(!pq.empty())
	{
		fl++;
//		cerr<<fl<<endl;
		if(fl==n+m)break;
		int u=pq.top();pq.pop();
		if(u<=n)
		{
			printf("%d %d\n",u,b[ib]);
			cnt[b[ib]]--;
			if(cnt[b[ib]]==0)pq.push(b[ib]);
			ib++;
		}
		else
		{
			printf("%d %d\n",u,a[ia]);
			cnt[a[ia]]--;
			if(cnt[a[ia]]==0)pq.push(a[ia]);
			ia++;
		}
	}
	return 0;
}