#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e16;
const int INF = 2e9 + 7;

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll x1, x2, y1, y2, n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    x1 *= 2;
    y1 *= 2;
    x2 *= 2;
    y2 *= 2;
    ll dx = (x1 + x2) / 2, dy = (y1 + y2) / 2;
    x1 -= dx;
    x2 -= dx;
    y1 -= dy;
    y2 -= dy;
    ll a = y1, b = 0 - x1;

    vector<ll> x(n), y(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> r[i];
        x[i] = x[i] * 2 - dx;
        y[i] = y[i] * 2 - dy;
        r[i] *= 2;
    }

    vector<pair<ld, int>> endo;
    vector<pair<ld, int>> endc;
    for (int i = 0; i < n; ++i) {
        ld r2 = r[i] * r[i];
        ld C1 = x[i] * x[i] + y[i] * y[i] - x1 * x1 - y1 * y1 - r2;
        ld C2 = a * x[i] + b * y[i] + a * x1 + b * y1;
        ld A = 4 * C2 * C2 - 4 * a * a * r2 - 4 * b * b * r2;
        ld B = 0. - 4 * C1 * C2 - 8 * a * x1 * r2 - 8 * b * y1 * r2;
        ld C = C1 * C1 - 4 * x1 * x1 * r2 - 4 * y1 * y1 * r2;
        ld D = B * B - 4 * A * C;
        if (D > EPS) {
            D = sqrt(D);
            endo.push_back({ (0 - B - D) / 2 / A, i });
            endc.push_back({ (0 - B + D) / 2 / A, i });
            if (endo.back().first > endc.back().first) {
                swap(endo.back(), endc.back());
            }
            //cout << endo.back().first << " " << endc.back().first << "\n";
        }
    }
    endo.push_back({ 1e30, -1 });
    endc.push_back({ 1e30, -1 });
    endo.push_back({ -1e30, -2 });
    endc.push_back({ -1e30, -2 });
    sort(endo.begin(), endo.end());
    sort(endc.begin(), endc.end());

    cout << setprecision(15);
    if (endo[0].first >= 0 || endc.back().first <= 0) {
        cout << sqrt(x1 * x1 + y1 * y1) / 2;
        return 0;
    }
    ld minr = 1e15;
    int cc = 0;
    set<int> copen;
    for (int co = 0; co < endo.size() - 1; ++co) {
        copen.insert(endo[co].second);
        while (copen.count(endc[cc].second) > 0 && endc[cc].first < endo[co + 1].first) {
            copen.erase(endc[cc].second);
            ++cc;
        }/*
        for (auto it = copen.begin(); it != copen.end(); ++it) {
            cout << *it << " ";
        }
        cout << "\n";*/
        if (copen.size() > 0) {
            continue;
        }
        ld cx, cy;
        cx = a * max(endo[co].first, endc[cc - 1].first) + x1;
        cy = b * max(endo[co].first, endc[cc - 1].first) + y1;
        minr = min(minr, sqrt(cx * cx + cy * cy) / 2);
        /*cout << (a * max(endo[co].first, endc[cc - 1].first) + dx) / 2 << ", " << (b * max(endo[co].first, endc[cc - 1].first) + dy) / 2 << "; ";
        cout << endo[co].first << ": " << sqrt(cx * cx + cy * cy) / 2 << "\n";*/
        cx = a * min(endo[co + 1].first, endc[cc].first) + x1;
        cy = b * min(endo[co + 1].first, endc[cc].first) + y1;
        minr = min<ld>(minr, sqrt(cx * cx + cy * cy) / 2);
        /*cout << (a * min(endo[co + 1].first, endc[cc].first) + dx) / 2 << ", " << (b * min(endo[co + 1].first, endc[cc].first) + dy) / 2 << "; ";
        cout << min(endo[co + 1].first, endc[cc].first) << ": " << sqrt(cx * cx + cy * cy) / 2 << "\n";*/
        if (min(endo[co + 1].first, endc[cc].first) > 0 && max(endo[co].first, endc[cc - 1].first) < 0) {
            minr = min<ld>(minr, sqrt(x1 * x1 * 1. + y1 * y1) / 2);
        }
    }
    cout << minr << "\n";

    return 0;
}