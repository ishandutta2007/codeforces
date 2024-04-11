#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , K;
int a[N];
double res = 0;

void dfs(int k) {
    if (k == K) {
        for (int i = 0 ; i < n ; ++ i)
            for (int j = i + 1 ; j < n ; ++ j)
                res += (a[i] > a[j]);
        return;
    }
    for (int i = 0 ; i < n ; ++ i)
        for (int j = i ; j < n ; ++ j) {
            reverse(a + i , a + 1 + j);
            dfs(k + 1);
            reverse(a + i , a + 1 + j);            
        }
}

void work() {
    cin >> n >> K;
    for (int i = 0 ; i < n ; ++ i)
        cin >> a[i];
    dfs(0);
    for (int i = 0 ; i < K ; ++ i)
        res /= (n * (n + 1) / 2);
    printf("%.15f\n" , res);
}

int main() {
//    freopen("1" , "r" , stdin);
    work();
    return 0;
}