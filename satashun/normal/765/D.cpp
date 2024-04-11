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

int n;
int f[100010];
int g[100010];
int h[100010];
int num;

int main() {
	cin >> n;

	rep(i, n) {
		cin >> f[i];
		--f[i];
		if (f[i] == i) {
			++num;
		}
	}

	if (num == 0) {
		puts("-1");
		return 0;
	}

	memset(g, -1, sizeof(g));
	memset(h, -1, sizeof(h));

	int now = 0;

	rep(i, n) {
		if (f[i] == i) {
			g[i] = now;
			h[now] = i;
			now++;
		}
	}

	rep(i, n) {
		if (f[i] != i) {
			if (f[f[i]] != f[i]) {
				puts("-1");
				return 0;
			}
			g[i] = g[f[i]];
		}
	}

	printf("%d\n", num);
	rep(i, n) printf("%d%c", g[i] + 1, i == n - 1 ? '\n' : ' ');
	rep(i, num) printf("%d%c", h[i] + 1, i == num - 1 ? '\n' : ' ');

	return 0;
}