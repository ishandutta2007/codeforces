#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 200005;
const int Q = 1e9 + 7;
LL p[N] , I[N];

void init() {
    p[0] = p[1] = I[0] = I[1] = 1;
    for (int i = 2 ; i < N ; ++ i)
        I[i] = (Q - Q / i) * I[Q % i] % Q;
    for (int i = 2 ; i < N ; ++ i) {
        p[i] = p[i - 1] * i % Q;
        I[i] = I[i - 1] * I[i] % Q;
    }
}
LL C(int x , int y) {
    return p[x] * I[y] % Q * I[x - y] % Q;
}
int h , w , n , f[N];
pair<int , int> a[N];
void work() {
    scanf("%d%d%d" , &h , &w , &n);
    for (int i = 0 ; i < n ; ++ i)
        scanf("%d%d" , &a[i].first , &a[i].second);
    a[n] = make_pair(h , w);
    sort(a , a + n + 1);
    for (int i = 0 ; i <= n ; ++ i) {        
        int x = a[i].first , y = a[i].second;
        f[i] = C(x + y - 2 , x - 1);
        for (int j = 0 ; j < i ; ++ j) {
            int X = a[j].first , Y = a[j].second;
            if (Y <= y) {
                f[i] += Q - f[j] * C(x + y - X - Y , y - Y) % Q;
                f[i] %= Q;
            }
        }
    }
    cout << f[n] << endl; 
}

int main() {
    init();
    work();
    return 0;
}