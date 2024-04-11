#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50,Log=29;
int n,val=0,id;
int a[N],b[40];
int main()
{
	ios::sync_with_stdio(false);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) 
	{
		cin>>a[i];
		for(j=0;j<=Log;j++)
		{
			if(a[i]&(1<<j)) b[j]++;
		}
	}
	for(i=0;i<=Log;i++)
	{
		if(b[i]<=1) val|=(1<<i);
	}
	id=1;
	for(i=2;i<=n;i++)
	{
		if((a[i]&val)>(a[id]&val)) id=i;
	}
	printf("%d ",a[id]);
	for(i=1;i<=n;i++)
	{
		if(i!=id) printf("%d ",a[i]);
	}
	return 0;
}