#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int main() {
    int n , a[N] , sum = 0;
    cin >> n;
    for (int i = 0;  i < n ; ++ i) {
        cin >> a[i];
        sum += a[i];
    }
    for (int k = *max_element(a , a + n) ; ; ++ k) {
        if (k * n - sum > sum) {
            printf("%d\n" , k);
            break;
        }
    }


}