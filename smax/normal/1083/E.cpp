#include <bits/stdc++.h>
using namespace std;

struct Rect {
    int x, y;
    long long a;

    bool operator < (const Rect &other) const {
        return x < other.x;
    }
} r[1000000];

struct Line {
    long long m, c;

    long long eval(int x) {
        return m * x + c;
    }

    /*double intersect(Line &l) {
        return (double) (c - l.c) / (l.m - m);
    }*/

    bool intersect(Line &l1, Line &l2) {
      //return (c - l1.c) / (l1.m - m) > (l1.c - l2.c) / (l2.m - l1.m);
      return (__int128) (c - l1.c) * (l2.m - l1.m) > (__int128) (l1.c - l2.c) * (l1.m - m);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> r[i].x >> r[i].y >> r[i].a;

    sort(r, r + n);

    long long ret = 0;
    deque<Line> dq;
    dq.push_back({0, 0});
    for (int i=0; i<n; i++) {
        while (dq.size() >= 2 && dq.back().eval(r[i].y) <= dq[dq.size()-2].eval(r[i].y))
            dq.pop_back();
        long long val = dq.back().eval(r[i].y) + (long long) r[i].x * r[i].y - r[i].a;
        ret = max(ret, val);
        Line cur = {-r[i].x, val};
        while (dq.size() >= 2 && cur.intersect(dq.front(), dq[1]))
            dq.pop_front();
        dq.push_front(cur);
    }

    cout << ret << "\n";

    return 0;
}