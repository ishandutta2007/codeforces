#include<bits/stdc++.h>
using namespace std;
int a[123456];
int b[123456];
priority_queue<int,vector<int>,greater<int> >pq;
int main()
{
	int n,k,m;
	scanf("%d %d %d",&n,&m,&k);
	int sum = n;
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i = 1;i<n;i++)
	{
		b[i-1] = a[i] - a[i-1] - 1;
	}
	sort(b,b+n-1);
	for(int i = 0;i<n-k;i++) sum += b[i];
	printf("%d\n",sum);
	return 0;
}