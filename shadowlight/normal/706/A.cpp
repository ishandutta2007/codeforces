#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdio>
#include <vector>
#include <iomanip>

using namespace std;

struct TVector {
    long double x, y;
    long double len() {
        return sqrt(x * x + y * y);
    }
};

const int INF = 1e9 + 7;

TVector operator+(const TVector &a, const TVector &b) {
    return TVector({a.x + b.x, a.y + b.y});
}

TVector operator-(const TVector &a, const TVector &b) {
    return TVector({a.x - b.x, a.y - b.y});
}

TVector operator*(const TVector &a, long double k) {
    return TVector({a.x * k, a.y * k});
}

long double operator%(const TVector &a, const TVector &b) {
    return a.x * b.x + a.y * b.y;
}

long double operator*(const TVector &a, const TVector &b) {
    return a.x * b.y - a.y * b.x;
}

struct Line {
    long double a, b, c;
    Line(TVector p1, TVector p2) {
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1.y * p2.x - p2.y * p1.x;
    }
    long double len(TVector p) {
        long double top = abs(a * p.x + b * p.y - c);
        long double bot = sqrt(a * a + b * b);
        return top / bot;
    }
};

int main() {
    TVector p1;
    cout << setprecision(20);
    cin >> p1.x >> p1.y;
    int n;
    cin >> n;
    long double mink = INF;
    for (int i = 0; i < n; i++) {
        TVector p2;
        long double speed;
        cin >> p2.x >> p2.y >> speed;
        TVector v = p2 - p1;
        mink = min(mink, v.len() / speed);
    }
    cout << mink;
}