#include <bits/stdc++.h>
using namespace std;
#define f1(i, a, b) for (int i = a; i <= b; i ++)

#define N 200005

int n;
int x[N], y[N], type[N], sx, sy;
int xx[N], yy[N], mx[N], a[N<<2];
set <int> st[N];
set <int> :: iterator iter;

void update(int pos, int v, int L, int R, int seg) {
	if (L == R) {
        a[seg] = v;
        return;
	}
    int mid = L + R >> 1;
    if (pos <= mid) update(pos, v, L, mid, seg << 1);
    else update(pos, v, mid + 1, R, seg << 1 | 1);
    a[seg] = max(a[seg << 1], a[seg << 1 | 1]);
    return;
}

int query(int pos, int v, int L, int R, int seg) {
    if (a[seg] < v) return -1;
    if (L == R) return L;
    int mid = L + R >> 1, res = -1;
    if (pos <= mid) res = query(pos, v, L, mid, seg << 1);
    if (res < 0) res = query(pos, v, mid + 1, R, seg << 1 | 1);
    return res;
}

int main() {
    scanf("%d", &n);
    char s[10];
    f1(i, 1, n) {
		scanf("%s %d %d", s, &x[i], &y[i]);
        if (s[0] == 'a') type[i] = 1;
        else if (s[0] == 'r') type[i] = 2;
        else type[i] = 3;
        xx[i] = x[i], yy[i] = y[i];
    }
    sort(xx + 1, xx + n + 1);
    sort(yy + 1, yy + n + 1);
    sx = unique(xx + 1, xx + n + 1) - xx;
    sy = unique(yy + 1, yy + n + 1) - yy;
    f1(i, 1, n) {
		x[i] = lower_bound(xx + 1, xx + sx, x[i]) - xx;
        y[i] = lower_bound(yy + 1, yy + sy, y[i]) - yy;
    }
    f1(i, 1, n) {
        if (type[i] == 1) {
            st[x[i]].insert(y[i]);
            if (mx[x[i]] < y[i]) {
                mx[x[i]] = y[i];
                update(x[i], y[i], 1, sx - 1, 1);
            }
        }
        else if (type[i] == 2) {
            st[x[i]].erase(y[i]);
            if (mx[x[i]] == y[i]) {
                if (st[x[i]].empty()) mx[x[i]] = 0;
                else mx[x[i]] = *st[x[i]].rbegin();
                update(x[i], mx[x[i]], 1, sx - 1, 1);
            }
        }
        else {
            int ansx = -1, ansy = -1;
            if (x[i] < sx - 1) {
                int k = query(x[i] + 1, y[i] + 1, 1, sx - 1, 1);
				if (k > 0) {
                    iter = st[k].lower_bound(y[i] + 1);
					ansx = xx[k];
                    ansy = yy[*iter];
				}
            }
            if (ansx >= 0) printf("%d %d\n", ansx, ansy);
			else puts("-1");
        }
    }
	return 0;
}