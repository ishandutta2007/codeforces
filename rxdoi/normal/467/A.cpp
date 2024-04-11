#include<cstdio>
using namespace std;

int n,x,y,cnt;

int main()
{
	scanf("%d",&n);
	while (n--) scanf("%d%d",&x,&y),cnt+=(y-x>=2);
	printf("%d\n",cnt);
}