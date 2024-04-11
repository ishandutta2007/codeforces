#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;

int n , m;
bool f[N];
char str[N];
void work() {
    int i , j , x , y;
    scanf("%s" , str + 1);
    n = strlen(str + 1);
    scanf("%d" , &m);
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d" , &x);
        f[x] ^= 1;
    }
    for (i = 2 ; i + i <= n ; ++ i)
        f[i] ^= f[i - 1];    
    for (i = 1 ; i + i <= n ; ++ i)
        if (f[i]) {
            swap(str[i] , str[n - i + 1]);
        }
    puts(str + 1);
}

int main() {
    work();
    return 0;
}