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

int query(int loc) {
    cout << "? " << loc + 1 << endl;
    int val;
    cin >> val;
    return val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    int v0 = query(0),
        vm = query(N/2);

    if ((vm - v0) % 2) {
        cout << "! -1\n";
        return 0;
    }

    if (v0 == vm) {
        cout << "! 1\n";
        return 0;
    }

    int lo = 1, hi = N/2 - 1;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        int va = query(mi),
            vb = query(mi + N/2);

        if (va == vb) {
            cout << "! " << mi + 1 << "\n";
            return 0;
        }

        if ((v0 < vm) ^ (va < vb)) {
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }

    assert(false);
    return 0;
}