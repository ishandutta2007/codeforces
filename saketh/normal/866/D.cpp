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

    int N;
    cin >> N;

    ll money = 0;
    set<array<int, 3>> hist;

    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;

        bool sold = false;

        if (hist.size() > 0) {
            auto c = *hist.begin();
            if (c[0] < p) {
                sold = true;
                hist.erase(hist.begin());

                money += p - c[0];

                if (c[1] > 0) {
                    hist.insert({ c[0], c[1] - 1, c[2] });
                }
                hist.insert({ p, 1, i });
            } 
        }

        if (!sold) {
            hist.insert({ p, 0, i });
        }
    }

    cout << money << endl;
    return 0;
}