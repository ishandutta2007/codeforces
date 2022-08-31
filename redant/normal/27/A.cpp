#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MXN 3005
#define SI ({int x;scanf("%d",&x);x;})

bool got[MXN];

int main()
{
	int n = SI, x, i;
	while(n--) got[SI]=true;
	for(i=1;;i++) if(!got[i]) break;
	printf("%d\n",i);	
	return 0;
}