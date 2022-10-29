#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int a[105];

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		if(n&1)
		{
			printf("1 ");
			for(int i=2; i<=n; i+=2)
				printf("%d %d ",i+1,i);
		}
		else
			for(int i=1; i<=n; i+=2)
				printf("%d %d ",i+1,i);
		puts("");
	}
	return 0;
}