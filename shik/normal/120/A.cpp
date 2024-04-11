// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char s[100];
	int x;
	scanf("%s%d",s,&x);
	printf("%c\n","LR"[(s[0]=='f')^(x%2==1)]);
	return 0;
}