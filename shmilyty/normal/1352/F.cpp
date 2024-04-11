#include<bits/stdc++.h>
using namespace std;
int t,n1,n2,n3;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n1,&n2,&n3);
		if(n2==0)
		{
			if(n1)
				for(int i=1;i<=n1+1;i++)
					cout<<0;
			else
				for(int i=1;i<=n3+1;i++)
					cout<<1;
			cout<<endl;
			continue;
		}
		for(int i=1;i<=n1+1;i++)
			cout<<0;
		for(int i=1;i<=n3+1;i++)
			cout<<1;
		n2--;
		for(int i=1;i<=n2;i++)
			if(i&1)
				cout<<0;
			else
				cout<<1;
		cout<<endl;
	}
	return 0;
}