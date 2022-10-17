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

    ll N, X, Y;
    string str;
    cin >> N >> X >> Y >> str;

    int sections = 0;
    for (int i = 0; i < N; i++) {
        if (str[i] == '0' && (!i || str[i-1] == '1'))
            sections++;
    }

    if (!sections) {
        cout << 0 << endl;
    } else {
        cout << min(sections * Y, (sections - 1) * X + Y) << endl;
    }

    return 0;
}