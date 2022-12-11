#include <bits/stdc++.h>

using namespace std;

#define y1 yy1

typedef long long ll;
const int N = 1e6 + 7;

void fail() {
    cout << -1;
    exit(0);
}

ll ans, sq, area;

void go2(int x1, int y1, int x2, int y2, int x3, int y3, string s) {
    if (x2 + x3 == sq && y2 == sq - y1 && y3 == sq - y1) {
        cout << sq << "\n";
        for (int i = 0; i < y1; i++) {
            for (int j = 0; j < x1; j++)
                cout << s[0];
            cout << "\n";
        }
        for (int i = y1; i < sq; i++) {
            for (int j = 0; j < sq; j++)
                cout << (j < x2 ? s[1] : s[2]);
            cout << "\n";
        }
        exit(0);
    }
}   

void go(int x1, int y1, int x2, int y2, int x3, int y3, string s) {
    if (x1 < sq) 
        return;
    int h = sq - y1;
    if (x2 == sq && x2 == sq) {
        cout << sq << "\n";
        for (int i = 0; i < y1; i++) {
            for (int j = 0; j < x1; j++) cout << s[0];
            cout << "\n";
        }
        for (int i = 0; i < y2; i++) {
            for (int j = 0; j < x1; j++) cout << s[1];
            cout << "\n";
        }
        for (int i = 0; i < y3; i++) {
            for (int j = 0; j < x1; j++) cout << s[2];
            cout << "\n";
        }
        exit(0);
    }
    go2(x1, y1, x2, y2, x3, y3, s);
    go2(x1, y1, y2, x2, x3, y3, s);
    go2(x1, y1, x2, y2, y3, x3, s);
    go2(x1, y1, y2, x2, y3, x3, s);
}

int x1, y1, x2, y2, x3, y3;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    area = x1 * y1 + x2 * y2 + x3 * y3;
    sq = sqrt(area + 0.5);
    if (sq * sq != area) {
        fail();
    }

    if (x1 < y1) swap(x1, y1);
    if (x2 < y2) swap(x2, y2);
    if (x3 < y3) swap(x3, y3);

    if (max(max(x1, x2), x3) > sq)
        fail();

    go(x1, y1, x2, y2, x3, y3, "ABC");

    go(x2, y2, x1, y1, x3, y3, "BAC");

    go(x3, y3, x1, y1, x2, y2, "CAB");

    fail();

    return 0;
}