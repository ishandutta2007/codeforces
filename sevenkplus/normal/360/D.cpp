#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 10010

template <typename T> 
T gcd(T a, T b) {
    if (b == 0) return a; 
    return gcd(b, a%b); 
}

int n, m, P; 
int a[N], o[N]; 
int w[N], L; 
int s[N];

int pow (int x, int y) {
    int s = 1, t = x; 
    while (y) {
        if (y&1) s = (ll)s*t%P; 
        y /= 2; 
        t = (ll)t*t%P; 
    }
    return s; 
}

int phi (int x) {
    int p = 1; 
    for (int i = 2; i*i <= x; i ++) 
        if (x % i == 0) {
            p *= (i-1); x /= i; 
            while (x % i == 0) x /= i, p *= i; 
        }
    if (x != 1) p *= (x-1); 
    return p; 
}

int c[N], Lc; 

int main()
{
    scanf("%d%d%d", &n, &m, &P); 
    for (int i = 1; i <= n; i ++) 
        scanf("%d", a+i); 
    int g = P-1; 
    for (int i = 1; i <= m; i ++) {
        int b; scanf("%d", &b); 
        g = gcd(g, b%(P-1)); 
    }
    int P1 = P-1; 
    for (int i = 1; i*i <= P1; i ++) 
        if (P1%i == 0) {
            w[L++] = i; 
            if (i*i != P1) w[L++] = P1/i; 
        }
    sort(w, w+L); 
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < L; j ++)
            if (pow(a[i], w[j]) == 1) {
                o[i] = w[j]; break; 
            }
    }
    for (int i = 1; i <= n; i ++)
        c[Lc ++] = gcd(P-1, (int)((ll)(P1/o[i])*g%P1)); 
    /*
    sort(c, c + Lc); 
    for (int i = 0; i < Lc; i ++) if (c[i] != -1) 
        for (int j = i+1; j < Lc; j ++) 
            if (c[j] != -1 && c[j] % c[i] == 0) c[j] = -1; 
    int Lc2 = 0;
    for (int i = 0; i < Lc; i ++)
        if (c[i] != -1)
            c[Lc2 ++] = c[i]; 
    Lc = Lc2; 
    */
    /*
    for (int i = 0; i < Lc; i++)
        printf("%d%c", c[i], i == Lc-1?'\n': ' ');
    */
    for (int i = 0; i < L; i ++) 
        s[i] = phi(P1/w[i]); 
    int S = 0; 
    for (int i = 0; i < L; i ++) 
        for (int j = 0; j < Lc; j ++) 
            if (w[i] % c[j] == 0) {
                S += s[i]; break; 
            }
    printf ("%d\n", S); 
    return 0;
}