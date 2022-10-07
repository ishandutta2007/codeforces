#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN = 2001000;

int ar[MAXN];
int N;

int main() {
	scanf("%d", &N);

	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}
	sort(ar, ar + N);

	int cur = N;
	int left = N;
	int scal = 1;
	ll sum = 0;
	for(int i = 0; i < N; ++i) {
		if (cur / left == 4) {
			cur = left;
			++scal;
		}
		sum += ll(scal) * ar[i];
		--left;
	}

	cout << sum << "\n";
	return 0;
}