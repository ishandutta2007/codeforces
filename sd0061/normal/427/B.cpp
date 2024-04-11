#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 200005
int n , t , c , s[N];
void work() {
    int i , x , ans = 0;
    scanf("%d%d%d",&n,&t,&c);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&x);
        s[i] = s[i - 1] + (x > t);
    }
    for (i = c ; i <= n ; ++ i)
        ans += !(s[i] - s[i - c]);
    printf("%d\n" , ans);
}

int main()
{
    work();
    return 0;
}