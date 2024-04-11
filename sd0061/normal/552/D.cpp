#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
typedef long long LL;
const int N = 2005;

struct Point {
    int x , y;
    Point (int x = 0 , int y = 0) : x(x) , y(y) {}
    Point operator - (const Point& R) const {
        return Point(x - R.x , y - R.y);       
    }    
    bool operator < (const Point& R) const {
        return make_pair(x , y) < make_pair(R.x , R.y);
    }
    Point normal() {
        int z = __gcd(x , y);
        Point ret(x / z , y / z);
        if (ret.y < 0) {
            ret.x = -ret.x;
            ret.y = -ret.y;
        }
        return ret;
    }
}a[N];
int n;

void work() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d%d" , &a[i].x , &a[i].y);
    }
    LL res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        vector<Point> V;
        for (int j = 0 ; j < n ; ++ j) {
            if (i != j)
                V.push_back((a[j] - a[i]).normal());
        }
        sort(V.begin() , V.end());
        for (int j = 0 ; j + 1 < n ; ++ j) {
            int k = j;
            while (k + 1 < n && V[j].x == V[k].x && V[j].y == V[k].y)
                ++ k;
            res += (k - j) * (k - j - 1);
            j = k - 1;
        }
    }
    res = (LL)n * (n - 1) * (n - 2) - res;
    cout << res / 6 << endl;
}

int main() {
    work();
    return 0;
}