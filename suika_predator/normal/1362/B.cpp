#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int ok[1111],a[1111];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		memset(ok,0,sizeof(ok));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			ok[a[i]]=1;
		}
		int fl=0;
		for(int b=1;b<1024;b++)
		{
			int zz=1;
			for(int i=1;i<=n;i++)
			{
				if(!ok[a[i]^b])
				{
					zz=0;
					break;
				}
			}
			if(zz)
			{
				fl=1;
				cout<<b<<endl;
				break;
			}
		}
		if(!fl)cout<<-1<<endl;
	}
	return 0;
}