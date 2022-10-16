#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[100001],flag[100001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		flag[a[i]]=1;
	}
	if(a[1]==1)
		flag[0]=1;
	for(int i=1;i<=n;i++)
		if(a[i]==a[i-1])
		{
			while(cnt<=n+1&&flag[cnt])
				cnt++;
			flag[cnt]=1;
			cout<<cnt<<" ";
		}
		else
			cout<<a[i-1]<<" ";
	return 0;
}