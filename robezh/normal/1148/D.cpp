#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50;

struct P {
    int l, r, id;
};

int n;
vector<P> inc, dc;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        if(l < r) inc.push_back({l, r, i});
        else dc.push_back({l, r, i});
    }
    if(inc.size() >= dc.size()) {
        sort(inc.begin(), inc.end(), [](const P &p1, const P &p2) {
            return p1.l > p2.l;
        });
        cout << inc.size() << "\n";
        for(const auto &p : inc) cout << p.id + 1 << " ";
        cout << "\n";
    }
    else {
        sort(dc.begin(), dc.end(), [](const P &p1, const P &p2) {
            return p1.l < p2.l;
        });
        cout << dc.size() << "\n";
        for(const auto &p : dc) cout << p.id + 1 << " ";
        cout << "\n";
    }

}