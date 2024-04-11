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

    int N, A, B;
    cin >> N >> A >> B;

    if (A > B) swap(A, B);

    vi vals(N);
    for (int i = 0; i < N; i++)
        cin >> vals[i];

    sort(all(vals), greater<int>());

    double ans = 0;
    for (int i = 0; i < A + B; i++)
        if (i < A) ans += double(vals[i]) / A;
        else ans += double(vals[i]) / B;
    cout << ans << endl;

    return 0;
}