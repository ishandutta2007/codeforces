#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define pw(x) (1LL<<x)
#define eprintf(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)

#define db(x) cerr << #x << " = " << x << '\n'
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"
#define db3(x, y, z) cerr << "( << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ", " << ")\n"
#define dbv(a) cerr << #a << " ="; for (auto xxxx: a) cerr << " " << xxxx; cerr << '\n'

typedef long long ll;
typedef double dbl;

int main() {
    int n;
    scanf("%d", &n);
    vector<ll> a(n);
    for (auto& i: a) scanf("%I64d", &i);
    if (n == 1) {
        cout << a[0];
        return 0;
    }
    vector<ll> sump(n), sums(n);
    for (int i = 0; i < n; ++i) {
        sump[i] = a[i];
        if (i >= 2) sump[i] += sump[i - 2];
    }
    for (int i = n - 1; i >= 0; --i) {
        sums[i] = a[i];
        if (i <= n - 3) sums[i] += sums[i + 2];
    }
    ll res = max(sump[n - 1], sump[n - 2]);
    for (int i = 0; i + 1 < n; ++i) {
        //db(sump[i]);
        //db(sums[i + 1]);
        res = max(res, sump[i] + sums[i + 1]);
    }
    printf("%I64d\n", res);
    return 0;
}