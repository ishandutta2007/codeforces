#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    ll A, B, M;
    cin >> A >> B >> M;

    ll a_copies = 1;
    vll coeffs = {};
    ll csum = 0;
    for (int l = 1; l <= 50; l++) {
        if (l >= 3) a_copies *= 2;
        if (l >= 4) {
            coeffs.push_back(2 * coeffs.back());
            csum += coeffs.back();
        } else if (l > 1) {
            coeffs.push_back(1);
            csum++;
        }

        if (A * a_copies + csum > B) break;
        if (A * a_copies + csum * M >= B) {
            ll need = B - A * a_copies - csum;

            reverse(all(coeffs));
            vll add(coeffs.size());
            for (int i = 0; i < coeffs.size(); i++) {
                add[i] = 1 + min(M - 1, need / coeffs[i]);
                need -= (add[i] - 1) * coeffs[i];
            }

            assert(need == 0);
            assert(add.size() + 1 == l);

            vll seq(l);
            seq[0] = A;
            ll psum = A;
            cout << l << " " << A;
            for (int i = 1; i < l; i++) {
                assert(add[i-1] >= 1);
                assert(add[i-1] <= M);

                seq[i] = psum + add[i-1];
                cout << " " << seq[i];
                psum += seq[i];
            }
            cout << "\n";

            assert(seq.back() == B);
            return;
        }
    }

    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        solve();
    }

    return 0;
}