#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <cassert>
using namespace std;

typedef long long LL;
const int N = 100005;
const int Q = 1e9 + 7;

int n , m;
char str[N] , p[N];
int num[N];
string t[N];
LL f[N] , g[N];

void work() {
    int i , j;
    scanf("%s%d" , str , &m);
    for (i = 0 ; i < m ; ++ i) {
        scanf("%s" , p);
        num[i] = *p - '0';
        t[i] = p + 3;
    }
    for (i = 0 ; i < 10 ; ++ i) {
        f[i] = i;
        g[i] = 10;
    }
    for (i = m - 1 ; i >= 0 ; -- i) {
        LL F = 0 , G = 1;
        for (j = (int)t[i].size() - 1 ; j >= 0 ; -- j) {
            int k = t[i][j] - '0';
            F += G * f[k] % Q , F %= Q;
            G *= g[k] , G %= Q;
        }
        int x = num[i];
        f[x] = F , g[x] = G;
    }
    n = strlen(str);
    LL F = 0 , G = 1;
    for (i = n - 1 ; i >= 0 ; -- i) {
        int k = str[i] - '0';
        F += G * f[k] % Q , F %= Q;
        G *= g[k] , G %= Q;
    }
    cout << F << endl;
}


int main() {
    work();
    return 0;
}