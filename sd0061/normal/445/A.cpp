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
//#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;

const int N = 105;
int n , m;
char s[N][N];
void work() {
    int i , j;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , s[i] + 1);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            if (s[i][j] == '.')
                s[i][j] = "BW"[(i + j) & 1];
    for (i = 1 ; i <= n ; ++ i)
        puts(s[i] + 1);
}

int main()
{
        work();
    return 0;
}