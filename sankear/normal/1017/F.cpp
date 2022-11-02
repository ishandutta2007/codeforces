#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <array>
#include <tuple>

using namespace std;

struct TNumber {
    unsigned int A = 0;
    unsigned int B = 0;
    
    TNumber() = default;
    
    TNumber(unsigned int a, unsigned int b)
        : A(a)
        , B(b)
    {
        
    }
    
    TNumber& operator+=(const TNumber& other) {
        A += other.A;
        B += other.B;
        if (B >= 6) {
            ++A;
            B -= 6;
        }
        return *this;
    }
};

const int N = 100000000 + 1;

unsigned int IsPrime[(N + 31) / 32];

inline void SetNotPrime(unsigned int n) {
    IsPrime[n >> 5] |= (1 << (n & 31));
}

inline void SetNotPrime(const TNumber& number) {
    if (number.B == 1) {
        SetNotPrime(number.A << 1);
    } else if (number.B == 5) {
        SetNotPrime((number.A << 1) | 1);
    }
}

bool CheckIsPrime(unsigned int n) {
    return (IsPrime[n >> 5] & (1 << (n & 31))) == 0;
}

bool CheckIsPrime(const TNumber& number) {
    if (number.B == 1) {
        return CheckIsPrime(number.A << 1);
    } else if (number.B == 5) {
        return CheckIsPrime((number.A << 1) | 1);
    } else {
        return false;
    }
}

int main() {
    //cerr << sizeof(IsPrime) / 1024 / 1024 << endl;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    unsigned int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    TNumber add(0, 1);
    TNumber current(0, 1);
    unsigned int ans = 0;
    for (unsigned int i = 2; i <= n; ++i) {
        current += add;
        if (i == 2 || i == 3 || CheckIsPrime(current)) {
            unsigned int step = a * i * i * i + b * i * i + c * i + d;
            unsigned int j = i;
            unsigned int pw = step;
            while (j <= n / i) {
                j *= i;
                pw += step;
            }
            unsigned int cnt = 0;
            while (j >= i) {
                unsigned int cur = (n / j) - cnt;
                ans += cur * pw;
                cnt += cur;
                j /= i;
                pw -= step;
            }

            if (i <= n / i) {
                j = i * i;
                TNumber current2(j / 6, j % 6);
                for (; j <= n; j += i, current2 += current) {
                    SetNotPrime(current2);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}