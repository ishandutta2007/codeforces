#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

template <u32 Mod> class ModInt {
    using Self = ModInt<Mod>;
    static_assert(Mod <= std::numeric_limits<i32>::max());
public:
    ModInt(i64 value = 0) {
        if (value < 0) {
            value_ = (Mod - (-value % Mod)) % Mod;
        } else {
            value_ = value % Mod;
        }
    }

    ModInt(const Self& other) : value_(other.value_) {}

    operator i32() const {
        return value_;
    }

    operator i64() const {
        return value_;
    }

    Self operator+(const Self& other) const {
        Self res(*this);
        res += other;
        return res;
    }

    Self operator-(const Self& other) const {
        Self res(*this);
        res -= other;
        return res;
    }

    Self operator*(const Self& other) const {
        Self res(*this);
        res *= other;
        return res;
    }

    Self operator/(const Self& other) const {
        Self res(*this);
        res /= other;
        return res;
    }

    Self operator-() const {
        Self res(0);
        res -= *this;
        return res;
    }

    Self pow(i64 power) const {
        Self ret(1), p(*this);
        if (power < 0) {
            power *= -1;
            p = p.inv();
        }
        for (i64 i = 0; (1 << i) <= power; ++i) {
            if ((power >> i) & 1) ret *= p;
            p *= p;
        }
        return ret;
    }

    Self& operator+=(const Self& other) {
        value_ += other.value_;
        if (value_ >= Mod) value_ -= Mod;
        return *this;
    }

    Self& operator-=(const Self& other) {
        value_ += Mod - other.value_;
        if (value_ >= Mod) value_ -= Mod;
        return *this;
    }

    Self& operator*=(const Self& other) {
        value_ = (u32)(((u64)value_ * other.value_) % Mod);
        return *this;
    }

    Self& operator/=(const Self& other) {
        *this *= other.inv();
        return *this;
    }

    Self inv() const {
        if (value_ < inv_tbl_.size()) return inv_tbl_[value_];
		if (Mod - value_ < inv_tbl_.size()) return Mod - inv_tbl_[Mod - value_];
        else return pow(Mod - 2);
    }

private:
    u32 value_;
    static const std::vector<Self> inv_tbl_;
};

template <u32 Mod>
std::vector<ModInt<Mod>> create_inv_tbl_(u32 n) {
    std::vector<ModInt<Mod>> res;
    res.reserve(n + 1);
    res.push_back(0);
    res.push_back(1);
    for (u32 i = 2; i <= n; ++i) {
        // MOD / i == 0
        // MOD // i + (MOD % i) / i == 0
        // 1 / i == -(MOD // i) / (MOD % i)
        res.push_back(res[Mod % i] * ModInt<Mod>(Mod - (Mod / i)));
    }
    return res;
}

template <u32 Mod>
const std::vector<ModInt<Mod>> ModInt<Mod>::inv_tbl_ = create_inv_tbl_<Mod>(1000001);

template <class T, u32 Mod>
ModInt<Mod> operator+(T x, ModInt<Mod> y) {
    return ModInt<Mod>(x) + y;
}

template <class T, u32 Mod>
ModInt<Mod> operator-(T x, ModInt<Mod> y) {
    return ModInt<Mod>(x) - y;
}

template <class T, u32 Mod>
ModInt<Mod> operator*(T x, ModInt<Mod> y) {
    return ModInt<Mod>(x) * y;
}

template <class T, u32 Mod>
ModInt<Mod> operator/(T x, ModInt<Mod> y) {
    return ModInt<Mod>(x) / y;
}

template <class T, u32 Mod>
ModInt<Mod> operator+(ModInt<Mod> x, T y) {
    return x + ModInt<Mod>(y);
}

template <class T, u32 Mod>
ModInt<Mod> operator-(ModInt<Mod> x, T y) {
    return x - ModInt<Mod>(y);
}

template <class T, u32 Mod>
ModInt<Mod> operator*(ModInt<Mod> x, T y) {
    return x * ModInt<Mod>(y);
}

