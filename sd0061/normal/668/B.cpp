#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n , m;
int res[N];

int main() {
    int p0 = 0 , p1 = 1;
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < m ; ++ i) {
        int t;
        scanf("%d" , &t);
        if (t == 1) {
            int x;
            scanf("%d" , &x);
            x = (x % n + n) % n;
            p0 += x , p0 %= n;
            p1 += x , p1 %= n;
        } else {
            p0 ^= 1;
            p1 ^= 1;
        }
        //printf("%d %d\n" , p0 , p1);
    }
    for (int i = 0 ; i < n ; i += 2) {
        res[p0] = i;
        p0 += 2 , p0 %= n;
    }
    for (int i = 1 ; i < n ; i += 2) {
        res[p1] = i;
        p1 += 2 , p1 %= n;
    }
    for (int i = 0 ; i < n ; ++ i) {
        printf("%d%c" , res[i] + 1 ,  " \n"[i + 1 == n]);
    }

}