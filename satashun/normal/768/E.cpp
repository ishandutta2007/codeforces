#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

map<ll, int> mem[70];

int gr(int x, ll mask)
{
	if (x == 0) return x;
	if (mem[x].count(mask)) {
		return mem[x][mask];
	}

	bool u[20] = {false};
	for (int i = 1; i <= x; ++i) {
		if ((mask >> i) & 1) {
			continue;
		}
		u[gr(x - i, mask | (1LL << i))] = 1;
	}

	for (int i = 0; ; ++i) {
		if (!u[i]) {
			return mem[x][mask] = i;
		}
	}
}

int num[70];

int main() {
	int n;
	scanf("%d", &n);

	rep(i, n) {
		int x;
		scanf("%d", &x);
		num[x]++;
	}

	int xo = 0;
	for (int i = 1; i <= 60; ++i) {
		int g = gr(i, 0);
		if (num[i] & 1) xo ^= g;
	}

	puts(xo ? "NO" : "YES");

	return 0;
}