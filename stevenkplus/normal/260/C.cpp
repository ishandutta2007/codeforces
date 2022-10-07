#include <iostream>

using namespace std;

typedef long long ll;

const ll inf = 1LL << 60;

const int MAXN = 100100;
int N;

ll ar[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	int x;
	cin >> N >> x;
	x--;
	ll m = inf;
	for(int i = 0; i < N; ++i) {
		cin >> ar[i];
		m = min(m, ar[i]);
	}
	for(int i = 0; i < N; ++i) {
		ar[i] -= m;
	}
	ll cnt = m * N;
	while (ar[x]) {
		ar[x]--;
		cnt++;
		x--;
		if (x < 0) x = N - 1;
	}
	ar[x] = cnt;
	for(int i = 0; i < N; ++i) {
		if (i) cout << " ";
		cout << ar[i];
	}
	cout << "\n";
	return 0;
}