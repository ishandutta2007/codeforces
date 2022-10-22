#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
typedef long long LL;
using namespace std;
const int N = 1000005;
const int Q = 1e9 + 7;
struct Point {
    int x , y;
    Point (int _x = 0 , int _y = 0) {
        x = _x , y = _y;
    }
    LL operator ^ (const Point &R) const {
        return (LL)x * R.y - (LL)y * R.x;
    }
};

int n;
Point p[N];
int f[N] , sx[N] , sy[N] , S[N];

int wtf(int i , int l , int r) {
    int A = (f[r] + Q - f[l]) % Q;
    int B = (LL)(r - l) * S[i] % Q;
    int x = (sx[r] + Q - sx[l]) % Q;
    int y = (sy[r] + Q - sy[l]) % Q;
    int C = (((LL)x * p[i].y - (LL)y * p[i].x) % Q + Q) % Q;        
    return ((LL)A - B + Q + C) % Q;
}

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d%d" , &p[i].x , &p[i].y);
    }
    reverse(p , p + n);
    for (int i = 0 ; i < n ; ++ i) {
        p[i + n] = p[i];    
    }
    LL area = 0;
    for (int i = 0 ; i + 1 < n + n ; ++ i) {
        LL delta = (p[i] ^ p[i + 1]);
        if (i < n)
            area += delta;
        S[i + 1] = (S[i] + ((delta % Q + Q) % Q)) % Q;
    }
    for (int i = 0 ; i + 1 < n + n ; ++ i) {
        f[i + 1] = (f[i] + S[i]) % Q;
        sx[i + 1] = ((LL)sx[i] + p[i].x % Q + Q) % Q;
        sy[i + 1] = ((LL)sy[i] + p[i].y % Q + Q) % Q;
    }
    
    int res = ((LL)n * (n - 3) / 2) % Q * (area % Q) % Q;
    LL cur = 0;
    for (int i = 0 , j = 0 ; i < n ; ++ i) {
        while ((cur + (p[j] ^ p[i])) < (area + 1) / 2) {
            cur += (p[j] ^ p[j + 1]);
            ++ j;
        }
        res += Q - wtf(i , i , j) , res %= Q;
        res += Q - (LL)(i + n - j) * (area % Q) % Q , res %= Q;
        res += wtf(i , j , i + n) , res %= Q;
        cur -= (p[i] ^ p[i + 1]);
    }    
    printf("%d\n" , res);
    return 0;
}