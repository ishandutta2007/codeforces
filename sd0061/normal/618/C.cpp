#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100005;

struct Point {
    int x , y;
    Point (int _x = 0 , int _y = 0) {
        x = _x , y = _y;
    }
    Point operator - (const Point &R) const {
        return Point(x - R.x , y - R.y);
    }
    LL operator ^ (const Point &R) const {
        return (LL)x * R.y - (LL)y * R.x;
    }
    LL operator % (const Point &R) const {
        return (LL)x * R.x + (LL)y * R.y;
    }    
    int sign() const {
        return y > 0 || (y == 0 && x > 0);
    }
    bool operator < (const Point &R) const {
        if (this->sign() != R.sign())
            return this->sign() < R.sign();
        LL w = (*this ^ R);
        if (w == 0)
            return (*this % *this) < R % R;
        return w > 0;
    }
    bool operator == (const Point &R) const {
        if (this->sign() != R.sign())
            return 0;
        return (*this ^ R) == 0;
    }
};
int n , b[N];
Point P;
pair<Point , int> a[N];
int main() {
    scanf("%d%d%d" , &n , &P.x , &P.y);
    for (int i = 0 ; i + 1 < n ; ++ i) {
        scanf("%d%d" , &a[i].first.x , &a[i].first.y);
        a[i].first = a[i].first - P;
        a[i].second = i + 2;
    }
    -- n;
    sort(a , a + n);
    int m = 0;
    for (int i = 0 ; i < n ; ++ i) {
        int j = i;
        while (j < n && a[i].first == a[j].first)
            ++ j;
        b[m ++] = i;
        i = j - 1;
    }
    for (int j = 0 ; j + 1 < m ; ++ j) {
        int x = b[j] , y = b[j + 1];
        if (a[x].first ^ a[y].first) {
            printf("1 %d %d\n" , a[x].second , a[y].second);    
            return 0;
        }
    }
    return 0;
}