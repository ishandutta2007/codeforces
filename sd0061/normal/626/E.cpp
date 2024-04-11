#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <queue>
typedef long long LL;
using namespace std;
const int N = 200005;
int n , a[N];
LL s[N];
long double res;
int L , R , Prev;
bool f[N];
bool check(int ii , int jj , long double val) {
    long double sum = 0;
    if (ii == jj) {
        sum += a[ii] - val;
    } else {
        sum += a[ii] - val;
        sum += a[jj] - val;
    }

    int l = 0 , r = min(ii - 1 , n - jj) , m;
    while (l < r) {
        m = l + r + 1 >> 1;
        if (a[ii - m] + a[n - m + 1] >= val + val)
            l = m;
        else
            r = m - 1;
    }    
    sum -= val * l * 2;
    sum += s[ii - 1] - s[ii - l - 1];
    sum += s[n] - s[n - l];
    Prev = l;
    return sum <= 0;
}

int main() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);       
    }
    sort(a + 1 , a + n + 1);
    for (int i = 1 ; i <= n ; ++ i) {
        s[i] = s[i - 1] + a[i];
    }
    res = -1e30;
    for (int i = 1 ; i <= n ; ++ i) {
        long double l = 0 , r = 2e6 , m;
        for (int T = 0 ; T < 100 ; ++ T) {
            m = (l + r) / 2;
            if (check(i , i , m))
                r = m;
            else
                l = m;
        }
        if (r - a[i] > res) {
            res = r - a[i];
            L = R = i;
        }
    }
    for (int i = 1 ; i + 1 <= n ; ++ i) {
        long double l = 0 , r = 2e6 , m;
        for (int T = 0 ; T < 100 ; ++ T) {
            m = (l + r) / 2;
            if (check(i , i + 1 , m))
                r = m;
            else
                l = m;
        }
        if (r - (a[i] + a[i + 1]) / 2.0 > res) {
            res = r - (a[i] + a[i + 1]) / 2.0;
            L = i , R = i + 1;
        }
    }
    //printf("%.10f\n" , res);
    long double l = 0 , r = 2e6 , m;
    for (int T = 0 ; T < 100 ; ++ T) {
        m = (l + r) / 2;
        if (check(L , R , m))
            r = m;
        else
            l = m;
    }
    check(L , R , r);
    f[L] = f[R] = 1;
    for (int i = 1 ; i <= Prev ; ++ i)
        f[L - i] = f[n + 1 - i] = 1;
    int cnt = ((L == R) ? 1 : 2) + Prev * 2;
    printf("%d\n" , cnt);
    for (int i = 1 ; i <= n ; ++ i)
        if (f[i])
            printf("%d " , a[i]);
    puts("");
    return 0;
}