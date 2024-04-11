#include <bits/stdc++.h>
using namespace std;
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define N 2005
#define ll long long
#define pb push_back

ll aa[N], bb[N];
ll *a, *b;
vector <ll> v;
int n, m;
ll ans, sk, d, sa, sb;
ll A[3], B[3];
int as, bs;
ll x[N], y[N];

ll myfunc(ll k) {
	if (k < 0) return -k;
	return k;
}

void update1() {
    f1(i, 1, as) {
        int ps = lower_bound(b + 1, b + bs + 1, a[i] - d) - b;
        if (ps <= bs) {
			ll bns = sa - a[i] + b[ps] - sb;
            if (myfunc(bns) < ans) {
                ans = myfunc(bns);
                sk = 1;
                A[0] = a[i], B[0] = b[ps];
            }
        }
        ps --;
        if (ps > 0) {
            ll bns = sa - a[i] + b[ps] - sb;
            if (myfunc(bns) < ans) {
                ans = myfunc(bns);
                sk = 1;
                A[0] = a[i], B[0] = b[ps];
            }
        }
    }
    return;
}

vector <ll> VA, VB;

void update2() {
    f1(i, 1, as) f1(j, i + 1, as) VA.pb(a[i] + a[j]);
    f1(i, 1, bs) f1(j, i + 1, bs) VB.pb(b[i] + b[j]);
    sort(VA.begin(), VA.end());
    sort(VB.begin(), VB.end());
    f0(i, 0, VA.size()) {
        int ps = lower_bound(VB.begin(), VB.end(), VA[i] - d) - VB.begin();
        if (ps < VB.size()) {
            ll bns = sa - VA[i] + VB[ps] - sb;
            if (myfunc(bns) < ans) {
                ans = myfunc(bns);
                sk = 2;
                A[0] = VA[i], B[0] = VB[ps];
            }
        }
        ps --;
        if (ps >= 0) {
            ll bns = sa - VA[i] + VB[ps] - sb;
            if (myfunc(bns) < ans) {
                ans = myfunc(bns);
                sk = 2;
                A[0] = VA[i], B[0] = VB[ps];
            }
        }
    }
    return;
}

int main() {
    scanf("%d", &n);
    f1(i, 1, n) scanf("%I64d", &aa[i]), sa += aa[i];
    scanf("%d", &m);
    f1(i, 1, m) scanf("%I64d", &bb[i]), sb += bb[i];
    bool swp = 0;
    if (sa < sb) {
        swap(sa, sb);
        a = bb, b = aa;
        as = m, bs = n;
        swp = 1;
    }
    else {
        a = aa, b = bb;
        as = n, bs = m;
    }
    f1(i, 1, as) a[i] <<= 1;
    f1(i, 1, bs) b[i] <<= 1;
    f1(i, 1, as) x[i] = a[i];
    f1(i, 1, bs) y[i] = b[i];
    sort(a + 1, a + as + 1);
    sort(b + 1, b + bs + 1);
    sk = 0, ans = sa - sb; d = sa - sb;
    update1();
    update2();
    if (sk == 2) {
        bool flag = 0;
        f1(i, 1, as) {
			f1(j, i + 1, as) {
				if (x[i] + x[j] == A[0]) {
					A[0] = i, A[1] = j;
					flag = 1;
					break;
				}
			}
            if (flag) break;
        }
		flag = 0;
        f1(i, 1, bs) {
			f1(j, i + 1, bs) {
				if (y[i] + y[j] == B[0]) {
					B[0] = i, B[1] = j;
					flag = 1; break;
				}
			}
			if (flag) break;
        }
    }
    else if (sk == 1) {
        f1(i, 1, as) if (x[i] == A[0]) {
            A[0] = i;
            break;
        }
        f1(i, 1, bs) if (y[i] == B[0]) {
            B[0] = i;
            break;
        }
    }
    printf("%I64d\n%d\n", ans, sk);
    if (swp) f0(i, 0, sk) swap(A[i], B[i]);
	f0(i, 0, sk) printf("%I64d %I64d\n", A[i], B[i]); puts("");
}