#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;
#define M 100100
typedef long long ll;

int main() {
    int T;
    ll n;
    for (scanf("%d", &T); T--; ) {
        scanf("%I64d", &n);
        ll answer = n * (n+1) / 2;
        ll k = 1;
        while (k <= n) {
            answer -= k * 2;
            k *= 2;
        }
        printf("%I64d\n", answer);
    }
}