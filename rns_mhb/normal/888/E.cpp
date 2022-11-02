#include <bits/stdc++.h>
using namespace std;
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define N 40
#define pb push_back
void chkmax(int &a, int b) {if (a < b) a = b;}

int a[N], b[40], n, m, ns;
vector <int> v[2];

void func(int k, int p) {
	if (!k) {
		v[ns].pb(p);
		return;
	}
    func(k-1, p);
    func(k-1, (p+b[k])%m);
}

int main() {
    scanf("%d %d", &n, &m);
    f1(i, 1, n) scanf("%d", &a[i]), a[i] %= m;
    if (n == 1) printf("%d\n", a[1]);
    else {
        int p = n / 2, ans = 0;
        f1(i, 1, p) b[i] = a[i];
        func(p, 0);
        ns ++;
        f1(i, p+1, n) b[i-p] = a[i];
        func(n-p, 0);
        f1(i, 0, 1) {
			sort(v[i].begin(), v[i].end());
            unique(v[i].begin(), v[i].end());
        }
        for (auto x : v[0]) {
            p = lower_bound(v[1].begin(), v[1].end(), m - x) - v[1].begin() - 1;
            chkmax(ans, x + v[1][p]);
        }
        printf("%d\n", ans);
    }
}