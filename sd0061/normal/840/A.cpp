#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n , res[N];
pair<int , int> a[N] , b[N];

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i].first);
        a[i].second = i;
    }
    sort(a , a + n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &b[i].first);
        b[i].second = i;
    }
    sort(b , b + n);
    for (int i = 0 ; i < n ; ++ i) {
        res[b[i].second] = a[n - 1 - i].first;
    }
    for (int i = 0 ; i < n ; ++ i) {
        printf("%d%c" , res[i] , " \n"[i == n - 1]);
    }

}