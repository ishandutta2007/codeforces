#include<bits/stdc++.h>
using namespace std;
int T;
typedef long long LL;
LL N,M;
int main()
{
	scanf("%d",&T);
	int x1,x2,y1,y2;
	while(T--)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		N=y2-y1+1;M=x2-x1+1;
		printf("%lld\n",(N-1)*(M-1)+1);
	}
	return 0;
}