#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int a[N], b[N];
priority_queue<int> A;

int main()
{
	int n, k1, k2;
	scanf("%d%d%d", &n, &k1, &k2);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for(int i = 1; i <= n; i++)
		A.push(abs(b[i] - a[i]));
	int K = k1 + k2;
	while(K)
	{
		int o = A.top();
		A.pop();
		o--;
		o = abs(o);
		A.push(o);
		K--;
	}
	long long ans = 0;
	while(!A.empty())
	{
		int o = A.top();
		ans += 1ll * o * o;
		A.pop();
	}
	cout << ans << endl;
}