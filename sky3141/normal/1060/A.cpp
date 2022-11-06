#include <cstdio>
#include <algorithm>

typedef long long LL;

using namespace std;

const int MAXN = 100 + 9;

int n;
char str[MAXN];
int cnt;

int main()
{
	scanf("%d", &n);
	scanf("%s", str);
	for(int i=0; i<n; ++i)
	{
		if(str[i] == '8') ++cnt;
	}
	printf("%d", min(n / 11, cnt));
	
	return 0;
}