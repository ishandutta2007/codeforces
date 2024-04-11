#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef long double LD;

const int N = int(1e5 + 5);

LL s[N], a[N];

LL sum(LL l, LL r) {
	r = min(r, LL(N - 1)); 
	return s[r] - s[l - 1];
}

int main() {
	int n;
	cin >> n;	

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);
	reverse(a, a + n);	

	s[0] = a[0];
	for (int i = 1; i < N; i++)
		s[i] = s[i - 1] + a[i];

	int q;
	cin >> q;

	LL res_1 = 0;
	for (int i = 1; i < n; i++) 
		res_1 += a[i] * i;		

	for (int i = 0; i < q; i++) 
    {
		int k;
		cin >> k;

		if (k == 1) 
        {
			cout << res_1 << " ";
			continue;
		}	

		LL res = 0, sz = 1;

		for (LL j = 1, t = 1; j < n; j += sz, t++) 
			sz *= k,  res += sum(j, j + sz - 1) * t;
		

		cout << res << " ";
	}
	cout << endl;

	return 0;
}