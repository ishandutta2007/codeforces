#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int Q = 1e9 + 7;

struct Point {
    int x , y;
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    const int sign() const {
        return y < 0 || y == 0 && x < 0;
    }
    Point operator - (const Point &R) {
        return Point(x - R.x , y - R.y);
    }
    long long operator ^ (const Point &R) const {
        return (long long)x * R.y - (long long)y * R.x;
    }
    bool operator < (const Point &R) const {
        if (sign() != R.sign()) {
            return sign() < R.sign();
        }
        return (*this ^ R) > 0;
    }
};

inline void add(long long &A , long long B) {
    A += B;
}

Point p[N];
int n;
long long f[6][N][N];

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d%d", &p[i].x , &p[i].y);
        f[0][i][i] = 1;
    }
    vector<tuple<Point, int, int>> v;
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < i ; ++ j) {
            v.emplace_back(p[j] - p[i], i , j);
            v.emplace_back(p[i] - p[j], j , i);
        }
    }
    sort(v.begin() , v.end());

    for (auto &it : v) {
        int x = get<1>(it);
        int y = get<2>(it);
        for (int i = 5 ; i > 0 ; -- i) {
            for (int j = 0 ; j < n ; ++ j) {
                add(f[i][j][y], f[i - 1][j][x]);
            }
        }
    }

    long long res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        add(res , f[5][i][i]);
    }
    cout << res << endl;

}