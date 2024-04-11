///	Choe Kwang B

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct seg {
	pair <int, int> st, en;
	void operator = (const seg &b) {
		st = b.st; en = b.en;
		return;
	}
} A, B, C, p[5];

bool common(seg A, seg B) {
	return (A.st == B.st || A.st == B.en || A.en == B.st || A.en == B.en) ? 1 : 0;
}

pair <int, int> mid[2];

LL dist(pair <int, int> A, pair <int, int> B) {
	return 1ll * (A.first - B.first) * (A.first - B.first) + 1ll * (A.second - B.second) * (A.second - B.second);
}

bool inside(seg A, pair <int, int> p) {
	if (A.st == p || A.en == p) return 0;
	int x1 = A.st.first - p.first, x2 = p.first - A.en.first;
	int y1 = A.st.second - p.second, y2 = p.second - A.en.second;
	if (1ll * x1 * y2 != 1ll * x2 * y1) return 0;
	if (x1 == 0 && x2 != 0 || y1 == 0 && y2 != 0) return 0;
	if (dist(A.st, p) + dist(p, A.en) < dist(A.st, A.en)) return 1;
	return 0;
}

bool ok(seg A, pair <int, int> mid) {
	LL x = dist(A.st, mid), y = dist(mid, A.en);
	if (x > y) swap(x, y);
	if (x * 16 >= y) return 1;
	return 0;
}

bool deg (seg A, seg B) {
	if (inside(A, B.en) || inside(B, A.en) || A.en == B.en) return 0;
	LL x = dist(A.st, A.en), y = dist(B.st, B.en), z = dist(A.en, B.en);
	if (x + y < z) return 0;
	return 1;
}

int main() {
	int t; scanf("%d", &t);
	while (t --) {
		scanf("%d %d %d %d", &A.st.first, &A.st.second, &A.en.first, &A.en.second);
		scanf("%d %d %d %d", &B.st.first, &B.st.second, &B.en.first, &B.en.second);
		scanf("%d %d %d %d", &C.st.first, &C.st.second, &C.en.first, &C.en.second);

        if (A.st == A.en || B.st == B.en || C.st == C.en) {puts("NO"); continue;}

        if (common(A, C)) swap(B, C);
        else if (common(B, C)) swap(A, C);
        else if (!common(A, B)) {puts("NO"); continue;}

		if (A.st == B.en) swap(B.st, B.en);
		else if (A.en == B.st) swap(A.st, A.en);
		else if (A.en == B.en) swap(A.st, A.en), swap(B.st, B.en);
		p[0] = A, p[1] = B, p[2] = C;

		if (!deg(p[0], p[1])) {puts("NO"); continue;}

		if (inside(p[0], p[2].st) && inside(p[1], p[2].en)) {
			mid[0] = p[2].st; mid[1] = p[2].en;
		}
		else if (inside(p[0], p[2].en) && inside(p[1], p[2].st)) {
			mid[0] = p[2].en; mid[1] = p[2].st;
		}
		else {puts("NO"); continue;}

		if (ok(p[0], mid[0]) && ok(p[1], mid[1])) puts("YES");
		else puts("NO");
	}
	return 0;
}