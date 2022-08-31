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
const std::vector<ModInt<Mod>> ModInt<Mod>::inv_tbl_ = create_inv_tbl_<Mod>(3000001);

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

typedef ModInt<1000000007> mint;

int N, Q;
mint fact[3030303], facti[3030303];

mint naive(int q) {
	mint ret = 0;
	for (int t = 1; t <= N; ++t) if (3 * t >= q) ret += fact[3 * t] * facti[3 * t - q] * facti[q];
	return ret;
}

mint ans[3030303];

mint comb(int a, int b) {
	if (0 <= b && b <= a) return fact[a] * facti[b] * facti[a - b];
	return 0;
}

void precalc() {
	mint zero = (N * 3 + 3) / 3, one = (N * 3 + 2) / 3, two = (N * 3 + 1) / 3;

	for (int i = 1; i <= 3 * N; ++i) {
		mint sum = comb(3 * N + 1, i + 1);
		mint oz = zero;  // new (one - zero)
		oz -= comb(3 * N + 1, i);
		// if (i % 3 == 1) oz += 1;

		mint to = one;  // new (two - one)
		// to -= comb(3 * N + 1, i);
		// if (i % 3 == 2) to += 1;

		// printf("%d %d %d\n", i, (int)oz, (int)to);
		mint zero2 = (sum - to - oz * 2) / 3;
		
		zero = zero2;
		one = zero + oz;
		two = one + to;

		ans[i] = zero;
	}
}

int main()
{
	scanf("%d%d", &N, &Q);
	fact[0] = facti[0] = 1;
	for (int i = 1; i <= 3 * N + 10; ++i) {
		fact[i] = fact[i - 1] * i;
		facti[i] = facti[i - 1] / i;
	}
	precalc();

	for (;Q--;) {
		int q;
		scanf("%d", &q);
		printf("%d\n", (int)ans[q]);
	}

	return 0;
}