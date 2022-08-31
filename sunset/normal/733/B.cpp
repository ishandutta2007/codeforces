#include<bits/stdc++.h>

using namespace std;

int a[100010],b[100010];

int n;

int sa,sb;

int mx,used;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		sa+=a[i],sb+=b[i];
	}
	mx=abs(sa-sb);
	for(int i=1;i<=n;i++)
	{
		int tmp=abs((sa-a[i]+b[i])-(sb+a[i]-b[i]));
		if(tmp>mx)
		{
			mx=tmp;
			used=i;
		}
	}
	cout<<used;
}