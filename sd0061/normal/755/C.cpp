#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int f[N];
int getf(int x) {
    return x == f[x] ? x : f[x] = getf(f[x]);
}

int main() {
    int n , x;
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        f[i] = i;
    }
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &x);
        f[getf(i)] = getf(x);
    }
    int res = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        res += (getf(i) == i);
    }
    cout << res << endl;
}