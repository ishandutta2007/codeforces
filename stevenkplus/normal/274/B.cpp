#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i) 
typedef long long ll;
typedef pair<ll, ll> pii;

const int MAXN = 100100;

vector<int> conn[MAXN];
int ar[MAXN];

int N;
pii get(int cur, int par) {
	ll up = 0;
	ll down = 0;

	repi(i, conn[cur]) {
		int nxt = *i;
		if (nxt != par) {
			pii k = get(nxt, cur);
			up = max(up, k.first);
			down = max(down, k.second);
		}
	}
	ll sum = up - down + ar[cur];
	if (sum > 0) {
		down += sum;
	} else {
		up += -sum;
	}
	return pii(up, down);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		conn[a].push_back(b);
		conn[b].push_back(a);
	}

	for(int i = 1; i <= N; ++i) {
		scanf("%d", ar + i);
	}

	pii p = get(1, -1);
	ll ans = p.first + p.second;
	cout << ans << "\n";
	return 0;
}