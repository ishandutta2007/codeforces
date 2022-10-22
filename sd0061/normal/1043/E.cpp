#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n , m;
int a[N] , b[N];
pair<int , int> v[N];
long long res[N] , sum;
int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d%d" , &a[i] , &b[i]);
        v[i] = make_pair(a[i] - b[i] , i);
        sum += b[i];
    }
    sort(v , v + n);
    long long sa = 0 , sb = 0;
    for (int i = 0 ; i < n ; ++ i) {
        int x = v[i].second;

        sum -= b[x];

        res[x] += 1LL * b[x] * i;
        res[x] += sa;
        res[x] += 1LL * a[x] * (n - i - 1);
        res[x] += sum;

        sa += a[x];
    }

    for (int i = 0 ; i < m ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        -- x , -- y;
        int v = min(a[x] + b[y] , a[y] + b[x]);
        res[x] -= v;
        res[y] -= v;
    }

    for (int i = 0 ; i < n ; ++ i) {
        printf("%lld%c" , res[i] , " \n"[i + 1 == n]);
    }
}