#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long long LL;
const int N = 100005;
int n , a[N] , b[N];
int c[N] , d[N];
void work() {
    int i , j;
    scanf("%d",&n);
    for (i = 0 ; i < n;  ++ i)
        scanf("%d",&a[i]) , b[i] = a[i];
    sort(b , b + n);
    int l = 1 << 30 , r = -1 << 30;
    for (i = 0 ; i < n ; ++ i)
        if (a[i] != b[i])
            l = min(l , i) , r = max(r , i);
    if (1 << 30 == l) {
        puts("yes\n1 1");
        return;
    }
    j = 0;
    for (i = l ; i <= r ; ++ i)
        c[j] = a[i] , d[j ++] = b[i];
    reverse(c , c + j);
    for (i = 0 ; i < j ; ++ i)
        if (c[i] != d[i])
            break;
    if (i < j)
        puts("no");
    else{
        puts("yes");
        printf("%d %d\n" , l + 1 , r + 1);
    }
}

int main(){
    //while (~scanf("%d",&n))
        work();
    return 0;
}