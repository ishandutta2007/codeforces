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

const int MOD = 1e9 + 7;
int sum(int a, int b) { return (a + b) % MOD; }
int diff(int a, int b) { return (a + MOD - b) % MOD; }
int prod(int a, int b) { return a * 1ll * b % MOD; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, K;
    cin >> N >> K;

    vi vals(N);
    for (int i = 0; i < N; i++)
        cin >> vals[i];

    priority_queue<pair<int, int>> pq;
    vi maxk(N, 0);
    for (int i = N - 1; i >= 0; i--) {
        pq.push({ vals[i], i });
        while (pq.top().second >= i + K)
            pq.pop();
        maxk[i] = pq.top().first;
    }

    K--;

    int fin = 0;

    vi res(K);
    vector<vector<pair<int, int>>> pf(K);
    for (int i = N - K - 1; i >= 0; i--) {
        int &ans = res[i % K];
        vector<pair<int, int>> &fam = pf[i % K];
        if (fam.empty()) {
            fam.emplace_back(INT_MAX, i+K);
        }
        int F = fam.size();
        while (fam[F-1].first <= maxk[i]) {
            ans = diff(ans, prod(fam[F-1].first,
                        (fam[F-2].second - fam[F-1].second) / K));
            fam.pop_back();
            F--;
        }
        ans = sum(ans, prod(maxk[i], (fam[F-1].second - i) / K));
        fam.emplace_back(maxk[i], i);
        fin = sum(fin, ans);

        /*cout << "At i=" << i << " family looks like ";
        for (auto e : fam) {
            cout << e.first << " " << e.second << ", ";
        }
        cout << endl;*/
    }

    cout << fin << endl;
    return 0;
}