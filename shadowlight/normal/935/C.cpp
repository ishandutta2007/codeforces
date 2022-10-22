#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e7 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

struct TVector {
    double x, y;
};

TVector operator+(TVector a, TVector b) {
    return {a.x + b.x, a.y + b.y};
}

TVector operator-(TVector a, TVector b) {
    return {a.x - b.x, a.y - b.y};
}

double operator%(TVector a, TVector b) {
    return a.x * b.x + a.y * b.y;
}

double len(TVector a) {
    return sqrt(a % a);
}

TVector norm(TVector a) {
    return {a.x / len(a), a.y / len(a)};
}

TVector operator*(TVector a, double k) {
    return {a.x * k, a.y * k};
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
    double r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    cout.precision(20);
    TVector O = {x1, y1}, A = {x2, y2};
    if (x1 == x2 && y1 == y2) {
        cout << O.x + r / 2 << " " << O.y << " " << r / 2 << "\n";
        return 0;
    }
    if (len(O - A) >= r) {
        cout << O.x << " " << O.y << " " << r << "\n";
        return 0;
    }
    TVector v = O - A;
    double l = len(v);
    v = norm(v) * (r / 2 + l / 2);
    cout << (v + A).x << " " << (v + A).y << " " << len(v) << "\n";
}