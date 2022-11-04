#include <bits/stdc++.h>
using namespace std;

long long C(long long a) {
	long long b = a / 2;
	long long ret = 1;
	for(long long i = b + 1; i <= a; i ++) ret *= i;
	for(long long i = 1; i <= b; i ++) ret /= i;
	return ret;
}

long long P(long long a) {
	long long ret = 1;
	for(long long i = 1; i <= a; i ++) ret *= i;
	return ret;
}

int main() {
	long long N; cin >> N;
	long long ans = C(N) / 2 * P(N / 2 - 1) * P(N / 2 - 1);
	cout << ans << endl;
	
	return 0;
}