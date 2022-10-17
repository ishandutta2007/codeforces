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

void fail() { cout << -1 << endl; exit(0); }
void print(vector<pair<int, int>> &res) {
    for (auto p : res)
        cout << p.first << " " << p.second << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, T, K;
    cin >> N >> T >> K;

    vi layers(T), begin(T);
    begin[0] = 2;
    for (int i = 0; i < T; i++) {
        cin >> layers[i];
        if (i) begin[i] = begin[i-1] + layers[i-1];
    }

    vi mini(T), maxi(T);
    vi leaves(T);

    for (int i = 0; i < T - 1; i++) {
        mini[i] = max(0, layers[i] - layers[i+1]);
        maxi[i] = layers[i] - 1;

        leaves[i] = mini[i];
        K -= leaves[i];
    }
    // last layer is all leaves
    mini[T - 1] = maxi[T - 1] = layers[T - 1];
    K -= mini[T-1];

    if (K < 0) fail();
    for (int i = 0; i < T; i++) {
        int add = min(K, maxi[i] - mini[i]);
        K -= add;
        leaves[i] += add;
    }
    if (K != 0) fail();

    vector<pair<int, int>> res;
    for (int n = begin[0]; n < begin[0] + layers[0]; n++)
        res.emplace_back(1, n);

    for (int i = 0; i < T - 1; i++) {
        int non_leaves = layers[i] - leaves[i];
        for (int n = begin[i+1]; n < begin[i+1] + layers[i+1]; n++)
            res.emplace_back((n % non_leaves) + begin[i], n);
    }

    cout << N << endl;
    print(res);
    return 0;
}