template <class T, u32 Mod>
ModInt<Mod> operator/(ModInt<Mod> x, T y) {
    return x / ModInt<Mod>(y);
}

typedef ModInt<998244353> mint;

int N, A[1010][505];
bool selected[1010];

int cnt[1010];

int uf[1010];

int root(int p) {
	return uf[p] < 0 ? p : (uf[p] = root(uf[p]));
}

bool join(int p, int q) {
	p = root(p);
	q = root(q);
	if (p == q) return false;
	uf[p] += uf[q];
	uf[q] = p;
	return true;
}

vector<int> graph[1010];
int col[1010];

void visit(int p, int c) {
	if (col[p] != -1) return;
	col[p] = c;
	for (int q : graph[p]) visit(q, c ^ 1);
}

bool share(int i, int j) {
	for (int k = 0; k < N; ++k) {
		if (A[i][k] == A[j][k]) return true;
	}
	return false;
}

bool ejected[1010];

int main()
{
	int TC;
	scanf("%d", &TC);
	for (;TC--;) {
		scanf("%d", &N);
		for (int i = 0; i < N * 2; ++i) {
			for (int j = 0; j < N; ++j) {
				scanf("%d", &(A[i][j]));
				--A[i][j];
			}
		}
		for (int i = 0; i < N * 2; ++i) selected[i] = ejected[i] = false;

		for (;;) {
			bool upd = false;
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) cnt[j] = -1;
				for (int j = 0; j < N * 2; ++j) {
					if (ejected[j]) continue;
					if (selected[j]) cnt[A[j][i]] = -2;
					int a = A[j][i];
					if (cnt[a] == -1) cnt[a] = j;
					else cnt[a] = -2;
				}
				for (int j = 0; j < N; ++j) {
					if (cnt[j] >= 0) {
						selected[cnt[j]] = true;
						upd = true;
						for (int k = 0; k < N * 2; ++k) {
							if (cnt[j] != k && share(cnt[j], k)) ejected[k] = true;
						}
					}
				}
			}
			if (!upd) break;
		}

		for (int i = 0; i < N * 2; ++i) uf[i] = -1;
		for (int i = 0; i < N * 2; ++i) graph[i].clear();

/*
		puts("eject");
		for (int i = 0; i < N * 2; ++i) if (selected[i]) {
			for (int j = 0; j < N; ++j) printf("%d ", A[i][j]);
			puts("");
		}
		puts("rem");
		for (int i = 0; i < N * 2; ++i) if (!selected[i]) {
			for (int j = 0; j < N; ++j) printf("%d ", A[i][j]);
			puts("");
		}
*/
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) cnt[j] = -1;
			for (int j = 0; j < N * 2; ++j) {
				if (ejected[j]) continue;
				if (selected[j]) {
					cnt[A[j][i]] = -3;
					continue;
				}
				int a = A[j][i];
				if (cnt[a] == -1) cnt[a] = j;
				else {
					if (cnt[a] == -3) continue;
					if (cnt[a] == -2) {
						printf("a %d %d %d\n", i, j, a);
						throw 5;
					}
					// printf("%d -- %d\n", cnt[a], j);
					// if (join(cnt[a], j)) --dim;
					graph[cnt[a]].push_back(j);
					graph[j].push_back(cnt[a]);
					cnt[a] = -2;
				}
			}
		}

		for (int i = 0; i < N * 2; ++i) col[i] = -1;
		mint ret = 1;
		for (int i = 0; i < N * 2; ++i) {
			if (!ejected[i] && col[i] == -1 && !selected[i]) {
				visit(i, 0);
				ret *= 2;
			}
		}
		printf("%d\n", (int)ret);
		
		vector<int> seq;
		for (int i = 0; i < N * 2; ++i) if (selected[i] || col[i] == 0) seq.push_back(i);
		for (int i = 0; i < N; ++i) printf("%d%c", seq[i] + 1, i == N - 1 ? '\n' : ' ');
	}
	return 0;
}