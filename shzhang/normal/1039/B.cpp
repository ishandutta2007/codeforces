#include <cstdio>
#include <random>
#include <cstdlib>
#include <chrono>

using namespace std;

#define ll long long

bool query(ll l, ll r)
{
    printf("%lld %lld\n", l, r);
    char s[5];
    fflush(stdout);
    scanf("%s", s);
    if (s[0] == 'Y') {
        if (l == r) exit(0);
        return true;
    } else if (s[0] == 'N') {
        return false;
    } else {
        exit(0);
    }
}

int main()
{
    ll n; int k;
    scanf("%lld%d", &n, &k);
    ll l = 1, r = n;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    while (1) {
        if ((r - l + 1) / 2 + 1 + 2 * k < (r - l + 1)) {
            ll mid = (l + r) / 2;
            if (query(l, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        } else {
            ll pos = l + rng() % (r - l + 1);
            query(pos, pos);
        }
        l -= k; r += k;
        if (l < 1) l = 1;
        if (r > n) r = n;
    }
}