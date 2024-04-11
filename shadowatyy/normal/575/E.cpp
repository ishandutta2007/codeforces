#include<bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define nd second
#define st first
using namespace std;

vector<pair<int, int>> otoczka[2], pts, ot;

bool czypolewo(pair<int, int> p0, pair<int, int> p1, pair<int, int> p2) {
    int w1x = p1.st - p0.st, w1y = p1.nd - p0.nd;
    int w2x = p2.st - p0.st, w2y = p2.nd - p0.nd;
    return (w2y * w1x >= w2x * w1y);
}

const int BD = 100000;

int32_t main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x0, y0, v;
        cin >> x0 >> y0 >> v;

        pts.pb(mp(x0-v, y0));
        pts.pb(mp(x0+v, y0));
        pts.pb(mp(x0, y0+v));
        pts.pb(mp(x0, y0-v));

        if (x0 < v) {
            pts.pb(mp(0, y0 + v - x0));
            pts.pb(mp(0, y0 - v + x0));
        }
        if (y0 < v) {
            pts.pb(mp(x0 - v + y0, 0));
            pts.pb(mp(x0 + v - y0, 0));
        }
        if (x0 + v > BD) {
            pts.pb(mp(BD, y0 + (BD - x0 - v)));
            pts.pb(mp(BD, y0 - (BD - x0 - v)));
        }
        if (y0 + v > BD) {
            pts.pb(mp(x0 - (BD - y0 - v), BD));
            pts.pb(mp(x0 + (BD - y0 - v), BD));
        }
    }
    for (int i = 0; i < pts.size(); i++) {
        pts[i].st = max(0LL, pts[i].st);
        pts[i].nd = max(0LL, pts[i].nd);
        pts[i].st = min(BD, pts[i].st);
        pts[i].nd = min(BD, pts[i].nd);
    }



    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    for (int i = 0; i < 2; i++) {
        for (auto it : pts) {
            if (otoczka[i].size() < 2) {
                otoczka[i].pb(it);
                continue;
            }
            while(otoczka[i].size() >= 2 && czypolewo(otoczka[i][otoczka[i].size() - 2], otoczka[i].back(), it))
                otoczka[i].pop_back();
            otoczka[i].push_back(it);
        }
        reverse(pts.begin(), pts.end());
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < otoczka[i].size(); j++) {
            ot.pb(otoczka[i][j]);
        }
    }

    long double wynik = 0;
    pair<int, int> p1wyn, p2wyn, p3wyn;

    for (int i = 0; i < ot.size(); i++) {
        pair<int, int> p1 = ot[i], p2 = ot[(i + 1) % ot.size()], p3 = ot[(i + 2) % ot.size()];
        int x1 = p2.st - p1.st, y1 = p2.nd - p1.nd;
        int x2 = p3.st - p1.st, y2 = p3.nd - p1.nd;
        int pole = 2 * abs(x1 * y2 - y1 * x2);
        int a = x1 * x1 + y1 * y1;
        int b = x2 * x2 + y2 * y2;
        int c = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        if (wynik < sqrtl(a) * sqrtl(b) * sqrtl(c) / pole) {
            wynik = sqrtl(a) * sqrtl(b) * sqrtl(c) / pole;
            p1wyn = p1;
            p2wyn = p2;
            p3wyn = p3;
        }
    }
    cout << p1wyn.st << " " << p1wyn.nd << "\n" << p2wyn.st << " " << p2wyn.nd << "\n" <<p3wyn.st << " " << p3wyn.nd;
    return 0;
}