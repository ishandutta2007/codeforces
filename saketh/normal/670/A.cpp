#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int calc(int arg) {
    int last = arg % 7;
    return (arg / 7) * 2 + max(0, last - 5);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    // minimum possible days off
    cout << calc(N) << " ";

    // maximum
    if (N <= 2) {
        cout << N << "\n";
    } else {
        cout << 2 + calc(N - 2) << "\n";
    }

    return 0;
}