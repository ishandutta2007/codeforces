#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
typedef long long LL;

struct Point {
    int x , y;
    Point (int _x = 0 , int _y = 0) {
        x = _x;
        y = _y;
    }
    Point operator - (const Point &R) const {
        return Point(x - R.x , y - R.y);
    }
    double len() const {
        return sqrt((LL)x * x + (LL)y * y);
    }
    void input() {
        scanf("%d%d" , &x , &y);
    }
};
int n;
Point A , B , T , p[N];
pair<double , int> a[N] , b[N];

int main() {
    A.input();
    B.input();
    T.input();
    scanf("%d" , &n);
    double res = 1e60 , sum = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        p[i].input();
        sum += (T - p[i]).len() * 2;
        a[i] = make_pair((A - p[i]).len() - (T - p[i]).len() , i);
        b[i] = make_pair((B - p[i]).len() - (T - p[i]).len() , i);
    }
    sort(a , a + n + 1);
    sort(b , b + n + 1);
    for (int i = 0 ; i <= n && i < 5 ; ++ i) {
        for (int j = 0 ; j <= n && j < 5 ; ++ j) {
            if (a[i].second != b[j].second) {
                res = min(res , a[i].first + b[j].first);
            }
        }
    }
    printf("%.12f\n" , res + sum);
}