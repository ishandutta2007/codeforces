#include <cstdio>
#include <vector>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

vector<int> factors;

int go(int a, int b) {
    int m = -1;
    repi(i, factors) {
        if (*i >= a && *i <= b) {
            m = max(m, *i);
        }
    }
    return m;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int c = gcd(a, b);
    for(int i = 1; i * i <= c; ++i) {
        if (c % i == 0) {
            factors.push_back(i);
            factors.push_back(c / i);
        }
    }
    
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        int low, high;
        scanf("%d %d", &low, &high);
        int ans = go(low, high);
        printf("%d\n", ans);
    }
    return 0;
}