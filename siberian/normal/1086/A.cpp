#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>


using namespace std;


struct P {
    int x, y;

    P() {};
    P(int x, int y) : x(x), y(y) {};

    bool operator<(const P &p) const {
        if (x == p.x) {
            return y < p.y;
        }

        return x < p.x;
    }
};


set<P> con(P a, P b, bool up) {
    if (a.y > b.y) {
        swap(a, b);
    }

    set<P> res;

    if (up) {
        for (int y = a.y; y < b.y; ++y) {
            res.emplace(a.x, y);
        }

        for (int x = a.x; x != b.x; x = x + (b.x > a.x ? 1 : -1)) {
            res.emplace(x, b.y);
        }
    } else {
        for (int x = a.x; x != b.x; x = x + (b.x > a.x ? 1 : -1)) {
            res.emplace(x, a.y);
        }

        for (int y = a.y; y < b.y; ++y) {
            res.emplace(b.x, y);
        }
    }

    res.insert(b);

    return res;
}


void merge(set<P> &a, set<P> &b) {
    for (P x : b) {
        a.insert(x);
    }
}


set<P> con(vector<P> ps, vector<int> ups) {
    set<P> a = con(ps[0], ps[1], ups[0]);
    set<P> b = con(ps[1], ps[2], ups[1]);
    merge(a, b);

    return a;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<P> ps(3);
    for (int i = 0; i < 3; ++i) {
        cin >> ps[i].x >> ps[i].y;
    }

    int answ = (int)1e7;
    set<P> aps;

    do {
        for (int i = 0; i < 4; ++i) {
            vector<int> ups = {i % 2, i > 1};

            set<P> cur = con(ps, ups);

            if (cur.size() < answ) {
                answ = cur.size();
                aps = cur;
            }
        }
    } while (next_permutation(ps.begin(), ps.end()));

    cout << aps.size() << '\n';
    for (P x : aps) {
        cout << x.x << ' ' << x.y << '\n';
    }

    return 0;
}