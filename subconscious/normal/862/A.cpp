#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n,x; scanf("%d%d",&n,&x);
	int c=0,f=0;
	while (n--){
		int t; scanf("%d",&t);
		if (t<x) c++;
		if (t==x) f=1;
	}
	printf("%d\n",x-c+f);
	return 0;
}