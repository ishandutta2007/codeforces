#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N];
int main() {
    int n , K;
    cin >> n >> K;
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
    }
    for (int i = 1 ; i <= n ; ++ i) {
        if (K > i) {
            K -= i;
        } else {
            printf("%d\n" , a[K - 1]);
            return 0;
        }
    }

}