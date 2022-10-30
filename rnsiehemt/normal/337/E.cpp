#include <cstdio>
#include <algorithm>
#include <cmath>

typedef long long ll;

const int inf = 999999999;

int N;
ll a[10];
int pc[10]; // prime count
int cc[10]; // child count
int cur;
int ans = inf;

int primecount(ll i) {
    int c = 0;
    ll max = std::min(ll(sqrt(i))+2ll, i);
    for (ll d = 2ll; d < max; d++) {
        while ((i%d) == 0ll) {
            i /= d;
            c++;
        }
    }
    if (i != 1ll) c++;
    return c;
}

void solve(int i, bool mega) {
    if (i == 0) {
        cur += 2;
        solve(i+1, true);
        cur -= 2;

        cur++;
        solve(i+1, false);
        cur--;
    }
    else if (i == N) {
        int pcleft = 0;
        for (int j = 0; j < N; j++) {
            if (!(pc[j] == 1 && cc[j] == 0)) pcleft += pc[j];
        }
        ans = std::min(ans, cur + pcleft);
    }
    else {
        if (mega) {
            cur++;
            solve(i+1, mega);
            cur--;
        }

        for (int j = 0; j < i; j++) {
            if ((a[j] % a[i]) == 0) {
                a[j] /= a[i];
                pc[j] -= pc[i];
                cc[j]++;
                cur++;
                solve(i+1, mega);
                cur--;
                cc[j]--;
                pc[j] += pc[i];
                a[j] *= a[i];
            }
        }
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%I64d", &a[i]);

    std::sort(a, a+N);
    std::reverse(a, a+N);

    for (int i = 0; i < N; i++) pc[i] = primecount(a[i]);
    solve(0, false);
    
    printf("%d\n", ans);
}