#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

const li INF = 1e17;

li len(pair<li, li> a, pair<li, li> b) {
    return abs(a.f - b.f) + abs(a.s - b.s);
}

void solve() {

}

int main() {
    //  ios_base::sync_with_stdio(0);
//  cin.tie(0);

    vector<pair<li, li>> a(1);
    cin >> a[0].f >> a[0].s;

    li ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    li x, y, t;
    cin >> x >> y >> t;

    pair<li, li> p = {x, y};

    while(1) {
        li x1 = a.back().f * ax + bx, y1 = a.back().s * ay + by;
        ld x2 = ld(a.back().f) * ax + bx, y2 = ld(a.back().s) * ay + by;
        if(x2 > INF || y2 > INF)
            break;
        a.emplace_back(x1, y1);
    }

//    sort(a.begin(), a.end());

    li ans = 0;
    for(int i = 0; i < a.size(); i++) {
        li t1 = len(a[i], p);
        if(t1 < 0)
            continue;
        li res = (t1 <= t ? 1 : 0);

        for(int j = i + 1; j < a.size(); j++) {
            t1 += len(a[j - 1], a[j]);

            if(t1 > t)
                break;

            res++;
        }
//        cout << i << ' ' << res << endl;
        ans = max(ans, res);
    }

    for(int i = 0; i < a.size(); i++) {
        li t1 = len(a[i], p);
        if(t1 < 0)
            continue;
        li res = (t1 <= t ? 1 : 0);

        for(int j = i - 1; j >= 0; j--) {
            t1 += len(a[j + 1], a[j]);

            if(t1 > t)
                break;

            res++;
        }
//cout << i << ' ' << res << endl;
        ans = max(ans, res);
    }

    cout << ans;
}