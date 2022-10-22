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

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const long double EPS = 1e-8;

struct TVector {
    long double x, y;
};

TVector operator-(TVector a, TVector b) {
    return {a.x - b.x, a.y - b.y};
}

long double operator%(TVector a, TVector b) {
    return a.x * b.x + a.y * b.y;
}

long double len(TVector a, TVector b) {
    a = a - b;
    return sqrt(a % a);
}

long double len1(TVector a, TVector b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

TVector E, F;

long double path(TVector A, TVector B) {
    return len1(A, E) + len(A, B) + len1(B, F);
}

long double a, b, c;

long double getx(long double y) {
    return (-c - y * b) / a;
}

long double gety(long double x) {
    return (-c - x * a) / b;
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
    cin >> a >> b >> c;
    long double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    E = {x1, y1}, F = {x2, y2};
    cout.precision(30);
    long double res = abs(x1 - x2) + abs(y1 - y2);
    if (abs(a) < EPS || abs(b) < EPS) {
        cout << res;
        return 0;
    }
    vector <TVector> all;
    long double alp = (-c - b * y1 - a * x1) / (a * a + b * b);
    long double beta = (-c - b * y2 - a * x2) / (a * a + b * b);
    TVector E1 = {x1 + alp * a, y1 + alp * b};
    TVector E2 = {x2 + beta * a, y2 + beta * b};
//    cout << E1.x * a + E1.y * b + c << "\n";
//    cout << E2.x * a + E2.y * b + c << "\n";
    TVector A, B, C, D;
    A = {x1, gety(x1)};
    B = {getx(y1), y1};
    C = {x2, gety(x2)};
    D = {getx(y2), y2};
    all.push_back(A);
    all.push_back(B);
    all.push_back(C);
    all.push_back(D);
//    all.push_back({floor(E1.x), gety(floor(E1.x))});
//    all.push_back({ceil(E1.x), gety(ceil(E1.x))});
//    all.push_back({floor(E2.x), gety(floor(E2.x))});
//    all.push_back({ceil(E2.x), gety(ceil(E2.x))});
//    all.push_back({getx(floor(E1.y)), floor(E1.y)});
//    all.push_back({getx(ceil(E1.y)), ceil(E1.y)});
//    all.push_back({getx(floor(E2.y)), floor(E2.y)});
//    all.push_back({getx(ceil(E2.y)), ceil(E2.y)});
    for (ll i = 0; i < (ll) all.size(); i++) {
        for (ll j = 0; j < (ll) all.size(); j++) {
            res = min(res, path(all[i], all[j]));
        }
    }
    cout << fixed << res;
}