#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
ll fib[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	fib[0] = fib[1] = 1;
	for(int i = 2; i < MAXN; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
	int a, b;
	cin >> a >> b;
	cout << (2LL*(fib[a] + fib[b] - 1)) % MOD << '\n';
}