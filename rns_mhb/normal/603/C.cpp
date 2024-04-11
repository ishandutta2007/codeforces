#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;

int n, k, a[N];

int func(int x) {
	if (x <= 3) return x % 2;
	if (x % 2) return 0;
	if (x == 4) return 2;
	if (func(x / 2) == 1) return 2;
	else return 1;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", a + i);
	int ans = 0;
	if (k % 2) for (int i = 1; i <= n; i ++) ans ^= func(a[i]);
	else for (int i = 1; i <= n; i ++) {
		if (a[i] == 1) ans ^= 1;
		else if (a[i] == 2) ans ^= 2;
		else if (a[i] % 2 == 0) ans ^= 1;
	}
	if (ans) puts("Kevin");
	else puts("Nicky");
    return 0;
}