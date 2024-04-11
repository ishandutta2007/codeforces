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

string query(vi &dists) {
    cout << "?";
    for (int d : dists)
        cout << " " << d;
    cout << endl;

    string res;
    cin >> res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vvi layer(N);
    vi bound(N, 0);

    layer[0] = { 0 };
    for (int i = 1; i < N; i++) {
        layer[1].push_back(i);
    }

    bound[1] = N - 1;

    while (true) {
        vi even, odd;
        for (int i = 0; i < N; i++) {
            if (bound[i] > i) {
                if (layer[i].size())
                    (even.size() > odd.size() ? odd : even).push_back(i);
                else {
                    for (int j = bound[i]; j >= i; j--)
                        bound[j] = j;
                }
            }
        }

        for (auto &grp : { even, odd }) {
            if (grp.empty()) continue;

            vi q1(N, 0), q2(N, 0);
            for (int i : grp) {
                int dm = (i + bound[i]) / 2;
                assert(!layer[i-1].empty());
                for (int p : layer[i-1]) {
                    q1[p] = dm - (i - 1);
                    q2[p] = dm - (i - 1) + 1;
                }
            }
            string res1 = query(q1), res2 = query(q2);

            for (int i : grp) {
                int dm = (i + bound[i]) / 2;

                vi tmp;
                for (int v : layer[i]) {
                    if (res1[v] == '1')
                        tmp.push_back(v);
                    else if (res2[v] == '1')
                        layer[dm + 1].push_back(v);
                    else
                        layer[dm + 2].push_back(v);
                }
                swap(layer[i], tmp);

                bound[dm + 1] = dm + 1;
                if (dm + 2 <= bound[i])
                    bound[dm + 2] = bound[i];
                bound[i] = dm;
            }
        }

        bool done = true;
        for (int i = 0; i < N; i++)
            if (bound[i] > i)
                done = false;
        if (done) break;
    }

    vi par(N);
    for (int m = 1; m <= 3; m++) {
        for (int b = 0; b < 10; b++) {
            vi q(N, 0);
            for (int d = m; d < N; d += 3) {
                for (int p : layer[d-1])
                    if ((p >> b)&1)
                        q[p] = 1;
            }
            string res = query(q);

            for (int d = m; d < N; d += 3) {
                for (int v : layer[d])
                    if (res[v] == '1')
                        par[v] |= 1 << b;
            }
        }
    }

    cout << "!\n";
    for (int i = 1; i < N; i++) {
        cout << par[i] + 1 << " " << i + 1 << "\n";
    }

    return 0;
}