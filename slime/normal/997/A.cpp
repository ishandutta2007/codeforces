#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 300005
#define ll long long
#define mod 1000000007 
using namespace std;
char inp[maxn];
int cnt;
ll ans;
int x, y;
int main()
{
	int n;
	scanf("%d%d%d", &n, &x, &y);
	scanf("%s", inp);
	int l = strlen(inp);
	for(int i = 0; i < l; )
	{
		if(inp[i] == '1')
		{
			i++;
			continue;
		}
		int j = i;
		while(j < l && inp[j] == '0') j++;
		cnt++;
		i = j;
	}
	if(cnt == 0) printf("0\n");
	else
	{
		ll ans = y + (cnt - 1) * (ll)min(x, y);
		printf("%lld\n", ans);
	}
	return 0;
}