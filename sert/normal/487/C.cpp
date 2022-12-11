#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 2e5 + 7;

bool p[N];

bool uo[N], uc[N];
ll n;

/*void go(ll len, ll ost) {
    if (len == n - 1) {
        for (int i = 0; i < n - 1; i++)
            cout << cur[i] << "\n";
        cout << n;
        exit(0);
    }
    for (ll i = 1; i < n; i++)
        if (!uc[i] && !uo[(ost * i) % n]) {
            cur[len] = i;
            if ((ost * i) % n == len + 1)
                go(len + 1, (ost * i) % n);
        }
}*/
ll step(ll a, ll st) {
    if (st == 0) return 1;
    if (st % 2)
        return (a * step(a, st - 1)) % n;
    ll q = step(a, st / 2);
    return (q * q) % n;
}

ll r;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    for (long long i = 2; i < N; i++)
        if (!p[i])
            for (long long j = i * i; j < N; j += i)
                p[j] = true;

    cin >> n;
    if (n == 1) {
        printf("YES\n1\n");
        return 0;
    }

    if (n == 4) {
        printf("YES\n1\n3\n2\n4\n");
        return 0;
    }

    if (p[n]) {
        //cerr << "mult\n";
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    ll cur = 1, oc;
    uo[1] = uc[1] = true;
    printf("1\n");

    //cerr << step(3ll, 2ll);

    for (ll i = 2; i < n; i++) {
        //cerr << cur << "\n";
        oc = step(i - 1, n - 2);
        cur = (oc * i) % n;
        //if (uo[cur]) exit(1);
        printf("%I64d\n", cur);
    }
    printf("%I64d\n", n);

    return 0;
}