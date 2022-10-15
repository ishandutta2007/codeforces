#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%lld: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

bool good(ll num)
{
    ll last = -1;
    for (ll i = 0; i <= 60; i++) {
        if (num & (1LL << i)) last = i;
    }
    for (ll i = 0; i < last; i++) {
        if ((num & (3LL << i)) == 0) return false;
    }
    return true;
}

ll pwr[25];

int opcnt = 0;
bool isxor[100005];
ll val1[100005], val2[100005];

ll Xor(ll x, ll y)
{
    opcnt++; isxor[opcnt] = true;
    val1[opcnt] = x;
    val2[opcnt] = y;
    return x ^ y;
}

ll Add(ll x, ll y)
{
    opcnt++;
    val1[opcnt] = x;
    val2[opcnt] = y;
    return x + y;
}

int work(ll a)
{
    //ll a; scanf("%lld", &a);
    Xor(a, a);
    ll mult = 0;
    for (ll i = 1; i <= 5000000; i += 2) {
        if ((a * i) % 4 == 3 && good(a * i)) {
            mult = i; break;
        }
    }
    //printf("!!! %lld\n", mult);
    pwr[0] = a;
    for (ll i = 1; i <= 20; i++) {
        pwr[i] = Add(pwr[i-1], pwr[i-1]);
    }
    ll cursum = 0;
    for (ll i = 0; i <= 20; i++) {
        if (mult & (1LL << i)) {
            cursum = Add(cursum, pwr[i]);
        }
    }
    //printf("!!! %lld %lld\n", cursum, a * mult);
    a = cursum;

    ll b = Add(a, a);
    ll c = Xor(a, b);
    ll d = Add(a, c);
    ll e = Add(a, b);
    ll f = Xor(d, e);
    ll two = Xor(a, f);
    //printf("!!! %lld\n", two);
    ll curv = two;
    for (int i = 1; i <= 60; i++) {
        if (a & (1LL << i)) {
            a = Xor(a, (1LL << i));
        }
        curv = Add(curv, curv);
    }
    /*if (a != 1) {
        printf("%lld\n", a); fflush(stdout);
        abort();
    }*/
    //printf("%lld\n", a);
    printf("%d\n", opcnt);
    for (int i = 1; i <= opcnt; i++) {
        printf("%lld %c %lld\n", val1[i], isxor[i] ? '^' : '+', val2[i]);
    }
    return 0;
}

int main()
{
    //for (ll i = 1; i <= 1000000; i += 2) {
    //    work(i);
    //}
    ll a; scanf("%lld", &a);
    work(a);
    return 0;
}