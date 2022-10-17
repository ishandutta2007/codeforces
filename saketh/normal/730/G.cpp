#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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

    vector<pair<ll, ll>> used;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;

        auto it = used.begin();
        while (it != used.end() && it->second <= a)
            it++;

        if (it != used.end() && it->first < a+b) {
            it = used.begin();

            if (it->first >= b+1) {
                cout << 1 << " " << b << "\n";
                used.insert(used.begin(), { 1, b+1 });
            } else {
                while (next(it) != used.end() && next(it)->first - it->second < b)
                    it++;
                cout << it->second << " " << it->second + b - 1 << "\n";
                used.insert(next(it), { it->second, it->second + b });
            }
        } else {
            cout << a << " " << a + b - 1 << "\n";
            used.insert(it, { a, a + b });
        }

        TRACE( for (auto p : used) {
            cout << "[" << p.first << ", " << p.second << ") ";
        }
        cout << endl; )
    }

    return 0;
}