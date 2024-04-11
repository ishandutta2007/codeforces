#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 100005;
typedef long long LL;
#define x first
#define y second
typedef pair<int , int> Point;
Point operator - (const Point &A , const Point &B) {
    return Point(A.x - B.x , A.y - B.y);
}

int n;
Point a[N];

void work() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d%d",&a[i].x , &a[i].y);
    }
    double res = 0 , power = pow(2 , -n);
    double p = 1 - (1 + n + (LL)n * (n - 1) / 2) * power;
    for (int j = 1 ; j < min(n , 100) ; ++ j) {
        double delta = 0;
        for (int i = 0 ; i < n ; ++ i) {
            Point V = a[(i + j) % n] - a[i];
            int grid = abs(__gcd(V.x , V.y));
            LL area = (LL)a[i].x * a[(i + j) % n].y - (LL)a[i].y * a[(i + j) % n].x;
            delta += area / 2.0;
            delta -= grid / 2.0;
        }
        res += delta * (pow(2 , -j - 1) - power) / p;
    }
    printf("%.15f\n" , res + 1);
}

int main() {
    work();
    return 0;
}