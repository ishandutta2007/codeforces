#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<array<int, 3>, bool> cache;
bool comp(int a, int b, int c) {
    if (a == c) {
        return b == a;
    }
    if (b == a || b == c) {
        return true;
    }

    if (cache.count({ a, b, c }))
        return cache[{ a, b, c }];

    cout << "? " << a+1 << " " << b+1 << " " << c+1 << endl;
    string _res;
    cin >> _res;
    bool res = _res == "Yes";

    cache[{ a, b, c }] = res;
    cache[{ c, b, a }] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, K;
    cin >> N >> K;

    int height = 1;
    int leaves = 1;
    int total = 1;
    while (total < N) {
        leaves *= K;
        height++;
        total += leaves;
    }
    assert(total == N);

    int v1, v2;
    vi betw;

    while (true) {
        v1 = rng() % N;
        do { v2 = rng() % N; }
        while (v1 == v2);

        for (int i = 0; i < N; i++) {
            if (comp(v1, v2, i)) v2 = i;
            if (comp(i, v1, v2)) v1 = i;
        }

        betw.clear();
        for (int i = 0; i < N; i++) {
            if (i != v1 && i != v2 && comp(v1, i, v2))
                betw.push_back(i);
        }

        if (betw.size() == 2 * height - 3) {
            break;
        }
    }

    sort(all(betw), [&](int i, int j) {
        return comp(v1, i, j);
    });

    cout << "! " << betw[betw.size()/2]+1 << endl;

    return 0;
}