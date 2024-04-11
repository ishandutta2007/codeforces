#include <bits/stdc++.h>
#define maxn 1005
#define ll long long
#define mod 998244353
using namespace std;
char inp[maxn];
int n[2] = {0, 0};
int main()
{
	scanf("%s", inp);
	for(int i = 0; i < strlen(inp); i++)
	{
		if(inp[i] == '0')
		{
			printf("%d %d\n", n[1] + 1, 4), 
			n[1] = (n[1] + 2) % 4;
		}
		else
			printf("%d %d\n", n[2] + 1, 1), 
			n[2] = (n[2] + 1) % 4;
	}
	return 0;
}