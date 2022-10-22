#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;

int n , m , K;
int a[N] , b[N];

void work() {
    int i , x , y;
    scanf("%d%d%d",&n,&m,&K);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d" , &a[i]) , b[a[i]] = i;
    LL res = 0;
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d" , &x);
        y = b[x];
        res += y / K + 1;
        if (y) {
            swap(a[y] , a[y - 1]);
            b[a[y]] = y;
            b[a[y - 1]] = y - 1;        
        }
    }
    cout << res << endl;
}

int main() {
    //freopen("1" , "r" , stdin);
    work();
    return 0;
}