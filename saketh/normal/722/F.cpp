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

bool emplace(vector<pair<int, int>> &inx, vi &primes, int value) {
    for (int p : primes) {
        if (inx[p].first > 0 && inx[p].second != value % p)
            return false;
    }

    for (int p : primes) {
        if (inx[p].first == 0) 
            inx[p].second = value % p;
        inx[p].first++;
    }
    return true;
}

void remove(vector<pair<int, int>> &inx, vi &primes, int value) {
    for (int p : primes) {
        inx[p].first--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vi sieve(M + 1);
    for (int p = 2; p <= M; p++) {
        if (sieve[p]) continue;
        for (int q = p; q <= M; q += p)
            sieve[q] = p;
    }

    vi len(N);
    vector<vector<pair<int, int>>> locs(M + 1);

    for (int i = 0; i < N; i++) {
        cin >> len[i];
        vi seq(len[i]);
        for (int j = 0; j < len[i]; j++) {
            cin >> seq[j];
            locs[seq[j]].emplace_back(i, j);
        }
    }

    vvi primes(N);
    for (int i = 0; i < N; i++) {

        for (int a = 1; a * a <= len[i]; a++) {
            if (len[i] % a == 0) {
                primes[i].push_back(a);
                primes[i].push_back(len[i] / a);
            }
        }
    }

    vector<pair<int, int>> inx(M + 1, { 0, 0} );

    for (int val = 1; val <= M; val++) {
        int ans = 0;
        deque<pair<int, int>> fam;

        for (auto app : locs[val]) {
            if (fam.size() > 0 && fam.back().first + 1 != app.first) {
                while (fam.size()) {
                    remove(inx, primes[fam.front().first], fam.front().second);
                    fam.pop_front();
                }
            }

            while (!emplace(inx, primes[app.first], app.second)) {
                remove(inx, primes[fam.front().first], fam.front().second);
                fam.pop_front();
            }

            fam.push_back(app);
            ans = max(ans, (int) fam.size());
        }

                while (fam.size()) {
                    remove(inx, primes[fam.front().first], fam.front().second);
                    fam.pop_front();
                }

        cout << ans << "\n";
    }

    return 0;
}