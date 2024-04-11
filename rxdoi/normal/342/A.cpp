#include<cstdio>
#define Error {printf("-1\n");return 0;}
using namespace std;

int cnt[8],n,x;

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&x),cnt[x]++;
	if (cnt[1]^n/3) Error
	if (cnt[5]||cnt[7]) Error
	int c_124=cnt[4];
	int c_126=cnt[2]-c_124;if (c_126<0) Error
	int c_136=cnt[6]-c_126;if (c_136<0) Error
	if (cnt[3]^c_136) Error
	while (c_124--) puts("1 2 4");
	while (c_126--) puts("1 2 6");
	while (c_136--) puts("1 3 6");
}