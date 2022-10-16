#include <cstdio>

using namespace std;

const int N=1e5+5;

int T;

int n;
char s[N];
void solve()
{
	scanf("%s",s+1);
	int cur=0;
	for (int i=1;s[i];i++)
		if (s[i]=='0'&&s[i-1]!='0')
			cur++;
	if (cur==0)
	{
		printf("0\n");
		return;
	}
	if (cur==1)
	{
		printf("1\n");
		return;
	}
	printf("2\n");
}

int main()
{
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}