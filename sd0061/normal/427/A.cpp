#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 100005
int n;
void work() {
    scanf("%d",&n);
    int i , x , s = 0 , ans = 0;
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d",&x);
        s += x , ans = min(ans , s);
    }
    printf("%d\n" , -ans);
}

int main()
{
    //int T; scanf("%d",&T);
    //while (T --)
        work();
    return 0;
}