#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

bool split(int C, auto& castles, const auto& coord) {
    if (C == 1) return true;

    vector<array<set<pair<int, int>>::iterator, 2>> front = {
        {{ castles[0].begin(),  castles[2].begin()  }},
        {{ castles[1].begin(),  castles[3].begin()  }},
    }, curfr = front;
    vector<array<set<pair<int, int>>::reverse_iterator, 2>> back = {
        {{ castles[0].rbegin(),  castles[2].rbegin()  }},
        {{ castles[1].rbegin(),  castles[3].rbegin()  }},
    }, curbk = back;

    vi peel;
    for (int sp = 1; sp * 2 <= C; sp++) {
        for (int i = 0; i < 2; i++) {
            if (next(curfr[i][0])->first >= curfr[i][1]->first &&
                        next(curfr[i][1])->first >= curfr[i][0]->first) {
                for (auto it = front[i][0]; it != next(curfr[i][0]); it++)
                    peel.push_back(it->second);
                goto DONE;
            }
            curfr[i][0] = next(curfr[i][0]);
            curfr[i][1] = next(curfr[i][1]);

            if (next(curbk[i][0])->first <= curbk[i][1]->first &&
                        next(curbk[i][1])->first <= curbk[i][0]->first) {
                for (auto it = back[i][0]; it != next(curbk[i][0]); it++)
                    peel.push_back(it->second);
                goto DONE;
            }
            curbk[i][0] = next(curbk[i][0]);
            curbk[i][1] = next(curbk[i][1]);
        }
    }

DONE:
    if (!sz(peel)) return false;

    vector<set<pair<int, int>>> peeled(4);
    for (int c : peel) {
        for (int i = 0; i < 4; i++) {
            castles[i].erase({ coord[i][c], c });
            peeled[i].insert({ coord[i][c], c });
        }
    }
    return split(C - sz(peel), castles, coord) && split(sz(peel), peeled, coord);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vector<set<pair<int, int>>> castles(4);
    vvi coord(4);

    for (int i = 0; i < N; i++) {
        for (int j = 0, v; j < 4; j++) {
            cin >> v;
            castles[j].insert({ v, i });
            coord[j].push_back(v);
        }
    }

    cout << (split(N, castles, coord) ? "YES" : "NO") << endl;

    return 0;
}