#include <cstdio>
#include <cmath>

using namespace std;

#define maxn 5001000

int n, x;
int fact[100];

int gcd(int a, int b) {
    while (b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int powmod(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = int(res * 1LL * a % p);
        }
        b >>= 1, a = int(a * 1LL * a % p);
    }
    return res;
}

bool is_prime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int phxi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int primitive_root(int p) {
    int cnt = 0;
    int phi = phxi(p), n = phi;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            fact[cnt++] = i;
            while (n % i == 0) n /= i;
        }
    if (n > 1) fact[cnt++] = n;
    for (int res = 1; res < p; ++res) {
        bool ok = true;
        if (gcd(res, p) != 1) continue;
        for (int i = 0; i < cnt && ok; ++i)
            ok = (powmod(res, phi / fact[i], p) != 1);
        if (ok) return res;
    }
    return -1;
}

int main() {
    scanf("%d%d", &n, &x);
    x--;
    if (n == 1) {
        if (x != 1) printf("%d\n", x);
        else puts("-1");
        return 0;
    }
    if (!is_prime(n + 1)) {
        puts("-1");
        return 0;
    }
    int root = primitive_root(n + 1);
    if (root == -1) {
        puts("-1");
        return 0;
    }
    int res = -1;
    for (int st = 1, v = 1; st <= n; ++st) {
        v = (v * 1LL * root) % (n + 1);
        if (gcd(st, n) == 1) {
            int val = x - x % (n + 1) + v;
            if (val > x) val -= n + 1;
            if (val > 1 && val > res) res = val;
        }
    }
    printf("%d\n", res);
    return 0;
}