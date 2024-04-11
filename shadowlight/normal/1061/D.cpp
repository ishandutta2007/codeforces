#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct State {
    ll pos, d, id;
};

bool operator<(State a, State b) {
    if (a.pos != b.pos) {
        return a.pos < b.pos;
    }
    if (a.d != b.d) {
        return a.d < b.d;
    }
    return a.id < b.id;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    ll n, x, y;
    cin >> n >> x >> y;
    vector <State> a;
    vector <ll> lt(n), rt(n);
    for (ll i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        lt[i] = l, rt[i] = r;
        a.push_back({l, 1, i});
        a.push_back({r + 1, 0, i});
    }
    sort(a.begin(), a.end());
    vector <ll> q;
    vector <ll> val(n, -1);
    ll sum = 0, cnt = 0;
    for (auto t : a) {
        ll pos = t.pos, d = t.d, id = t.id;
        if (d) {
            while (q.size() && (pos - q.back()) * y > x) {
                q.pop_back();
            }
            if (q.size()) {
                sum += (rt[id] - q.back()) * y;
                sum %= INF;
                q.pop_back();
            } else {
                //cout << "kek\n";
                sum += x + (rt[id] - lt[id]) * y;
                sum %= INF;
            }
        } else {
            q.push_back(pos - 1);
        }
        //cout << pos << " " << d << " " << sum << "\n";
    }
    cout << sum;
}