#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f3(i, a, b) for (int i = a; i >= b; i --)

#define N 300005
#define M 1000005

int n, m, a[N], d[M], p[M];
set <int> st;
set <int> :: iterator it;

ll b[N];

void update(int p, int v) {
    for ( ; p <= n; p += p & -p) b[p] += v;
    return;
}

ll calc(int p) {
	ll res = 0;
	for ( ; p; p -= p & -p) res += b[p];
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	f1(i, 2, 1000) if (!p[i]) for (int j = i * i; j < M; j += i) p[j] = i;
	d[1] = 1;
	f0(i, 2, M) {
        if (!p[i]) d[i] = 2;
        else {
            int k = i, t = 0;
            while (k % p[i] == 0) k /= p[i], t ++;
            d[i] = d[k] * (t + 1);
        }
	}
	f1(i, 1, n) {
		scanf("%d", &a[i]);
		if (a[i] > 2) st.insert(i);
	}
	st.insert(n+1);
    f1(i, 1, n) b[i] = b[i-1] + a[i];
    f3(i, n, 1) b[i] -= b[i-(i&-i)];
	int type, L, R;
    while (m --) {
        scanf("%d %d %d", &type, &L, &R);
        if (type == 1) {
            int now = L;
            while (1) {
				it = st.lower_bound(now);
                if (*it > R) break;
                update(*it, d[a[*it]] - a[*it]);
                a[*it] = d[a[*it]];
                now = (*it) + 1;
                if (a[*it] <= 2) st.erase(it);
            }
        }
        else {
            ll ans = calc(R) - calc(L - 1);
            printf("%I64d\n", ans);
        }
    }
	return 0;
}