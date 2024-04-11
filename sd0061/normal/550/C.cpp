#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
typedef long long LL;

char s[N];
int n;
int f[N][8] , pre[N][8];

void print(int x , int y) {
    if (~pre[x][y]) {
        if (pre[x][y] < 8) {
            print(x - 1 , pre[x][y]);
            printf("%c" , s[x]);        
        } else {
            print(x - 1 , y);
        }
    } else
        printf("%c" , s[x]);    
}

void work() {
    int i , j , x , y;
    memset(f , 0 , sizeof(f));
    scanf("%s" , s + 1);
    n = strlen(s + 1);    
    for (i = 1 ; i <= n ; ++ i)
        if (s[i] != '0') {
            f[i][(s[i] - '0') % 8] = 1;
            pre[i][(s[i] - '0') % 8] = -1;            
        } else {
            puts("YES\n0");
            return;
        }
    for (i = 1 ; i < n ; ++ i) {
        x = s[i + 1] - '0';
        for (j = 0 ; j < 8 ; ++ j) {
            if (!f[i][j])
                continue;
            f[i + 1][j] = 1 , pre[i + 1][j] = 8;
            y = (j * 10 + x) % 8;
            f[i + 1][y] = 1 , pre[i + 1][y] = j;            
        }
    }
    if (!f[n][0])
        puts("NO");
    else {
        puts("YES");
        print(n , 0);
    }
}

int main() {
    work();
    return 0;
}