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
const int N = 205;
const int Q = 1e9 + 7;

int n , a , b , c;
char str[N];
int f[N][N][N];

int F(int x , int y , int z) {
    if (x + y + z > n)
        return 0;
    if (~f[x][y][z])
        return f[x][y][z];
    int &res = f[x][y][z];
    res = 0;
    if (x) res |= F(x + 1 , y , z) || F(x - 1 , y + 1 , z + 1);
    if (y) res |= F(x , y + 1 , z) || F(x + 1 , y - 1 , z + 1);
    if (z) res |= F(x , y , z + 1) || F(x + 1 , y + 1 , z - 1);    
    return res;
}

int main() {
    scanf("%d%s" , &n , str);
    for (int i = 0 ; i < n ; ++ i) {
        if (str[i] == 'R') ++ a;
        if (str[i] == 'B') ++ b;
        if (str[i] == 'G') ++ c;        
    }
    memset(f , -1 , sizeof(f));
    f[a][b][c] = 1;
    if (F(0 , 1 , 0)) putchar('B');
    if (F(0 , 0 , 1)) putchar('G');
    if (F(1 , 0 , 0)) putchar('R');
    puts("");        
    return 0;
}