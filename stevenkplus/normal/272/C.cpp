#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;
const int MAXN = 100100;
int ar[MAXN];

int N, M;
int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}

	scanf("%d", &M);
	ll prv = 0;
	for(int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		ll h = ar[a - 1];
		if (prv > h) {
			h = prv;
		}
		cout << h << "\n";
		prv = h + b;
	}
	return 0;
}