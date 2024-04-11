#include<bits/stdc++.h>
using namespace std;
long long a[123456];
long long b[123456];
pair<long long,int> c[123456];
long long d[123456];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++) scanf("%lld",&a[i]);
	sort(a,a+n);
	for(int i = 0;i<n-1;i++) b[i] = a[i+1] - a[i];
	sort(b,b+n-1);
	b[n-1] = 1e18;
	b[n-1] += 10;
	int q;
	scanf("%d",&q);
	for(int i = 0;i<q;i++)
	{
		long long x,y;
		scanf("%lld %lld",&x,&y);
		c[i] = make_pair(y-x+1,i);
	}
	sort(c,c+q);
	int pos = 0;
	long long ans = 0;
	long long ufl = n;
	long long cur = 0;
	for(int i = 0;i<q;i++)
	{
		while(pos<n)
		{
			if(c[i].first>b[pos])
			{
				//printf("GG pos = %d, cur = %lld, ufl = %lld, ans = %lld ,b[pos]= %lld\n",pos,cur,ufl,ans,b[pos]);
				ans += ufl*(b[pos]-cur);
				cur = b[pos];
				ufl --;
				pos ++;

			}
			else 
			{
				//printf("EZ pos = %d, cur = %lld, ufl = %lld, ans = %lld ,b[pos]= %lld\n",pos,cur,ufl,ans,b[pos]);
				ans += ufl*(c[i].first-cur);
				cur = c[i].first;
				break;
			}
		}
		//printf("pos = %d, cur = %lld, ufl = %lld, ans = %lld ,b[pos]= %lld\n",pos,cur,ufl,ans,b[pos]);
		d[c[i].second] = ans;
	}
	for(int i = 0;i<q;i++)
	{
		printf("%lld ",d[i]);
	}
	printf("\n");
	return 0;
}