#include<cstdio>
using namespace std;

int n,x,y,k;

int main()
{
	scanf("%d%d",&n,&x);
	while (n--) scanf("%d",&y),k+=y;
	if (k<0) k=-k;
	printf("%d\n",k/x+(k%x!=0));
}