#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n , m , a[N] , b[N];
int main() {
    cin >> n >> m;
    for (int i = 0 ; i < n ; ++ i) {
        cin >> a[i];
    }
    for (int i = 0 ; i < m ; ++ i) {
        cin >> b[i];
    }
    sort(b , b + m);
    for (int i = 0 , j = 0 ; i < n ; ++ i) {
        if (!a[i]) {
            a[i] = b[j ++];
        }
    }
    bool flag = 1;
    for (int i = 0 ; i + 1 < n ; ++ i) {
        if (a[i] >= a[i + 1]) {
            flag = 0;
        }
    }
    if (!flag || b[0] < b[m - 1]) {
        puts("Yes");
    } else {
        puts("No");
    }
}