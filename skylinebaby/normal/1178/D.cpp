#include<bits/stdc++.h>
using namespace std;
int a[3000];
int main()
{
	int n;
	for(int i = 2;i<=3000;i++) for(int j = 2;j*j<=i;j++) if(i%j==0) a[i] = 1;
	scanf("%d",&n);
	int ans = n;
	for(int i = 0;i<=n/2;i++) 
	{
		if(!a[ans]) break;
		ans ++;
	}
	printf("%d\n",ans);
	for(int i = 1;i<n;i++) printf("%d %d\n",i,i+1);
	printf("%d 1\n",n);
	for(int i = n;i<ans;i++) printf("%d %d\n",i-n+1,i-n+1+n/2);
}