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
typedef long long LL;
const int N = 1005;
int n , m , K , p;
LL R[N] , C[N];
LL f[N * N] , g[N * N];
void work() {
    int i , j , X , Y; LL x , y;
    scanf("%d%d%d%d",&n,&m,&K,&p);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            scanf("%d",&X) , R[i] += X , C[j] += X;
    priority_queue<LL> QR , QC;
    for (i = 1 ; i <= n ; ++ i)
        QR.push(R[i]);
    for (i = 1 ; i <= m ; ++ i)
        QC.push(C[i]);
    LL res = -1LL << 60;
    for (i = 1 ; i <= K ; ++ i) {
        f[i] = f[i - 1] + QR.top();
        QR.pop() , QR.push(f[i] - f[i - 1] - m * p);
    }
    for (i = 1 ; i <= K ; ++ i) {
        g[i] = g[i - 1] + QC.top();
        QC.pop() , QC.push(g[i] - g[i - 1] - n * p);
    }
    for (i = 0 ; i <= K ; ++ i) {
        res = max(res , f[i] + g[K - i] - (LL)i * (K - i) * p);
    }
    cout << res << endl;
}


int main()
{
        work();
    return 0;
}