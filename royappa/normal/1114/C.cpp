// testing the tutorial solution provided
#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

long long n, b;

void Input() {
	cin >> n >> b;
}

void Solve() {
	long long ans = 1000000000000000000LL;
	for (long long i=2; i<=b; i++) {
		if (1LL * i * i > b) i = b;
		int cnt = 0;
		while (b % i == 0) {b /= i; cnt++;}
		if (cnt == 0) continue;
		long long tmp = 0, mul = 1;
		while (mul <= n / i) {mul *= i; tmp += n / mul;}
		ans = min(ans, tmp / cnt);
	}
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}