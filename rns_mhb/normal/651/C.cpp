#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
#define f1(i, a, b) for (int i = a; i <= b; i ++)

typedef pair <int, int> pii;

#define N 200005

int n;

map <int, int> hx, hy;
map <pii, int> h;
ll ans;
int x[N], y[N];

int main() {
	scanf("%d", &n);
	f1(i, 1, n) {
		scanf("%d %d", &x[i], &y[i]);
        hx[x[i]] ++; hy[y[i]] ++;
        h[pii(x[i], y[i])] ++;
	}
	int z;
    for (auto x : hx) {
		z = x.y;
        ans += 1ll * z * (z - 1) / 2;
    }
    for (auto x : hy) {
		z = x.y;
		ans += 1ll * z * (z - 1) / 2;
    }
    for (auto x : h) {
		z = x.y;
		ans -= 1ll * z * (z - 1) / 2;
    }
    printf("%I64d\n", ans);
	return 0;
}