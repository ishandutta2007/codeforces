#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , m;
int a[N];
void work() {
    int i , j , k , res;
    cin >> n >> m;
    res = n * (n + 1) * (n + 2) / 6;
    for (i = 0 ; i < n ; ++ i)
        a[i] = i + 1;
    do {
        int sum = 0;
        for (i = 0 ; i < n ; ++ i) {
            for (j = i ; j < n ; ++ j) {
                int x = 1 << 30;
                for (k = i ; k <= j ; ++ k)
                    x = min(x , a[k]);
                sum += x;
            }
        }
        if (sum == res) {
            if (!-- m) {
                for (i = 0 ; i < n ; ++ i)
                    printf("%d " , a[i]);
                return;
            }
        }
    } while (next_permutation(a , a + n));
}

int main() {
//    freopen("1" , "r" , stdin);
    work();
    return 0;
}