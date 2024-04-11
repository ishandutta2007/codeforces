#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1005;
const int Q = 1e9 + 7;
int C[N][N];
void work() {
    int res = 1 , n , s = 0 , x;
    cin >> n;
    for (int i = 0 ; i <= 1000 ; ++ i) {
        C[i][0] = 1;
        for (int j = 1 ; j <= i ; ++ j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Q;
        }
    }
    for (int i = 0 ; i < n ; ++ i) {
        cin >> x;
        res = (LL)res * C[s + x - 1][x - 1] % Q;
        s += x;
    }
    cout << res << endl;
}

int main() {
    work();    
    return 0;
}