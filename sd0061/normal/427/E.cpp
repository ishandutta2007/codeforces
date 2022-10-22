#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 1000005
int n , m , p[N];
long long ans;
void work() {
    int i ;
    scanf("%d%d",&n,&m);
    for (i = 0 ; i < n  ; ++ i)
        scanf("%d",&p[i]);
    for(i = 0 ; i < n / 2 ; i += m)
        ans += p[n / 2] - p[i];
    for(i = n - 1 ; i > n / 2 ; i -= m)
        ans += p[i] - p[n / 2];
    cout << ans + ans << endl;
}

int main()
{
    work();
    return 0;
}