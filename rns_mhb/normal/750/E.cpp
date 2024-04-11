#include <bits/stdc++.h>
using namespace std;
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
template <class T> void chkmin(T &a, T b) {if (a > b) a = b;}

const int inf = 0x3f3f3f3f;

#define N 200005

int n, q;
char s[N];

struct mat {
    int t[5][5];
    mat () {
		f0(i, 0, 5) f0(j, 0, 5) t[i][j] = inf;
    }
    void print() {
        f0(i, 0, 5) {
            f0(j, 0, 5) printf("%d ", t[i][j]);
            puts("");
        }
        return;
    }
} A[N<<2];

void jota(mat &A, mat &B, mat &C) {
    f0(i, 0, 5) f0(j, i, 5) f1(k, i, j) chkmin(C.t[i][j], A.t[i][k]+B.t[k][j]);
    return;
}

void build(int L, int R, int seg) {
    if (L == R) {
        f0(i, 0, 5) A[seg].t[i][i] = 0;
        switch (s[L]) {
		case '2' :
            A[seg].t[0][0] = 1, A[seg].t[0][1] = 0; break;
		case '0' :
            A[seg].t[1][1] = 1, A[seg].t[1][2] = 0; break;
		case '1' :
            A[seg].t[2][2] = 1, A[seg].t[2][3] = 0; break;
		case '7' :
			A[seg].t[3][3] = 1, A[seg].t[3][4] = 0; break;
		case '6' :
            A[seg].t[4][4] = 1, A[seg].t[3][3] = 1; break;
		default : break;
        }
        return;
    }
    int mid = L + R >> 1;
    build(L, mid, seg << 1);
    build(mid+1, R, seg << 1 | 1);
    jota(A[seg<<1], A[seg<<1|1], A[seg]);
    return;
}

mat query(int l, int r, int L, int R, int seg) {
    if (l <= L && R <= r) return A[seg];
    int mid = L + R >> 1;
    mat res;
    if (r <= mid) return query(l, r, L, mid, seg << 1);
    if (mid < l) return query(l, r, mid + 1, R, seg << 1 | 1);
    mat Ll = query(l, r, L, mid, seg << 1);
    mat Rr = query(l, r, mid + 1, R, seg << 1 | 1);
    jota(Ll, Rr, res);
    return res;
}

int main() {
	scanf("%d %d", &n, &q);
    scanf("%s", s+1);
    build(1, n, 1);
    mat res; int ans, x, y;
    while (q --) {
		scanf("%d %d", &x, &y);
        res = query(x, y, 1, n, 1);
        ans = res.t[0][4];
        if (ans > inf - 10) ans = -1;
        printf("%d\n", ans);
    }
	return 0;
}