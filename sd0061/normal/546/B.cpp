#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n , a[N];

int main() {
    int i , j , res = 0;
    cin >> n;
    for (i = 0 ; i < n ; ++ i) {
        cin >> a[i];        
    }
    sort(a , a + n);
    for (i = 0 ; i < n ; ++ i) {
        if (i && a[i] <= a[i - 1]) {
            res += a[i - 1] + 1 - a[i];
            a[i] = a[i - 1] + 1;
        }
    }
    cout << res << endl;
    return 0;
}