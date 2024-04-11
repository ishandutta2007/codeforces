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
#include <set>
#include <map>
typedef long long LL;
using namespace std;
const int N = 1100005;
const int M = 100005;
int n , m , pos[M];
char str[N] , text[N];
int u[N][26] , val[N] , cnt;
int f[M] , pre[M];

void print(int x) {
    if (x == 0) return;
    print(f[x]);
    printf("%s " , text + pos[pre[x]]);
}

int main() {
    scanf("%d%s%d" , &n , str , &m);
    int cnt = 1; val[1] = -1;
    for (int i = 0 , L = 0 ; i < m ; ++ i) {
        scanf("%s" , text + L);
        int x = 1;
        int T = strlen(text + L);
        for (int j = L + T - 1 ; j >= L ; -- j) {
            int c = tolower(text[j]) - 'a';
            if (!u[x][c]) {
                u[x][c] = ++ cnt;
                val[cnt] = -1;
            }
            x = u[x][c];
        }
        val[x] = i;        
        pos[i] = L;
        L += T + 1;
    }
    memset(f , -1 , sizeof(f));
    for (int i = 0 ; i < n ; ++ i) {
        if (i && !~f[i]) continue;
        //printf("%d\n" , i);
        int x = 1;
        for (int j = i ; j < n ; ++ j) {
            int c = str[j] - 'a';
            if (!u[x][c])
                break;
            x = u[x][c];
            if (~val[x]) {
                f[j + 1] = i;
                pre[j + 1] = val[x];
            }
        }
    }
    print(n);        
    return 0;
}