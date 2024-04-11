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
typedef vector<bool> vb;

int MOD;
int sum(int a, int b) { return (a + b) % MOD; }
int prod(int a, int b) { return (a * 1ll * b) % MOD; }

int mpow(int b, int e) {
    if (e == 0) return 1;
    if (e & 1) return prod(b, mpow(b, e - 1));
    return mpow(prod(b, b), e/2);
}

int inv(int val) { return mpow(val, MOD - 2); }

// vals are sorted
int verify(vi &vals, int D) {
    vb used(vals.size());

    list<int> seq;
    seq.push_back(vals.front());
    used.front() = true;

    while (true) {
        int nxt = sum(seq.back(), D);
        auto it = lower_bound(all(vals), nxt);
        if (it != vals.end() && *it == nxt) {
            seq.push_back(nxt);
            used[it - vals.begin()] = true;
        } else break;
    }

    while (true) {
        int nxt = sum(seq.front(), MOD - D);
        auto it = lower_bound(all(vals), nxt);
        if (it != vals.end() && *it == nxt) {
            seq.push_front(nxt);
            used[it - vals.begin()] = true;
        } else break;
    }

    if (seq.size() != vals.size()) {
        cout << -1 << endl;
        exit(0);
    }
    return seq.front();
}

pair<int, int> solve(vi &vals) {
    assert(2 * vals.size() <= MOD);

    if (vals.empty()) {
        return { 0, 1 };
    }
    if (vals.size() == 1) {
        return { vals[0], 1 };
    }

    sort(all(vals));
    int D = vals[1] - vals[0];

    int K = 0;
    for (int i = 0; i < vals.size(); i++) {
        int succ = sum(vals[i], D);
        auto it = lower_bound(all(vals), succ);
        if (it != vals.end() && *it == succ)
            K++;
    }

    D = prod(D, inv(vals.size() - K));
    return { verify(vals, D), D };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> MOD >> N;

    vi vals(N);
    for (int i = 0; i < N; i++)
        cin >> vals[i];

    if (2 * N > MOD) {
        vb pres(MOD);
        for (int v : vals)
            pres[v] = true;

        vi complement;
        for (int i = 0; i < MOD; i++)
            if (!pres[i])
                complement.push_back(i);

        auto res = solve(complement);
        cout << sum(res.first, prod(res.second, (MOD - N))) << " " << res.second << endl;
    } else {
        auto res = solve(vals);
        cout << res.first << " " << res.second << endl;
    }

    return 0;
}