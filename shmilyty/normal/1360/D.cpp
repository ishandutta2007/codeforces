#include<bits/stdc++.h>
using namespace std;
int T,n,k;
int main() 
{
	scanf("%d",&T);
	while(T--) 
	{
		scanf("%d%d",&n,&k);
		int ma = 1;
		for(int i=sqrt(n);i>=1;i--) 
		{
			if(n%i!=0) 
				continue;
			int a=i,b=n/i;
			if(a<=k) 
				ma=max(ma,a);
			if(b<=k) 
				ma=max(ma,b);
		}
		printf("%d\n",n/ma);
	}
	return 0;
}