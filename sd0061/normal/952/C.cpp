#include <bits/stdc++.h>
using namespace std;
const int N = 55;

int n , a[N] , b[N];
int main() {
    cin >> n;
    for (int i = 0 ; i < n ; ++ i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b , b + n);
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j + 1 < n - i ; ++ j) {
            if (abs(a[j] - a[j + 1]) > 1) {
                puts("NO");
                return 0;
            }
        }
        int x = 0;
        for (int j = 1 ; j < n - i ; ++ j) {
            if (a[j] > a[x]) {
                x = j;
            }
        }
        int t = a[x];
        for (int j = x ; j + 1 < n - i ; ++ j) {
            a[j] = a[j + 1];
        }
        a[n - i - 1] = t;
    }
    puts("YES");
}