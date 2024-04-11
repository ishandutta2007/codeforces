#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    const int MAXN = 1e5 + 100;
    vi sieve(MAXN);

    for (int p = 2; p < MAXN; p++) {
        if (sieve[p]) continue;
        for (int q = p; q < MAXN; q += p)
            sieve[q] = p;
    }

    int N;
    cin >> N;

    bool non_prime = false;
    for (int v = 2; v <= N + 1; v++)
        if (sieve[v] != v)
            non_prime = true;

    cout << (non_prime ? 2 : 1) << "\n";
    for (int v = 2; v <= N + 1; v++) {
        if (sieve[v] == v) cout << 1 << " ";
        else cout << 2 << " ";
    }
    cout << endl;

    return 0;
}