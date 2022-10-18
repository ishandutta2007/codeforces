#include<bits/stdc++.h>
using namespace std;
int a[111111];
int b[111111];
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	for(int i = 0;i<m;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	int xx = a[0],yy = b[0],ans = 0;
	int idx = 0,idy = 0;
	while(idx<m-1&&idy<n-1)
	{
		if (xx==yy)
		{
			ans++;
			xx+=a[++idx];yy+=b[++idy];
		}
		else if(xx<yy) xx+=a[++idx];
		else if(xx>yy) yy+=b[++idy];
	}
	printf("%d\n",ans+1); 
	return 0;
}