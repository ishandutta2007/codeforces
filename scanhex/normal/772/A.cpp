#include <bits/stdc++.h>

using namespace std;
typedef long long nagai;

int main()
{
	int n, p;
	scanf("%d %d", &n, &p);
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &a[i], &b[i]);
	nagai sum = 0;
	for (int x : a)
		sum += x;
	if (sum <= p)
	{
		cout << -1 << endl;
		return 0;
	}
	double L = 0, R = 1000000000000.0;
	for (int i = 0; i < 100; ++i)
	{
		double M = (L + R) / 2;
		double ext = 0;
		for (int j = 0; j < n; ++j)
			if (a[j] * M > b[j])
				ext += M * a[j] - b[j];
		if (ext / p < M)
			L = M;
		else
			R = M;
	}
	cout.precision(15);
	cout << L << endl;
	
}