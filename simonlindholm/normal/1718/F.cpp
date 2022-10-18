#pragma GCC target ("popcnt")
#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#include <immintrin.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a, x) for (auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// typedef bitset<50'003> bs;

const int BITS = (50'003 / 256 + 1) * 256;

struct bs {
	union {
		__m256i m256[BITS / 256];
		uint64_t m64[BITS / 64];
	} u;
	constexpr bs() : u{} {}
	int count(int bits = BITS) {
		int res = 0;
		rep(i,0,bits / 64)
			res += (int)__builtin_popcountll(u.m64[i]);
		rep(i,bits/64*64,bits)
			res += (*this)[i];
		return res;
	}
	void set(size_t index) {
		u.m64[index / 64] |= (1ULL << (index % 64));
	}
	bool operator[](size_t index) {
		return u.m64[index / 64] & (1ULL << (index % 64));
	}
};
bs operator|(const bs& a, const bs& b) {
	bs r;
	rep(i,0,BITS/256) r.u.m256[i] = a.u.m256[i] | b.u.m256[i];
	return r;
}
void operator|=(bs& a, const bs& b) {
	rep(i,0,BITS/256) a.u.m256[i] |= b.u.m256[i];
}
bs operator&(const bs& a, const bs& b) {
	bs r;
	rep(i,0,BITS/256) r.u.m256[i] = a.u.m256[i] & b.u.m256[i];
	return r;
}
void operator&=(bs& a, const bs& b) {
	rep(i,0,BITS/256) a.u.m256[i] &= b.u.m256[i];
}

struct Tree {
	typedef bs T;
	static constexpr T unit = bs();
	T f(T a, T b) { return a | b; }
	vector<T> s; int n;
	Tree(int n, vector<bs>& v) : s(move(v)), n(n) {
		for (int i = n-1; i >= 0; i--) {
			s[i] = s[i * 2] | s[i * 2 + 1];
		}
	}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = s[pos * 2] | s[pos * 2 + 1];
	}
	T query(int b, int e) { // query [b, e)
		T ret = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ret |= s[b++];
			if (e % 2) ret |= s[--e];
		}
		return ret;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M, C, Q;
	cin >> N >> M >> C >> Q;

	// bitsets[i] = numbers that share factor with i
	// odd num x at pos x/2+1, bit 0 = div by 2
	vector<bs> bitsets(M+1);
	vi prime(M+1, 1);
	rep(i,2,M+1) {
		if (prime[i]) {
			for (int j = i*2; j <= M; j += i)
				prime[j] = 0;
			bs b{};
			if (i == 2) b.set(0);
			else {
				for (int j = i; j <= C; j += i * 2)
					b.set(j / 2 + 1);
			}
			bitsets[i] = b;
		} else {
			bs b{};
			int a = i;
			for (int d = 2; d*d <= a; d++) {
				while (a % d == 0) {
					b |= bitsets[d];
					a /= d;
				}
			}
			if (a != 1) {
				b |= bitsets[a];
			}
			bitsets[i] = b;
		}
	}

	int CHUNK_SIZE = 11;

	vi A(N);
	int N2 = (N / CHUNK_SIZE + 1);
	vector<bs> aChunkBitsets(N2 * 2);
	rep(i,0,N) {
		int a;
		cin >> a;
		A[i] = a;
		aChunkBitsets[i / CHUNK_SIZE + N2] |= bitsets[a];
	}

	Tree st(N2, aChunkBitsets);

	rep(qi,0,Q) {
		int L, R;
		cin >> L >> R;
		L--;
		int Lhi = (L + CHUNK_SIZE-1) / CHUNK_SIZE;
		int Rlo = R / CHUNK_SIZE;
		bs b = st.query(Lhi, Rlo);
		Lhi *= CHUNK_SIZE;
		Rlo *= CHUNK_SIZE;
		Lhi = min(Lhi, R);
		Rlo = max(Lhi, Rlo);
		while (L < Lhi) b |= bitsets[A[L++]];
		while (Rlo < R) b |= bitsets[A[Rlo++]];
		int res = (int)b.count();
		if (b[0]) {
			res--;
			res += C/2;
		} else {
			int c = C;
			for (;;) {
				c /= 2;
				if (c < 1) break;
				res += (int)b.count((c - 1)/2 + 2);
			}
		}
		cout << C - res << '\n';
	}
	exit(0);
}