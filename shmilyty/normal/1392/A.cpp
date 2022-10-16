#include<bits/stdc++.h>
using namespace std;
int t,n,fir,a,flag;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&fir);
		flag=0;
		for(int i=1;i<n;i++)
		{
			scanf("%d",&a);
			if(a!=fir)
				flag=1;
		}
		if(flag)
			puts("1");
		else
			cout<<n<<endl;
	}	
	return 0;
}