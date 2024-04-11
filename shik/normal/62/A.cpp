// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int al,ar,bl,br;
	scanf("%d%d%d%d",&al,&ar,&bl,&br);
	if ( (bl>=ar-1 && bl<=(ar+1)*2) || (br>=al-1 && br<=(al+1)*2) ) puts("YES");
	else puts("NO");
	return 0;
}