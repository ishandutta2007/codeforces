#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <map>
using namespace std;
typedef long long LL;
const int N = 2105;
const int Q = 1e9 + 7;

int n , m;
char s[N] , t[N];
int u[N * N][26] , cnt;
int L[N * N] , R[N * N];
int f[N] , p[N] , w[N];

void print(int x) {
    if (x <= 1) return;
    print(w[x]);
    printf("%d %d\n" , L[p[x]] , R[p[x]]);
}

int main() {
    scanf("%s%s" , s + 1 , t + 1);
    cnt = 1;
    n = strlen(s + 1) , m = strlen(t + 1);
    for (int i = 1 ; i <= n ; ++ i) {
        int x = 1;
        for (int j = i ; j <= n ; ++ j) {
            char c = s[j] - 'a';
            if (!u[x][c]) {
                u[x][c] = ++ cnt;                
            }
            x = u[x][c];
            L[x] = i , R[x] = j;
        }
    }
    for (int i = 1 ; i <= n ; ++ i) {
        int x = 1;
        for (int j = i ; j > 0 ; -- j) {
            char c = s[j] - 'a';
            if (!u[x][c]) {
                u[x][c] = ++ cnt;                
            }
            x = u[x][c];            
            L[x] = i , R[x] = j;
        }
    }
    memset(f , 0x3f , sizeof(f));
    f[1] = 0;
    for (int i = 1 ; i <= m ; ++ i) {
        int x = 1;
        for (int j = i ; j <= m ; ++ j) {
            char c = t[j] - 'a';
            if (!u[x][c]) break;
            x = u[x][c];
            if (f[j + 1] > f[i] + 1) {
                f[j + 1] = f[i] + 1;
                w[j + 1] = i;
                p[j + 1] = x;
            }
        }
    }
    if (f[m + 1] > 1000000000) {
        puts("-1");
    } else {
        printf("%d\n" , f[m + 1]);
        print(m + 1);
    }
    return 0;
}