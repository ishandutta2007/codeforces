#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define pb push_back
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f0(i, a, b) for (int i = a; i < b; i ++)
const int inf = 0x3f3f3f3f;

int a[N], jd[N], id[N], l[N], r[N], ans[N], n;

bool cmp(int x, int y) {
	return l[x] < l[y];
}
bool cmp1(int x, int y) {
	return a[x] < a[y];
}
struct fen {
    int a[N], _n;
    void init(int _n) {
		n = _n;
        return;
    }
    int calc(int pos) {
		int res = 0;
		for ( ; pos <= n; pos += pos & -pos) res += a[pos];
        return res;
    }
	void update(int pos) {for ( ; pos; pos -= pos & -pos) a[pos] ++;}
} A;

int main() {
    scanf("%d", &n);
    f1(i, 1, n) scanf("%d %d", &l[i], &r[i]), id[i] = i;
    sort(id + 1, id + n + 1, cmp);
    f1(i, 1, n) a[i] = r[id[i]], jd[i] = i;
    sort(jd + 1, jd + n + 1, cmp1);
    A.init(n);
    f1(i, 1, n) {
        ans[jd[i]] = A.calc(jd[i]);
        A.update(jd[i]);
    }
    f1(i, 1, n) l[id[i]] = ans[i];
    f1(i, 1, n) printf("%d\n", l[i]);
    return 0;
}