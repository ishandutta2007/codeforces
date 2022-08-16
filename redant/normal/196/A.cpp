#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MX 100005

char s[MX], ans[MX];

int main()
{
	scanf("%s",s);
	int n = strlen(s);
	int m = 0;
	ans[0] = s[n-1];
	for(int i=n-2;i>=0;i--)
		if(s[i]>=ans[m]) ans[++m] = s[i];
	for(int i=m;i>=0;i--) printf("%c",ans[i]);
	puts("");
	return 0;
}