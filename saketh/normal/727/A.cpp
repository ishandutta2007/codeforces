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

bool go(vll &seq, ll targ) {
    if (seq.back() == targ) return true;
    if (seq.back() > targ) return false;

    seq.push_back(2 * seq.back());
    if (go(seq, targ))
        return true;
    seq.pop_back();

    seq.push_back(10 * seq.back() + 1);
    if (go(seq, targ))
        return true;
    seq.pop_back();

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    ll A, B;
    cin >> A >> B;

    vll seq({A});
    if (go(seq, B)) {
        cout << "YES" << "\n";
        cout << seq.size() << "\n";
        for (ll v : seq)
            cout << v << " ";
        cout << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}