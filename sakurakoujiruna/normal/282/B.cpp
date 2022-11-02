#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	//cin >> n;
	scanf("%d", &n);
	int sum = 0;
	while(n --)
	{
		int a, g;
		//cin >> a >> g;
		scanf("%d%d", &a, &g);
		if(sum + a <= 500)
		{
			sum += a;
			//cout << 'A';
			putchar('A');
		}
		else
		{
			sum -= g;
			//cout << 'G';
			putchar('G');
		}
	}
	//cout << '\n';
	puts("");
	return 0;
}