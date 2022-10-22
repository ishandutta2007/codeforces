#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5005;
int n , K , Q;
int a[N];
map<int , int> f;

void work() {
    int i , j , k , x;
    scanf("%d%d",&n,&K);
    f[0] = 0;
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
        for (j = 1 ; j <= K ; ++ j) {
            f[j * a[i]] = j;            
        }
    }
    scanf("%d" , &Q);
    for (i = 0 ; i < Q ; ++ i) {
        scanf("%d" , &x);
        int res = 1 << 30;
        for (j = 0 ; j < n ; ++ j) {
            for (k = 1 ; k <= K && a[j] * k <= x ; ++ k)
                if (f.count(x - a[j] * k))
                    res = min(res , f[x - a[j] * k] + k);
        }
        if (res > K)
            res = -1;
        printf("%d\n" , res);
    }
}

int main () {
    work();
    return 0;
}