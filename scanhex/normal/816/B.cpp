#include <bits/stdc++.h>

using namespace std;

const int MX = 200001;

int main()
{
	int n, k, q;
	scanf("%d %d %d", &n, &k, &q);
	vector<int> v(MX);
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		--a;
		++v[a];
		--v[b];
	}
	vector<int> v1(MX);
	v1[0] = v[0];
	for (int i = 0; i < MX - 1; ++i)
		v1[i + 1] = v1[i] + v[i + 1];
	vector<int> v2(MX + 1);
	for (int i = 0; i < MX; ++i)
		v2[i + 1] = v2[i] + int(v1[i] >= k);
	for (int i = 0; i < q; ++i)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		--l;
		cout << v2[r] - v2[l] << '\n';
	}
}