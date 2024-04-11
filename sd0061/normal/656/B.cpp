#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n , a[N] , b[N];

int main() {
    cin >> n;
    for (int i = 0 ; i < n ; ++ i)
        cin >> a[i];
    for (int i = 0 ; i < n ; ++ i)
        cin >> b[i];
    int sum = 0;
    for (int i = 0 ; i < 720720 ; ++ i) {
        int f = 0;
        for (int j = 0 ; j < n ; ++ j)
            f |= (i % a[j] == b[j]);
        sum += f;
    }
    printf("%.10f\n" , 1.0 * sum / 720720);
    return 0;
}