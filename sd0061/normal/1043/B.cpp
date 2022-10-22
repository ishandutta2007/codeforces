#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n , a[N];

int main() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
    }
    for (int i = n ; i > 0 ; -- i) {
        a[i] -= a[i - 1];
    }
    vector<int> v;
    for (int k = 1 ; k <= n ; ++ k) {
        bool flag = 1;
        for (int i = k + 1 ; i <= n  ; ++ i) {
            if (a[i] != a[i - k]) {
                flag = 0;
                break;
            }
        }
        if (flag) v.push_back(k);
    }
    printf("%d\n" , v.size());
    for (int i = 0 ; i < v.size() ; ++ i) {
        printf("%d%c" , v[i] , " \n"[i + 1 == v.size()]);
    }
}