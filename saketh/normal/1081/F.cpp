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

int get(int l, int r) {
    cout << "? " << l << " " << r << endl;
    cout.flush();

    int NT;
    cin >> NT;
    if (NT == -1) { assert(false); }
    return NT;
}

/*vector<int> seq;
int get_test(int l, int r) {
    l--, r--;
    if (rng()&1) {
        for (int i = 0; i <= r; i++)
            seq[i] = !seq[i];
    } else {
        for (int i = l; i < seq.size(); i++) {
            seq[i] = !seq[i];
        }
    }
    int NT = 0;
    for (int v : seq) NT += v;
    return NT;
}*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    /*string inp = "010000101010101001100101010101010101010100111";
    int N = inp.size(), T = 0;
    for (char c : inp) {
        seq.push_back(c - '0');
        T += seq.back();
    }*/

    auto parity = [](int i) { return abs(i)&1; };

    int N, T;
    cin >> N >> T;

    vi pref(N + 1);
    pref[0] = 0;
    pref[N] = T;

    for (int i = 1; i < N; i++) {
        int l, r;
        bool comp;
        int left, right;

        vector<array<int, 3>> cand = {
            { i,    i, false },
            { i-1,  i, false },
            { i+1,    N, true }
        };

        bool found = false;
        for (auto [lc, rc, compc] : cand) {
            l = lc, r = rc, comp = compc;
            left = r;
            right = N - l + 1;
            if (left < 0 || right < 0 || left > N || right > N)
                continue;
            if (parity(left) == parity(right))
                continue;
            found = true;
            break;
        }
        assert(found);

        bool flipL = false, flipR = false, done = false;
        while (!done || flipL || flipR) {
            int NT = get(l, r);

            if (parity(NT - T) == parity(left)) {
                if (!comp && !flipL && !flipR && !done) {
                    pref[i] = (left + T - NT) / 2;
                    done = true;
                }
                flipL = !flipL;
            } else {
                if (comp && !flipL && !flipR && !done) {
                    pref[i] = pref.back() - (right + T - NT) / 2;
                    done = true;
                }
                flipR = !flipR;
            }
            T = NT;

            /*cout << "Now T = " << NT << " and " << flipL << " " << flipR;
            if (done) cout << " we have discovered pref[i] = " << pref[i];
            cout << endl;*/
        }
    }

    cout << "! ";
    stringstream res;
    for (int i = 1; i <= N; i++) {
        res << char('0' + (pref[i] - pref[i-1]));
    }
    cout << res.str() << endl;
    cout.flush();

    return 0;
}