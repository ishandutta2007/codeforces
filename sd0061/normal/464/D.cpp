#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , K;
double f[2][805];
void work() {
    int i , j , cur = 0 , nxt = 1;
    cin >> n >> K;
    for (i = n - 1 ; i >= 0 ; -- i) {
        for (j = 1 ; j <= 800 ; ++ j) {
            f[nxt][j] = j * f[cur][j] + f[cur][j + 1];
            f[nxt][j] += j * (j + 3) / 2;
            f[nxt][j] /= K , f[nxt][j] /= j + 1;
            f[nxt][j] += (1 - 1.0 / K) * f[cur][j];
        }
        swap(cur , nxt);
    }
    printf("%.10f\n" , K * f[cur][1]);
}

int main() {
    work();
    return 0;
}