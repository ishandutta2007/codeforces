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

int find_missing(int c, vector<array<int, 2>> args) {
    for (int i = 0; i < args.size(); i++)
        if (c < args[i][0] || args[i][1] < c)
            return i;
    return -1;
}

map<int, int> pos(int N, vector<array<int, 2>> args) {
    vi order(N);
    for (int i = 0; i < N; i++)
        order[i] = i;
    sort(all(order), [&](int i, int j) {
        return args[i][0] < args[j][0];
    });

    map<int, int> res;
    priority_queue<int, vector<int>, greater<int>> ends;
    for (int i : order) {
        auto p = args[i];
        while(!ends.empty() && ends.top() < p[0])
            ends.pop();
        ends.push(p[1]);
        if (ends.size() >= N - 1)
            res[p[0]] = find_missing(p[0], args);
    }

    return res;
}

bool match(int m1, int m2) {
    if (m1 == -1) return true;
    if (m2 == -1) return true;
    return m1 == m2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;
    vector<array<int, 2>> x, y;

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x.push_back({ x1, x2 });
        y.push_back({ y1, y2 });
    }

    auto xp = pos(N, x), yp = pos(N, y);
    for (pair<int, int> xe : xp) {
        for (pair<int, int> ye : yp) {
            if (match(xe.second, ye.second)) {
                cout << xe.first << " " << ye.first << endl;
                return 0;
            }
        }
    }

    assert(false);
    return 0;
}