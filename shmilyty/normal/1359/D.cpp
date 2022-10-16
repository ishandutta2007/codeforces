/*
n=int(input());arr=list(map(int,input().split()));ans=0
for i in range(1,31):
    res=0
    for j in arr:
        res+=j
        if(j>i):res=0
        res=max(res,0);ans=max(ans,res-i)
print(ans)
*/
#include<bits/stdc++.h>
using namespace std;
int n,a[100001],ans,res;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=31;i++)
	{
		res=0;
		for(int j=1;j<=n;j++)
		{
			res+=a[j];
			if(a[j]>i)
				res=0;
			res=max(res,0);
			ans=max(ans,res-i);
		}
	}
	cout<<ans;
	return 0;
}