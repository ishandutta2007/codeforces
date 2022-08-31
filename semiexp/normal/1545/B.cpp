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
#define MOD 998244353
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


int TC;
int N;
char S[101010];
mint fact[101010], facti[101010];

int main()
{
	fact[0] = facti[0] = 1;
	for (int i = 1; i <= 100000; ++i) {
		fact[i] = fact[i - 1] * i;
		facti[i] = facti[i - 1] / i;
	}
	scanf("%d", &TC);
	for (;TC--;) {
		scanf("%d%s", &N, S);

		int p = 0;
		int ch = 0, r = 0;
		while (p < N) {
			if (p + 1 < N && S[p] == '1' && S[p + 1] == '1') {
				++ch;
				p += 2;
			} else if (S[p] == '1') {
				++r;
				++p;
			} else {
				++p;
			}
		}
		int a = N - ch - r, b = ch;
		mint ans = fact[a] * facti[b] * facti[a - b];
		printf("%d\n", (int)ans);
	}

	return 0;
}