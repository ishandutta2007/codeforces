#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 1 << 17;

int bestc = -1;
ll bestv = 0;
ll second = 0;

ll get(int x) {
	if (x == bestc) return second;
	return bestv;
}

void set(int x, ll val) {
	if (val > bestv) {
		if (x != bestc) {
			second = bestv;
		}
		bestv = val;
		bestc = x;
	} else if (val > second) {
		if (x != bestc) {
			second = val;
		}
	}
}

ll best[MAXN];
bool vis[MAXN];

int N, Q;
int v[MAXN];
int c[MAXN];

int A, B;

int main() {
	scanf("%d %d", &N, &Q);
	for(int i = 0; i < N; ++i) {
		scanf("%d", v + i);
	}
	for(int i = 0; i < N; ++i) {
		scanf("%d", c + i);
	}

	for(int i = 0; i < Q; ++i) {
		scanf("%d %d", &A, &B);
		for(int j = 0; j < MAXN; ++j) {
			vis[j] = false;
		}
		bestc = -1;
		bestv = 0;
		second = 0;

		ll ans = 0;
		for(int j = 0; j < N; ++j) {
			ll choice = B;
			choice *= v[j];
			choice += get(c[j]);
			if (vis[c[j]]) {
				ll oth = A;
				oth *= v[j];
				oth += best[c[j]];
				if (oth > choice) {
					choice = oth;
				}
			}

			set(c[j], choice);
			if (!vis[c[j]] || choice > best[c[j]]) {
				vis[c[j]] = true;
				best[c[j]] = choice;
			}

			if (choice > ans) ans = choice;
		}

		cout << ans << "\n";
	}


	return 0;
}