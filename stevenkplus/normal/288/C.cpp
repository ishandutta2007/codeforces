#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 1001000;
int N;

int ar[MAXN];
bool matched[MAXN];

int main() {
	scanf("%d", &N);
	ll sum = 0;

	for (int i = N; i > 0; --i) {
		if (!matched[i]) {
			int k = 1;
			while (k * 2 <= i) k *= 2;
			int up = i - k;
			int down = k - up - 1;
			matched[i] = true;
			matched[down] = true;
			ar[down] = i;
			ar[i] = down;
		}
	}

	for(int i = 0; i <= N; ++i) {
		sum += i ^ ar[i];
	}

	cout << sum << "\n";
	for(int i = 0; i <= N; ++i) {
		if (i) cout << " ";
		cout << ar[i];
	}

	cout << "\n";
	return 0;
}