#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;

    Point() {
        x = y = 0;
    }

    Point(int _x, int _y) {
        x = _x, y = _y;
    }
};

struct Vec {
    int x, y;

    Vec(int _x, int _y) {
        x = _x, y = _y;
    }
};

Vec toVec(Point a, Point b) {
    return Vec(b.x - a.x, b.y - a.y);
}

long long cross(Vec a, Vec b) {
    return (long long) a.x * b.y - (long long) a.y * b.x;
}

bool len(Vec a, Vec b) {
    return (long long) a.x * a.x + (long long) a.y * a.y
        == (long long) b.x * b.x + (long long) b.y * b.y;
}

bool check(Vec a, Vec b) {
    return cross(a, b) == 0 && len(a, b);
}

Point p[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> p[i].x >> p[i].y;
    p[n] = p[0];

    if (n % 2 == 1)
        cout << "NO\n";
    else {
        bool ok = true;
        for (int i=0; i<n/2; i++) {
            Vec v1 = toVec(p[i], p[i+1]), v2 = toVec(p[i+n/2], p[i+n/2+1]);
            if (!check(v1, v2)) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}