#include <bits/stdc++.h>

using namespace std;

struct Vect {
    int x, y;

    Vect() {};

    Vect(int x, int y) : x(x), y(y) {};
};

Vect operator - (Vect a, Vect b) {
    return Vect(a.x - b.x, a.y - b.y);
}

bool operator != (Vect a, Vect b) {
    return a.x != b.x || a.y != b.y;
}

using Point = Vect;

int main() {
    int n;
    cin >> n;

    vector<Point> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }

    if(n & 1) {
        cout << "NO" << endl;
        return 0;
    }

    int k = n / 2;

    for(int i1 = 0; i1 < n; i1++) {
        int i2 = (i1 + 1) % n;
        int j1 = (i1 + k) % n;
        int j2 = (j1 + 1) % n;

        Vect v = a[i2] - a[i1];
        Vect u = a[j1] - a[j2];

        if(v != u) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES";
}