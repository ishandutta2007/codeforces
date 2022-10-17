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

/*
 * Returns the vector z[i] = the greatest length l
 * such that s[i, i+l) is identical to s[0, l).
 */
template<typename T> vi z_algorithm(const vector<T>& s) {
    int N = s.size();
    vi z(N);
    z[0] = N;

    for (int i = 1, l, r = -1; i < N; i++) {
        z[i] = r > i ? min(r - i, z[i - l]) : 0;
        while (i + z[i] < N && s[i + z[i]] == s[z[i]])
            z[i]++;
        if (i + z[i] > r)
            l = i, r = i + z[i];
    }
    return z;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<pair<vi, int>> adj(N);
    for (int e = 0; e < M; e++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].first.push_back((b - a + N) % N);
        adj[b-1].first.push_back((a - b + N) % N);
    }

    for (int i = 0; i < N; i++) {
        sort(all(adj[i].first));
        adj[i].second = i;
    }

    shuffle(all(adj), rng);
    sort(all(adj));

    vi seq(2 * N);
    for (int i = 0, t = 0; i < N; i++) {
        if (i && adj[i].first != adj[i-1].first)
            t++;
        seq[adj[i].second] = seq[adj[i].second + N] = t;
    }

    vi zs = z_algorithm(seq);
    for (int i = 1; i < N; i++) {
        if (zs[i] >= N) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}