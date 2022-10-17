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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vector<array<int, 2>> ob(N), cl(N);

    for (int i = 0; i < N; i++)
        cin >> ob[i][0] >> ob[i][1];

    for (int i = 0; i < N; i++)
        cin >> cl[i][0] >> cl[i][1];

    vector<array<int, 2>> pts;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            pts.push_back({ ob[i][0] + cl[j][0], ob[i][1] + cl[j][1] });
        }
    }

    sort(all(pts));
    for (int i = 0, j = 0; i < pts.size(); i = j) {
        while (j < pts.size() && pts[j] == pts[i])
            j++;

        // will appear exactly N times since each obelisk produces N distinct points
        if (j - i == N) {
            cout << pts[i][0] << " " << pts[i][1] << endl;
            return 0;
        }
    }

    assert(false);
    return 0;
}