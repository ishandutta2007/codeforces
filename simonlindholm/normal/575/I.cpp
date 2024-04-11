#pragma GCC target ("mmx,sse,sse2")
#include "xmmintrin.h"
#include <bits/stdc++.h>
using namespace std;

typedef __m128i mi;
#define M(x) _mm_##x##_si128
#define M16(x) _mm_##x##_epi16
#define M32(x) _mm_##x##_epi32

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Counter {
	int N;
	short *xs, *ys, *ups;
	Counter() : N(0) {
		xs = (short*)_mm_malloc(200000, 32);
		ys = (short*)_mm_malloc(200000, 32);
		ups = (short*)_mm_malloc(200000, 32);
	}
	void insert(short x, short y, short len) {
		xs[N] = x;
		ys[N] = y;
		ups[N] = (short)(x + y + len);
		N++;
	}
	int count(short x, short y) {
		mi mx = M16(set1)(x);
		mi my = M16(set1)(y);
		mi msum = M16(set1)((short)(x + y)), mres = M16(set1)(0);
		int i = 0;
		while (i + 16 <= N) {
			mres = M16(add)(mres, M(or)(
				M(or)(
					M16(cmplt)(my, *(mi*)&ys[i]),
					M16(cmplt)(mx, *(mi*)&xs[i])
				),
				M16(cmplt)(*(mi*)&ups[i], msum)
			));
			i += 8;
			mres = M16(add)(mres, M(or)(
				M(or)(
					M16(cmplt)(my, *(mi*)&ys[i]),
					M16(cmplt)(mx, *(mi*)&xs[i])
				),
				M16(cmplt)(*(mi*)&ups[i], msum)
			));
			i += 8;
		}

		int res = N;
		union { short v[8]; mi m;} u; u.m = mres;
		rep(i,0,8) res += u.v[i];

		while (i < N) {
			if (!(ys[i] <= y && xs[i] <= x && x + y <= ups[i]))
				res--;
			++i;
		}
		return res;
	}
};

int main() {
	cin.sync_with_stdio(false);
	int N, Q;
	cin >> N >> Q;
	Counter d1, d2, d3, d4;
	rep(qi,0,Q) {
		short type;
		cin >> type;
		if (type == 1) {
			short dir, x, y, len;
			cin >> dir >> x >> y >> len;
			if (dir == 1) d1.insert((short)x, (short)y, len);
			if (dir == 2) d2.insert((short)x, (short)-y, len);
			if (dir == 3) d3.insert((short)-x, (short)y, len);
			if (dir == 4) d4.insert((short)-x, (short)-y, len);
		}
		else {
			assert(type == 2);
			short x, y;
			cin >> x >> y;
			int ans = 0;
			ans += d1.count((short)x, (short)y);
			ans += d2.count((short)x, (short)-y);
			ans += d3.count((short)-x, (short)y);
			ans += d4.count((short)-x, (short)-y);
			cout << ans << '\n';
		}
	}
}