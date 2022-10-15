#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

int n;

struct Point {
    int i, x, y, z;
    bool f;
}; std::vector<Point> p;

bool comparexy(Point u, Point v) {
    if (u.x == v.x && u.y == v.y) { return u.z < v.z; }
    return u.x == v.x ? u.y < v.y : u.x < v.x;
}
bool compareyz(Point u, Point v) {
    if (u.y == v.y && u.z == v.z) { return u.x < v.x; }
    return u.y == v.y ? u.z < v.z : u.y < v.y;
}
bool comparezx(Point u, Point v) {
    if (u.z == v.z && u.x == v.x) { return u.y < v.y; }
    return u.z == v.z ? u.x < v.x : u.z < v.z;
}

void solvexy() {
    std::sort(p.begin(), p.end(), comparexy);
    for (int i = (int) p.size() - 1; i >= 1; i--) {
        if (p[i - 1].f || p[i].f) { continue; }
        if (p[i - 1].x == p[i].x && p[i - 1].y == p[i].y) {
            printf("%d %d\n", p[i - 1].i, p[i].i);
            p[i - 1].f = p[i].f = true;
        }
    }
    std::vector<Point> q;
    for (auto i : p) {
        if (!i.f) { q.push_back(i); }
    }
    p = q;
}
void solveyz() {
    std::sort(p.begin(), p.end(), compareyz);
    for (int i = (int) p.size() - 1; i >= 1; i--) {
        if (p[i - 1].f || p[i].f) { continue; }
        if (p[i - 1].y == p[i].y && p[i - 1].z == p[i].z) {
            printf("%d %d\n", p[i - 1].i, p[i].i);
            p[i - 1].f = p[i].f = true;
        }
    }
    std::vector<Point> q;
    for (auto i : p) {
        if (!i.f) { q.push_back(i); }
    }
    p = q;
}
void solvezx() {
    std::sort(p.begin(), p.end(), comparezx);
    for (int i = (int) p.size() - 1; i >= 1; i--) {
        if (p[i - 1].f || p[i].f) { continue; }
        if (p[i - 1].z == p[i].z && p[i - 1].x == p[i].x) {
            printf("%d %d\n", p[i - 1].i, p[i].i);
            p[i - 1].f = p[i].f = true;
        }
    }
    std::vector<Point> q;
    for (auto i : p) {
        if (!i.f) { q.push_back(i); }
    }
    p = q;
}
void solve() {
    std::vector<Point> q;
    std::sort(p.begin(), p.end(), comparexy);
    for (int i = (int) p.size() - 1; i >= 1; i--) {
        if (p[i - 1].f || p[i].f) { continue; }
        if (p[i - 1].x == p[i].x) {
            printf("%d %d\n", p[i - 1].i, p[i].i);
            p[i - 1].f = p[i].f = true;
        }
    }
    for (auto i : p) {
        if (!i.f) { q.push_back(i); }
    }
    p = q; q.clear();
    std::sort(p.begin(), p.end(), compareyz);
    for (int i = (int) p.size() - 1; i >= 1; i--) {
        if (p[i - 1].f || p[i].f) { continue; }
        if (p[i - 1].y == p[i].y) {
            printf("%d %d\n", p[i - 1].i, p[i].i);
            p[i - 1].f = p[i].f = true;
        }
    }
    for (auto i : p) {
        if (!i.f) { q.push_back(i); }
    }
    p = q; q.clear();
    std::sort(p.begin(), p.end(), comparezx);
    for (int i = (int) p.size() - 1; i >= 1; i--) {
        if (p[i - 1].f || p[i].f) { continue; }
        if (p[i - 1].z == p[i].z) {
            printf("%d %d\n", p[i - 1].i, p[i].i);
            p[i - 1].f = p[i].f = true;
        }
    }
    for (auto i : p) {
        if (!i.f) { q.push_back(i); }
    }
    p = q; q.clear();
    std::sort(p.begin(), p.end(), comparexy);
    for (int i = 1; i < p.size(); i += 2) {
        printf("%d %d\n", p[i - 1].i, p[i].i);
    }
}

int main() {
    n = read(); p.resize(n);
    for (int i = 0; i < n; i++) {
        p[i].i = i + 1;
        p[i].x = read(); p[i].y = read(); p[i].z = read();
    }
    solvexy(); solveyz(); solvezx(); solve();
    return 0;
}