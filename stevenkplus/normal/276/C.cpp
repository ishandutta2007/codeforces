#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, Q;
const int MAXN = 200100;

int ar[MAXN];
int weight[MAXN];

int main() {
	scanf("%d %d", &N, &Q);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}
	for(int i = 0; i < Q; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a;
		++weight[a];
		--weight[b];
	}
	for(int i = 1; i < N; ++i) {
		weight[i] += weight[i - 1];
	}

	sort(ar, ar + N);
	sort(weight, weight + N);
	ll sum = 0;
	for(int i = 0; i < N; ++i) {
		sum += ll(ar[i]) * weight[i];
	}
	cout << sum << "\n";
}