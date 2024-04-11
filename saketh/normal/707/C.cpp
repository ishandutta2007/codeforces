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

// need a^2 - b^2 = V^2 for some a, b
// so (a + b) (a - b) = V^2
void try_leg(ll V) {
    vll fact;
    for (ll v = 1; v * v <= V; v++) {
        if (V % v == 0) {
            fact.push_back(v);
            if (V/v != v) fact.push_back(V/v);
        }
    }

    for (ll v : fact) {
        ll aminusb = v;
        ll aplusb = V * V / v;

        ll twoa = aplusb + aminusb;
        ll twob = aplusb - aminusb;

        if (twoa % 2 > 0 || twob % 2 > 0 || twob <= 0) 
            continue;

        cout << twob / 2 << " " << twoa / 2 << "\n";
        exit(0);
    }
}

void try_hypo(ll V) {

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    ll V;
    cin >> V;

    try_leg(V);
    try_hypo(V);

    cout << -1 << "\n";

    return 0;
}