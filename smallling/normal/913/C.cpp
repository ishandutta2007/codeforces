#include <bits/stdc++.h>

using namespace std;

long long a[31];

long long getans(int L, int n)
{
	if(!L)return 0;
	if((1 << n) <= L)return a[n] + getans(L - (1 << n), n - 1);
	return min(a[n], getans(L, n - 1));
}

int main()
{
	int n, L;
	scanf("%d%d", &n, &L);
	for(int i = 0; i < n; i++)
	{
		scanf("%I64d", &a[i]);
		if(i > 0)a[i] = min(a[i], a[i - 1] * 2);
	}
	for(int i = n - 1; i; i--)
		a[i - 1] = min(a[i - 1], a[i]);
	for(int i = n; i < 31; i++)
		a[i] = a[i - 1] * 2;
	cout << getans(L, 30) << endl;
}