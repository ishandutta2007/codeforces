#include <iostream>
#include <cstdlib>
#include <cmath>

#define maxn 5100

using namespace std;

int n, m;
int sm[maxn];
double trash;
int ans[maxn];
int res = 0;

int main() {
	cin >> n >> m;
	ans[0] = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> sm[i] >> trash;
		ans[i] = 1;
		for (int j = 1; j < i; ++j)
			if (sm[i] >= sm[j])
				ans[i] = max(ans[i], ans[j] + 1);
		res = max(res, ans[i]);
	}
	cout << n - res << endl;
	return 0;
}