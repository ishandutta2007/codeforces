#include <bits/stdc++.h>
using namespace std;
map<int, int> cnt;
int n , m;
int a[200005] , b[200005];

bool check(int v) {
    long long rem = m;
    for (int i = 0 ; i < n ; ++ i) {
        long long g = (long long)a[i] * v;
        if (g > b[i]) {
            g -= b[i];
            if (rem < g)
                return 0;
            rem -= g;
        }
    }
    return 1;
}

int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
    }
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &b[i]);
    }
    long long l = 0 , r = 2e9 ;
    while (l < r) {
        long long mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
}