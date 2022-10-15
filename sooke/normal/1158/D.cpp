// La Ji Remote Judge.

#include <cstdio>
#include <algorithm>
#include <map>

typedef std::pair<long long, long long> Point;

bool operator <(Point u, Point v) {
    return u.first == v.first ? u.second < v.second : u.first < v.first;
}
Point operator >>(Point u, Point v) {
    return {v.first - u.first, v.second - u.second};
}
long long operator ^(Point u, Point v) {
    return u.first * v.second - u.second * v.first;
}

const int N = 2005;

int n;
char str[N];
Point p, q;
std::map<Point, int> f;

int main() {
    scanf("%d", &n);
    for (int i = 1, x, y; i <= n; i++) {
        scanf("%d%d", &x, &y); f[{x, y}] = i;
    }
    scanf("%s", str + 3);
    printf("%d ", f.begin()->second);
    q = f.begin()->first; f.erase(q);
    for (int i = 3; i <= n; i++) {
        p = q;
        if (str[i] == 'L') {
            for (auto j : f) { q = (p >> q ^ p >> j.first) > 0 ? q : j.first; }
        } else {
            for (auto j : f) { q = (p >> q ^ p >> j.first) < 0 ? q : j.first; }
        }
        printf("%d ", f[q]); f.erase(q);
    }
    printf("%d\n", f.begin()->second);
    return 0;
}