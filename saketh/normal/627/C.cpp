#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct event {
    int xc;
    bool intro;

    int gi;
    int price;

    event(int _xc, bool _intro, int _gi,int _price) {
        xc = _xc;
        intro = _intro;
        gi = _gi;
        price = _price;
    }

    bool operator<(const event &o) {
        if (xc != o.xc) return xc < o.xc;
        return intro > o.intro;
    }
};

int D, N, M, X, P;
vector<event> all;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> D >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> X >> P;

        all.push_back(event(X, true, i, P));
        all.push_back(event(X + N, false, i, P));
    }

    int loc = 0;
    ll spent = 0;

    set<pair<int, int>> avail;

    avail.insert(make_pair(0, 0));
    all.push_back(event(N, false, 0, 0));

    sort(all.begin(), all.end());

    for (event &e : all) {
        int nxt = e.xc;

        if (nxt >= D) { // prices aren't changing anymore, just go to the end
            spent += (D - loc) * 1ll * avail.begin()->first;
            cout << spent << "\n";
            return 0;
        }

        spent += (nxt - loc) * 1ll * avail.begin()->first;
        loc = nxt;

        if (e.intro) {
            avail.insert(make_pair(e.price, e.gi));
        } else {
            avail.erase(make_pair(e.price, e.gi));
        }

        if (!avail.size()) {
            cout << -1 << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}