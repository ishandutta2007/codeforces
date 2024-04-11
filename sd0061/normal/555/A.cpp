#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 1e9 + 7;

int n , K , a[N];

void work() {
    scanf("%d%d" , &n , &K);
    int cnt = 0 , res = 0;
    for (int i = 0 ; i < K ; ++ i) {
        int m , x;
        scanf("%d" , &m);
        for (int j = 0 ; j < m ; ++ j) {
            scanf("%d" , &a[j]);
        }
        for (int j = 0 ; j < m ; ++ j) {
            int k = j + 1;
            while (k < m && a[k] == a[k - 1] + 1)
                ++ k;
            if (j) {
                cnt += k - j;
                res += k - j;
            } else {
                if (a[j] > 1) {
                    cnt += k - j;
                    res += k - j - 1;
                } else {
                    ++ cnt;
                }
            }
            j = k - 1;
        }        
    }
    cout << res + cnt - 1 << endl;
}

int main() {
    work();    
    return 0;
}