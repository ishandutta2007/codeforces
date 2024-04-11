#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n,S=1;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)S+=(i*2-2)*6;
	printf("%d\n",S);
	return 0;
}