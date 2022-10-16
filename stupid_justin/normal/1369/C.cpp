#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],w[N];
bool cmp (int x,int y)
{
	return x>y;
}
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		for (int i=1;i<=n;i++)
		scanf("%lld",a+i);
		for (int i=1;i<=m;i++)
		scanf("%lld",w+i);
		sort(w+1,w+1+m);
		sort(a+1,a+1+n,cmp);
		long long ans=0;
		long long pos=1;
		for (int i=1;i<=m;i++)
		{
			ans+=a[pos];
			if (w[i]==1) ans+=a[pos];
			pos++;
			w[i]--;
		}
		for (int i=1;i<=m;i++)
		{
			if (w[i])
			{
				ans+=a[pos+w[i]-1];
				pos+=w[i];
			}
		}
		cout<<ans<<endl;
	}
		
	
}