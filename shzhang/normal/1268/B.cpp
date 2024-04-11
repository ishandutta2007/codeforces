#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>

using namespace std;

int n;
#define ll long long

int main()
{
    scanf("%d", &n);
    ll white = 0;
    ll black = 0;
    for (int i = 1; i <= n; i++) {
        ll val;
        scanf("%lld", &val);
        if (i % 2 == 1) {
            white += val / 2LL;
            black += val - (val / 2LL);
        } else {
            black += val / 2LL;
            white += val - (val / 2LL);
        }
    }
    printf("%lld", min(black, white));
    return 0;
}