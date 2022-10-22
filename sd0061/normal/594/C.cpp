#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
using namespace std;
const int N = 100005;
typedef long long LL;
int n , K , xx[N] , yy[N];
struct Point {
    int x , y;
    bool operator < (const Point &R) const {
        if (x != R.x)
            return x < R.x;
        return y < R.y;
    }
}a[N] , b[N];
int dx[N] , dy[N] , Dx , Dy;

int main() {
    scanf("%d%d" , &n , &K);
    //n = 100000 , K = 10;
    for (int i = 0 ; i < n ; ++ i) {
        int x1 , x2 , y1 , y2;
        scanf("%d%d%d%d" , &x1 , &y1 , &x2 , &y2);  
        xx[i] = x1 + x2;
        yy[i] = y1 + y2;
        a[i].x = xx[i] , a[i].y = yy[i];
        dx[Dx ++] = xx[i];
        dy[Dy ++] = yy[i];
        //printf("%d %d\n" , xx[i] , yy[i]);
    }
    sort(a , a + n);
    //for (int i = 0 ; i < n ; ++ i)
    //    printf("%d %d\n" , a[i].x , a[i].y); 
    sort(dx , dx + Dx);
    sort(dy , dy + Dy);
    Dx = unique(dx , dx + Dx) - dx;
    Dy = unique(dy , dy + Dy) - dy;
    LL res = 0x7FFFFFFFFFFFFFFFLL;
    for (int L = 0 ; L <= K ; ++ L) {
        for (int R = Dy - 1 ; R >= Dy - K - 1 ; -- R) {
            if (L <= R) {
                int delta = 0x7FFFFFFF;
                int m = 0;
                for (int i = 0 ; i < n ; ++ i)
                    if (dy[L] <= a[i].y && a[i].y <= dy[R]) {
                        b[m ++] = a[i];
                    }
                if (n - m > K)
                    continue;
                int p = min(K - n + m , m);                
                for (int i = 0 ; i <= p ; ++ i) {
                    //  printf("%d %d\n" , )
                    delta = min(delta , b[m - (p - i) - 1].x - b[i].x);
                }
                //printf("%d %d : %d %d %d\n" , L , R ,  m , delta , (dy[R] - dy[L]));
                res = min(res , (LL)max(2 , delta) * max(2 , (dy[R] - dy[L])));
            }
        }
    }
    cout << res / 4 << endl;
    return 0;
}