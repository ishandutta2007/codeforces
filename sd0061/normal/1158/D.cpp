#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2005;


struct Point {
    int x , y;
    Point (int x = 0 , int y = 0) : x(x) , y(y) {}
    Point operator - (const Point& R) const {
        return Point(x - R.x , y - R.y);
    }
    LL operator ^ (const Point& R) const {
        return (LL)x * R.y - (LL)y * R.x;
    }
}; 

Point p[N];
int n;
bool used[N];
char str[N];

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d%d" , &p[i].x , &p[i].y);
    }
    scanf("%s" , str);
    vector<int> res;

    int cur = 0;
    for (int i = 1 ; i < n ; ++ i) {
        if (make_pair(p[i].x, p[i].y) < make_pair(p[cur].x, p[cur].y)) {
            cur = i;
        }
    }

    used[cur] = 1;
    res.emplace_back(cur);

    auto findLeft = [&](Point P) {
        int x = -1;
        for (int i = 0 ; i < n ; ++ i) {
            if (!used[i] && (!~x || ((p[i] - P) ^ (p[x] - P)) < 0)) {
                x = i;
            }
        }
        return x;
    };    
    auto findRight = [&](Point P) {
        int x = -1;
        for (int i = 0 ; i < n ; ++ i) {
            if (!used[i] && (!~x || ((p[i] - P) ^ (p[x] - P)) > 0)) {
                x = i;
            }
        }
        return x;
    };

    for (int i = 0 ; i < n - 2 ; ++ i) {
        int nxt;
        if (str[i] == 'L') {
            nxt = findRight(p[cur]);
        } else {
            nxt = findLeft(p[cur]);
        }
        used[nxt] = 1;
        cur = nxt;
        res.emplace_back(nxt);
    }

    res.emplace_back(findRight(p[cur]));

    for (int i = 0 ; i < n ; ++ i) {
        printf("%d%c" , res[i] + 1, " \n"[i + 1 == n]);
    }

}