#include <bits/stdc++.h>
using namespace std;

struct Line {
    long long m, c;

    long long eval(int x) {
        return m * x + c;
    }

    double intersect(Line &l) {
        return (double) (c - l.c) / (l.m - m);
    }
};

int a[100000], b[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++)
        cin >> b[i];

    long long ret;
    deque<Line> dq;
    dq.push_back({b[0], 0});
    for (int i=1; i<n; i++) {
        while (dq.size() >= 2 && dq.back().eval(a[i]) >= dq[dq.size()-2].eval(a[i]))
            dq.pop_back();
        ret = dq.back().eval(a[i]);
        Line cur = {b[i], ret};
        while (dq.size() >= 2 && cur.intersect(dq.front()) <= dq.front().intersect(dq[1]))
            dq.pop_front();
        dq.push_front(cur);
    }

    cout << ret << "\n";

    return 0;
}