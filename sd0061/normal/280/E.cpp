#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 12005;

struct range {
    double L , R;
    double a , b , c;
}s[N] , t[N]; 
int cnt;
double value[N];
int n;
double Q , A , B , a[N];

void work() {
    scanf("%d%lf%lf%lf" , &n , &Q , &A ,&B);
    for (int i = 0 ; i < n ; ++ i)
        scanf("%lf" , &a[i]);
    reverse(a , a + n);
    cnt = 1;
    s[0].L = 1 , s[0].R = Q;
    s[0].a = 1;
    s[0].b = -a[0] - a[0];
    s[0].c = (double)a[0] * a[0];

    for (int i = 1 ; i <= n ; ++ i) {
        int p = -1;
        double w , mn;
        for (int j = 0 ; j < cnt ; ++ j) {
            double x = -s[j].b / (s[j].a + s[j].a);
            if (s[j].L <= x && x <= s[j].R) {
                p = j , w = x;
                mn = s[j].a * x * x + s[j].b * x + s[j].c;
                break;
            }
        }
        if (!~p) {
            p = cnt - 1;
            w = s[p].R;
            double mnR = s[p].a * w * w + s[p].b * w + s[p].c;
            p = 0;
            w = s[p].L;
            double mnL = s[p].a * w * w + s[p].b * w + s[p].c;
            if (mnR < mnL) {
                p = cnt - 1;
                w = s[p].R;
                mn = mnR;
            } else {
                p = 0;
                w = s[p].L;
                mn = mnL;
            }
        }
        value[i] = w;
        if (i == n) {
            double res = 0;
            for (i = n - 1 ; i >= 0 ; -- i) {
                printf("%.10f%c" , w , " \n"[!i]);
                res += (w - a[i]) * (w - a[i]);
                if (w + A <= value[i] && value[i] <= w + B)
                    w = value[i];
                else if (w + A > value[i])
                    w += A;
                else
                    w += B;
            }
            printf("%.10f\n" , res);
            break;
        }
        int newcnt = 0;
        for (int j = 0 ; j < cnt ; ++ j) {
            if (j < p) {
                t[newcnt].L = s[j].L - B;
                t[newcnt].R = s[j].R - B;
                t[newcnt].c = s[j].c + s[j].b * B + s[j].a * B * B;
                t[newcnt].b = s[j].b + s[j].a * B * 2;
                t[newcnt].a = s[j].a;
                newcnt ++;
            } else if (j == p) {

                t[newcnt].L = s[j].L - B;
                t[newcnt].R = w - B;
                t[newcnt].c = s[j].c + s[j].b * B + s[j].a * B * B;
                t[newcnt].b = s[j].b + s[j].a * B * 2;
                t[newcnt].a = s[j].a;
                newcnt ++;
            
                t[newcnt].L = w - B;
                t[newcnt].R = w - A;
                t[newcnt].a = t[newcnt].b = 0;
                t[newcnt].c = mn;
                newcnt ++;

                t[newcnt].L = w - A;
                t[newcnt].R = s[j].R - A;
                t[newcnt].c = s[j].c + s[j].b * A + s[j].a * A * A;
                t[newcnt].b = s[j].b + s[j].a * A * 2;
                t[newcnt].a = s[j].a;
                newcnt ++;
            } else {
                t[newcnt].L = s[j].L - A;
                t[newcnt].R = s[j].R - A;
                t[newcnt].c = s[j].c + s[j].b * A + s[j].a * A * A;
                t[newcnt].b = s[j].b + s[j].a * A * 2;
                t[newcnt].a = s[j].a;
                newcnt ++;
            }
        }
        cnt = 0;
        for (int j = 0 ; j < newcnt ; ++ j) {
            if (t[j].R < 1.0)
                continue;
            t[j].L = max(t[j].L , 1.0);
            s[cnt] = t[j];
            s[cnt].a = s[cnt].a + 1;
            s[cnt].b = s[cnt].b - a[i] - a[i];
            s[cnt].c = s[cnt].c + (double)a[i] * a[i];
            cnt ++;
        }
    }
}

int main() {
    work();
    return 0;
}