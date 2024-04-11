#include <iostream>

using namespace std;

typedef long long ll;

const ll MOD = 1 << 30;

ll add (ll a, ll b) {
	return (a + b) % MOD;
}

const int MAXN = 1100000;
int dd[MAXN];
int d(int k) {
	return dd[k];
}
void prec() {
	for(int a = 1; a < MAXN; ++a) {
		for(int b = a; b < MAXN; b += a) {
			dd[b]++;
		}
	}
}

int main() {
	prec();
	int A,B,C;
	ll sum = 0;
	cin >> A >> B >> C;
	for(int i = 1; i <= A; ++i) {
		for(int j = 1; j <= B; ++j) {
			for(int k = 1; k <= C; ++k) {
				sum = add(sum,d(i * j * k));
			}
		}
	}
	cout << sum << endl;
	return 0;
}