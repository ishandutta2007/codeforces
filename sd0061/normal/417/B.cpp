#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <map>
typedef long long LL;
using namespace std;
#define N 100005

int n , t[N];

void work()
{
    int i , k , x;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d",&x,&k);
        if (x + 1 <= t[k])
            continue;
        else if (x != t[k])
            break;
        t[k] = x + 1;
    }
    puts(i < n ? "NO" : "YES");
}

int main()
{
//    freopen("~input.txt" , "r" , stdin);
        work();
    return 0;
}