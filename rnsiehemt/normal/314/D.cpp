#include <cstdio>
#include <algorithm>

typedef long long ll;

const ll inf = 999999999999999ll;

struct P {
    ll a, b;
    bool operator<(const P &p) const {
        return a < p.a;
    }
};

int N;
P p[100005];
ll maxto[100005];
ll maxfrom[100005];
ll minto[100005];
ll minfrom[100005];

bool valid(ll d) {
    int s = 1, e = 1;
    while (s <= N) {
        while (e <= N && p[e].a - p[s].a <= d) e++;
        if (std::max(maxto[s-1], maxfrom[e]) -
            std::min(minto[s-1], minfrom[e]) <= d)
        {
            return true;
        }
        s++;
    }
    /* else */return false;
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        ll x, y; scanf("%I64d%I64d", &x, &y);
        p[i].a = x+y; p[i].b = x-y;
    }

    std::sort(p+1, p+N+1);

    maxto[0] = -inf; for (int i = 1; i <= N; i++) maxto[i] = std::max(maxto[i-1], p[i].b);
    minto[0] = inf; for (int i = 1; i <= N; i++) minto[i] = std::min(minto[i-1], p[i].b);
    maxfrom[N+1] = -inf; for (int i = N; i >= 1; i--) maxfrom[i] = std::max(maxfrom[i+1], p[i].b);
    minfrom[N+1] = inf; for (int i = N; i >= 1; i--) minfrom[i] = std::min(minfrom[i+1], p[i].b);

    ll lo = -1ll, hi = 2000000000ll;
    while (hi-lo > 1ll) {
        ll mid = (lo+hi)/2ll;
        if (valid(mid)) hi = mid;
        else lo = mid;
    }

    printf("%.7lf", double(hi)/2.0);
}