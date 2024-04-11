#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
    int x, y;
    Point operator-(Point p) { return {x - p.x, y - p.y}; }
};

const int N = 2505;
int n;
Point pt[N];

bool InUpper(Point p) {
    return p.y > 0 || (p.y == 0 && p.x > 0);
}
ll CrossProd(Point A, Point B) {
    return 1LL * A.x * B.y - 1LL * A.y * B.x;
}

ll f3[N], f4[N];

ll solve(vector<Point> A) {
//    cout << "s" << endl;
    sort(A.begin(), A.end(), [&](Point &A, Point &B) {
        int au = InUpper(A);
        int bu = InUpper(B);
        if (au != bu) {
            return au > bu;
        }
        return CrossProd(A, B) > 0;
    });
    for(int i = 0; i < A.size(); i++) {
        auto e = A[i];
//        cout << i << ": " << e.x << ", " << e.y << endl;
    }

    ll res = f4[A.size()] / 24;
    int r = 0;
    for(int i = 0; i < A.size(); i++) {
        r = max(r, i + 1);
        while(r < i + A.size() && CrossProd(A[i], A[r % A.size()]) > 0) r++;
        res -= f3[r - i - 1] / 6;
//        cout << i << ", " << r << endl;
    }
//    cout << "this " << res << endl;
    return res;
}

int main() {
    for(int i = 3; i < N; i++) {
        f3[i] = 1LL * i * (i - 1) * (i - 2);
        f4[i] = 1LL * i * (i - 1) * (i - 2) * (i - 3);
    }
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> pt[i].x >> pt[i].y;
    }

    ll res = 0;

    for(int i = 0; i < n; i++) {
        vector<Point> pts;
        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            pts.push_back(pt[j] - pt[i]);
        }
//        for(Point x : pts) cout << x.x << " " << x.y << endl;
        res += solve(pts);
    }
    cout << res << '\n';

}