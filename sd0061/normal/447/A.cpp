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

const int N = 100005;
int n , p , a[N];
void work() {
    int i , j ;
    scanf("%d%d",&p,&n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&a[i]);
        for (j = 1 ; j < i ; ++ j)
            if (a[i] % p == a[j] % p)
                break;
        if (j < i)
            break;
    }
    if (i > n)
        i = -1;
    printf("%d\n" , i);
}

int main()
{
    //while (~scanf("%d",&n))
        work();
    return 0;
}