#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9

struct Line {
    // y = mx + b, deal with vertical lines separately
    double m, b;

    Line(int x1, int y1, int x2, int y2) {
        m = (double) (y2 - y1) / (x2 - x1);
        b = y1 - m * x1;
    }

    bool operator < (const Line &other) const {
        if (fabs(m - other.m) < EPS)
            return b < other.b;
        return m < other.m;
    }
};

int x[1000], y[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> x[i] >> y[i];

    set<int> vert;
    map<pair<int, int>, int> mp;
    set<Line> st;
    int numLines = n * (n - 1) / 2, rem = 0;
    long long ret = (long long) numLines * (numLines - 1) / 2;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++) {
            auto v = make_pair(x[j] - x[i], y[j] - y[i]);
            if (x[i] == x[j]) {
                if (vert.count(x[i])) {
                    ret -= numLines - 1 - rem;
                    rem++;
                    continue;
                }
                vert.insert(x[i]);
            } else {
                Line l(x[i], y[i], x[j], y[j]);
                if (st.count(l)) {
                    ret -= numLines - 1 - rem;
                    rem++;
                    continue;
                }
                st.insert(l);
            }
            // simplify the pair
            int g = __gcd(v.first, v.second);
            v.first /= g;
            v.second /= g;
            if (v.second < 0) {
                v.first *= -1;
                v.second *= -1;
            }
//            cout << i << ", " << j << ", ";
//            cout << v.first << ", " << v.second << " ";
            if (mp.count(v))
                ret -= mp[v];
            mp[v]++;
//            cout << ret << endl;
        }

    cout << ret << "\n";

    return 0;
}