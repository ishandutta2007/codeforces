#include<bits/stdc++.h>
using namespace std;
int a[200014];
int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort (a,a+n);
	int pre = 0;
	int ato = k-1; 
	int ans = 0;
	while(ato<n&&pre<=n-k)
	{
		if (a[pre]==-1) {pre++;continue;}
		if (a[ato]-a[pre]<m) 
		{
			ans ++;
			a[ato] = -1;
			ato ++;
		}
		else
		{
			ato ++;
			pre ++;
		}
	}
	printf("%d\n",ans);
	return 0;
}