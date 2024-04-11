#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
const int N = 100005;
typedef long long LL;
int n , m;
int a[N] , b[N] ;
LL c[N];
void work() {
    int i , j;
    LL sumA = 0 , sumB = 0;
    scanf("%d%d",&m,&n);
    for (i = 0 ; i < m ; ++ i)
        scanf("%d",&a[i]) , sumA += a[i];
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&b[i]) , sumB += b[i];
    LL res = sumA + sumB - max(*max_element(a , a + m) , *max_element(b , b + n));
    LL sum = 0;
    for (i = 0 ; i < m ; ++ i) {
        c[i] = min((LL)a[i] , sumB);
    }
    sort(c , c + m , greater<LL>());
    sum = max(sumB , c[0]);
    for (i = 1 ; i < m ; ++ i) {
        sum += c[i];
    }
    res = min(res , sum);
    for (i = 0 ; i < n ; ++ i) {
        c[i] = min((LL)b[i] , sumA);
    }
    sort(c , c + n , greater<LL>());
    sum = max(sumA , c[0]);
    for (i = 1 ; i < n ; ++ i) {
        sum += c[i];
    }
    res = min(res , sum);



    cout << res << endl;
}


int main() {
    work();
    return 0;
}