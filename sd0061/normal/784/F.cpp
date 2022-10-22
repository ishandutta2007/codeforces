#include <bits/stdc++.h>
using namespace std;

int main() {
    int n , a[100];
    cin >> n;
    for (int i = 0 ; i < n ; ++ i) {
        cin >> a[i];
    }
    int w = 0;
    for (int i = 0 ; i < 50000 ; ++ i) {
        for (int j = 0 ; j < 50000 ; ++ j) {
            w += (i ^ j);
        }
    }
    w %= 1000;
    if (w < 0) w = -w;
    n += w;
    sort(a , a + n - w);
    for (int i = 0 ; i < n - w ; ++ i) {
        printf("%d%c" , a[i] , " \n"[i + 1 == n]);
    }
}