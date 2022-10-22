#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <set>
using namespace std;
typedef long long LL;
const int N = 1005;
const int Q = 1e9 + 7;
int n , m;
char g[N][N];
int num[N][N] , f[N * N] , s[N * N];
int getf(int x) {
    return x == f[x] ? x : f[x] = getf(f[x]);
}
void work() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < n ; ++ i)
        scanf("%s" , g[i]);
    int cnt = 0;
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < m ; ++ j) {
            num[i][j] = cnt;
            f[cnt] = cnt;
            if (g[i][j] == '.') {
                s[cnt] = 1;
                if (i > 0 && g[i - 1][j] == '.') {
                    int x = getf(cnt) , y = getf(cnt - m);
                    if (x != y) {
                        s[y] += s[x];
                        f[x] = y;
                    }
                }
                if (j > 0 && g[i][j - 1] == '.') {
                    int x = getf(cnt) , y = getf(cnt - 1);
                    if (x != y) {
                        s[y] += s[x];
                        f[x] = y;
                    }
                }                
            }
            ++ cnt;
        }
    }
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < m ; ++ j) {
            if (g[i][j] != '.') {
                set<int> Hash;
                if (i > 0) Hash.insert(getf(num[i - 1][j]));
                if (i + 1 < n) Hash.insert(getf(num[i + 1][j]));
                if (j > 0) Hash.insert(getf(num[i][j - 1]));
                if (j + 1 < m) Hash.insert(getf(num[i][j + 1]));                
                int cnt = 1;
                for (auto &x : Hash)
                    cnt += s[x];
                g[i][j] = '0' + cnt % 10;
            }
        }
    }
    for (int i = 0 ; i < n ; ++ i)
        puts(g[i]);
    
}

int main() {
    work();
    return 0;
}