#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		if(n&1)
		{
			for(int i=3;i*i<=n;i++)
				if(n%i==0)
				{
					n+=i;
					break;
				}
			if(n&1)
				n*=2;
			k--;
		}
		n+=k*2;
		cout<<n<<endl;
	}
	return 0;
}