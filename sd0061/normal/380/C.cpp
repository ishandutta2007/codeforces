#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
//typedef long long LL;

const int N = 1000005;
int n , m;
char s[N];
struct stree {
    int a , l , r;
}t[20][N];
stree operator + (stree A , stree B) {
    int t = min(A.l , B.r);
    return (stree) {A.a + B.a + t , A.l + B.l - t , A.r + B.r - t};
}

void work() {
    int i , j , x , y , k;
    scanf("%s" , s + 1) , n = strlen(s + 1);
    for (i = 1 ; i <= n ; ++ i)
        if (s[i] == '(')
            t[0][i] = (stree) {0 , 1 , 0};
        else
            t[0][i] = (stree) {0 , 0 , 1};
    for (j = 1 ; 1 << j <= n ; ++ j)
        for (i = 1 ; i + (1 << j) - 1 <= n ; ++ i)
            t[j][i] = t[j - 1][i] + t[j - 1][i + (1 << j - 1)];
    scanf("%d",&m);
    while (m --) {
        stree res = {0 , 0 , 0};
        scanf("%d%d",&x,&y) , k = y - x + 1;
        for (i = 19 ; i >= 0 ; -- i)
            if (k >= (1 << i)) {
                res = res + t[i][x];
                x += (1 << i) , k -= (1 << i);
            }
        printf("%d\n" , res.a << 1);
    }
}

int main()
{
    work();
    return 0;
}