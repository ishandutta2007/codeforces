#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct pt{
    int x, y;
    pt() {}
    pt (int xx, int yy) {
        x = xx;
        y = yy;
    }
    pt(string s) {
        x = s[0] - 'a';
        y = s[1] - '1';
        cerr << x << " " << y << "\n";
    }
    bool operator == (const pt &a) {
        return x == a.x && y == a.y;
    }
    int len(const pt &a) {
        return (x - a.x) * (x - a.x) + (y - a.y) * (y - a.y);
    }
    int ln(const pt &a) {
        return abs(x + y - a.x - a.y) + (a.x - x) * (a.y - y) * 100;
    }
};

pt rook1, rook2, wk, bk;
bool def = false;

bool check(pt k) {
    if (min(k.x, k.y) < 0) return true;
    if (max(k.x, k.y) >= 8) return true;
    if (k == rook1 && !def && wk.len(rook1) > 2) return false;
    if (k == rook2 && !def && wk.len(rook2) > 2) return false;
    if ((k.x == rook1.x || k.y == rook1.y) && wk.ln(k) + wk.ln(rook1) != k.ln(rook1)) return true;
    if ((k.x == rook2.x || k.y == rook2.y) && wk.ln(k) + wk.ln(rook2) != k.ln(rook2)) return true;
    if (wk.len(k) <= 2) return true;
    return false;
}

int main() {
    //freopen("a.in", "r", stdin);
    string r1, r2, k1, k2;
    cin >> r1 >> r2 >> k1 >> k2;
    rook1 = pt(r1);
    rook2 = pt(r2);
    wk = pt(k1);
    bk = pt(k2);
    if ((rook1.x == rook2.x || rook1.y == rook2.y) && wk.ln(rook1) + wk.ln(rook2) != rook1.ln(rook2))
        def = true;
    if (!check(bk)) {cout << "OTHER\n"; return 0;}
    if (!check(pt(bk.x, bk.y - 1))) {cout << "OTHER\n"; return 0;}
    if (!check(pt(bk.x, bk.y + 1))) {cout << "OTHER\n"; return 0;}
    if (!check(pt(bk.x - 1, bk.y - 1))) {cout << "OTHER\n"; return 0;}
    if (!check(pt(bk.x - 1, bk.y))) {cout << "OTHER\n"; return 0;}
    if (!check(pt(bk.x - 1, bk.y + 1))) {cout << "OTHER\n"; return 0;}
    if (!check(pt(bk.x + 1, bk.y - 1))) {cout << "OTHER\n"; return 0;}
    if (!check(pt(bk.x + 1, bk.y))) {cout << "OTHER\n"; return 0;}
    if (!check(pt(bk.x + 1, bk.y + 1))) {cout << "OTHER\n"; return 0;}
    cout << "CHECKMATE\n";
}