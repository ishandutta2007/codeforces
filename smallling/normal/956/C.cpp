#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, a[N], b[N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	b[n + 1] = -0x3f3f3f3f;
	for(int i = n; i; i--)
		b[i] = max(b[i + 1], a[i] + 1 - i);
	int nowx = 0;
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(nowx < a[i] + 1)nowx = a[i] + 1;
		else if(nowx < b[i] + i)nowx++;
		ans += nowx - (a[i] + 1);
	}
	cout << ans << endl;
}