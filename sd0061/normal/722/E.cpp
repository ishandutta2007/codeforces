#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
const int Q = 1e9 + 7;
int n , m , K , s;
int P[N] , I[N];
pair<int , int> a[N];

int cmp(pair<int , int> A , pair<int , int> B) {
    return A.first + A.second < B.first + B.second;
}
int C(int x , int y) {
    if (y < 0 || y > x) {
        return 0;
    }
    return (LL)P[x] * I[y] % Q * I[x - y] % Q;
}
void add(int &A , int B) {
    A += B;
    if (A >= Q) {
        A -= Q;
    }
}

int f[20][2005];
int main() {
    P[0] = P[1] = I[0] = I[1] = 1;
    for (int i = 2 ; i < N ; ++ i) {
        I[i] = (LL)(Q - Q / i) * I[Q % i] % Q;
    }
    for (int i = 2 ; i < N ; ++ i) {
        P[i] = (LL)P[i - 1] * i % Q;
        I[i] = (LL)I[i - 1] * I[i] % Q;
    }
    scanf("%d%d%d%d" , &n , &m , &K , &s);
    for (int i = 0 ; i < K ; ++ i) {
        scanf("%d%d" , &a[i].first , &a[i].second);
        -- a[i].first , -- a[i].second;
    }
    a[K ++] = make_pair(n - 1 , m - 1);
    sort(a , a + K , cmp);

    int res = 0;
    for (int k = 0 ; k <= 20 ; ++ k) {
        for (int i = 0 ; i < K ; ++ i) {
            f[k][i] = C(a[i].first + a[i].second , a[i].first);
            for (int j = 0 ; j < i ; ++ j) {
                add(f[k][i] , Q - (LL)f[k][j] * C(a[i].first - a[j].first + a[i].second - a[j].second , a[i].first - a[j].first) % Q);
            }
            if (k) add(f[k][i] , Q - f[k - 1][i]);
        }
        add(res , (LL)s * f[k][K - 1] % Q);
        s = (s + 1) / 2;
        for (int i = 0 ; i < K ; ++ i) {
            if (k) add(f[k][i] , f[k - 1][i]);
        }
    }
    add(res , (C(n + m - 2 , m - 1) + Q - f[20][K - 1]) % Q);
    res = (LL)res * I[n + m - 2] % Q * P[n - 1] % Q * P[m - 1] % Q;
    cout << res << endl;
}