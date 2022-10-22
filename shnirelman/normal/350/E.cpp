#include <bits/stdc++.h>

#define f first
#define s second
#define endl '\n'

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 1e5 + 13;

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    set<int> sta;
    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;

        sta.insert(x - 1);
    }

    if(k == n) {
        cout << -1 << endl;
        return 0;
    }

    set<int> stb;
    for(int i = 0; i < n; i++) {
        if(sta.count(i) == 0) {
            stb.insert(i);
        }
    }

    int rt = *stb.begin();

//    vector<pii> e;
    set<pii> ste;
    for(int i = 0; i < n; i++) {
        if(i != rt) {
//            e.emplace_back(i, rt);
            ste.insert({min(i, rt), max(i, rt)});
        }
    }

    int v, u = -1;
//    if(sta.size() >= 2) {
    v = *sta.begin();
    u = *sta.rbegin();
//    } else if(sta.size() == 1) {
//        v = *sta.begin();
//        u = *stb.rbegin();
//    } else {
//        auto it = stb.begin();
//        it++;
//        v = *it;
//        it++;
//        u = *it;
//    }

    for(auto x : stb) {
        if(ste.size() >= m)
            break;

        for(int i = 0; i < n; i++) if(i != x) {
            if(ste.size() >= m)
                break;
            pii pp = {min(x, i), max(x, i)};
            if(ste.count(pp) == 0) {
                ste.insert(pp);
//                e.push_back(pp);
            }
        }
    }



    for(auto x : sta) {
        for(auto y : sta) {
            if(x != y && x != u && y != u && ste.size() < m) {
                ste.insert({min(x, y), max(x, y)});
            }
        }
    }

    if(ste.size() == m) {
        for(auto p : ste)
            cout << p.f + 1 << ' ' << p.s + 1 << endl;
    } else {
        cout << -1 << endl;
    }
}