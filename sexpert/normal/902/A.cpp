#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, a, b, mpos = 0;
	scanf("%d %d", &n, &m);
	while(n--)
	{
		scanf("%d %d", &a, &b);
		if(a <= mpos) mpos = max(mpos, b);
		else
		{
			printf("NO");
			return 0;
		}
	}
	if(mpos >= m) printf("YES");
	else printf("NO");
	return 0;
}