#include <iostream>
#include <cmath>
using namespace std;
const int N = 200000 + 10;

int n;
struct P {
    int x, y;
} p[N];

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int pnt_on_edge(int u, int v) {
    P A, B;
    A = p[u], B = p[v];
    if (A.x > B.x) swap(A, B);
    if (A.y > B.y) swap(A.y, B.y);
    // printf("[%d, %d] [%d, %d]\n", A.x, A.y, B.x, B.y);
    int dx = B.x - A.x;
    int dy = B.y - A.y;
    int g = gcd(dx, dy);

    return g;
}
double pw[N];
double area_of_edge(int u, int v) {
    return (1LL * p[u].x * p[v].y - 1LL * p[u].y * p[v].x) / 2.0; 
}
double pro_of_edge(int u, int v) {
    int cnt = (n - 2 - (v - u - 1));
    // printf("cnt = %d, n = %d\n", cnt, n);
    double A = pw[n - cnt] - pw[n];
    double B = 1 - 1.0 * (1 + n + n * (n - 1) / 2) * pw[n];
    //return 1.0 * ((1LL<<cnt) - 1) / ((1LL<<n) - 1 - n - n * (n - 1) / 2);
    return A / B;
}

int main() {
    pw[0] = 1;
    for (int i = 1; i < N; i ++) pw[i] = pw[i-1] * 0.5;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i + n] = p[i];
    }
    double S = 0, E = 0;
    int B = min(60, n - 1);

    for (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= i + B; j ++) {
            /*
            printf("i = %d, j = %d\n", i, j);
            printf("cnt = %d\n", pnt_on_edge(i ,j));
            printf("are = %.5f\n", area_of_edge(i, j));
            printf("pro = %.5f\n", pro_of_edge(i ,j));
            */
            E += pro_of_edge(i, j) * pnt_on_edge(i, j);
            S += pro_of_edge(i, j) * area_of_edge(i, j);
        }
    }
    double ans = S + 1 - E / 2;
    printf("%.10f\n", ans);
}