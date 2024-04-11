#include<bits/stdc++.h>
using namespace std;
int t,n,k,a[200001],f[200001];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		f[1]=1;
		for(int i=2;i<n;i++)
			if(a[i]>a[i-1]&&a[i]>a[i+1])
				f[i]=f[i-1]+1;
			else
				f[i]=f[i-1];
		f[n]=f[n-1];
		int cnt1=0,cnt2=0;
		for(int i=1;i+k-1<=n;i++)
			cnt1=max(cnt1,f[i+k-2]-f[i]);
		for(int i=1;i+k-1<=n;i++)
			if(f[i+k-2]-f[i]==cnt1)
			{
				cnt2=i;
				break;
			}
		cnt1++;
		cout<<cnt1<<" "<<cnt2<<endl;
	}
	return 0;
}