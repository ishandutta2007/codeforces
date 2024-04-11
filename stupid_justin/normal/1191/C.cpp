#include<bits/stdc++.h>
#define N 100005
using namespace std;
long long n,m,k;
long long p[N],r[N],num[N],loc[N];
long long solve(long long x)
{
	return (x-1)/k;
}
signed main()
{
	cin>>n>>m>>k;
	for (long long i=1;i<=m;i++)
	{
		cin>>p[i];
		if (i==1)
		{
			r[i]=1;	
			num[i]=p[i];	
			loc[r[i]]=1;	
		}
		else
		{
			num[i]=p[i]+1-i;
//			cout<<num[i]+loc[r[i-1]]<<" "<<num[i-1]<<endl;
			if (solve(num[i]+loc[r[i-1]])==solve(num[i-1]))
			{
				r[i]=r[i-1];
				loc[r[i]]++;
			}
			else 
			{
				r[i]=r[i-1]+1;
				loc[r[i]]=1;
			}
		}	
	}
//	for (int i=1;i<=m;i++) printf("r[%d]=%d\n",i,r[i]);
	cout<<r[m]<<endl;
	return 0;
}