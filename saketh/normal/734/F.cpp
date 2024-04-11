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

void fail() {
    cout << -1 << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;
    vll b(N), c(N);

    for (int i = 0; i < N; i++)
        cin >> b[i];

    for (int i = 0; i < N; i++)
        cin >> c[i];

    vll s(N);
    ll sum = 0;

    for (int i = 0; i < N; i++) {
        s[i] = b[i] + c[i];
        sum += s[i];
    }

    if (sum % (2 * N))
        fail();
    sum /= 2 * N;

    vll a(N);
    for (int i = 0; i < N; i++) {
        if ((s[i] - sum) % N) fail();
        a[i] = (s[i] - sum) / N;
    }

    // now check if a works

    vll ct(32);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 32; j++)
            if ((a[i] >> j) & 1)
                ct[j]++;
    }

    for (int i = 0; i < N; i++) {
        ll and_res = 0, or_res = 0;
        for (int j = 0; j < 32; j++) {
            if ((a[i] >> j) & 1) {
                and_res += ct[j] << j;
                or_res += (N * 1ll) << j;
            } else {
                and_res += 0;
                or_res += ct[j] << j;
            }
        }

        if (and_res != b[i]) fail();
        if (or_res != c[i]) fail();
    }

    for (ll v : a)
        cout << v << " ";
    cout << endl;
    return 0;
}