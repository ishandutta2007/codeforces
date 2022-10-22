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
char s1[N];
char s2[N];
const double GR = (sqrt(5) + 1) / 2;
LL a[N];
void work() {
    int i , j;
    scanf("%s%s", s1 , s2);
    int n1 = strlen(s1) , n2 = strlen(s2);
    reverse(s1 , s1 + n1);
    reverse(s2 , s2 + n2);
    while (n1 > 0 && s1[n1 - 1] == '0')
        s1[-- n1] = 0;
    while (n2 > 0 && s2[n2 - 1] == '0')
        s2[-- n2] = 0;
    int L = max(n1 , n2);
    for (i = 0 ; i < n1 ; ++ i)
        a[i] = s1[i] - '0';
    for (i = 0 ; i < L ; ++ i)
        a[i] = a[i] - (i < n2 ? (s2[i] - '0') : 0);

    for (i = L ; i > 1 ; -- i) {
        if (a[i] > 1LL << 40) {
            puts(">");
            return;
        }
        if (a[i] < -1LL << 40) {
            puts("<");
            return;
        }
        a[i - 1] += a[i];
        a[i - 2] += a[i];
    }
    //printf("%lld %lld\n" , a[1] , a[0]);
    if (a[1] == 0 && a[0] == 0) {
        puts("=");
    } else if (a[1] * GR + a[0] > 0) {
        puts(">");
    } else {
        puts("<");
    }
}


int main() {
    //freopen("~input.txt" , "r" , stdin);
    //int _; scanf("%d",&_); while (_ --)
        work();
    return 0;
}