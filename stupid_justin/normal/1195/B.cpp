#include<bits/stdc++.h>
#define MID cout<<mid<<endl;return 0
using namespace std;
long long n,k;
int solve(long long x)
{
	long long tmp=(n-x)*(n-x+1)/2;
	tmp-=x;
	if (tmp==k) return 0;
	if (tmp>k) return 1;
	if (tmp<k) return -1;
}
int main()
{
	
	cin>>n>>k;
	long long l,r,mid;
	l=0;r=n;mid=(l+r)/2;
	while(l<r)
	{
		mid=(l+r)/2;
		if (solve(mid)==0) {cout<<mid<<endl;break;}else
		if (solve(mid+1)==0) 
		{
			mid++;
			cout<<mid<<endl;break;
		}else
		if (solve(mid-1)==0) 
		{
			mid--;
			cout<<mid<<endl;break;
		}else
		if (solve(mid)==1) 
			l=mid;
		else
		if (solve(mid)==-1)
			r=mid+1;
	}
	return 0;
}