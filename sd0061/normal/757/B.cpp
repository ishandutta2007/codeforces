#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n , m , cnt[N];
int main() {
    scanf("%d" , &n);
    for (int i = 0 , x ; i < n ; ++ i) {
        scanf("%d" , &x);
        ++ cnt[x];
    }
    int res = 1;
    for (int i = 2 ; i < N ; ++ i) {
        int sum = 0;
        for (int j = i ; j < N ; j += i) {
            sum += cnt[j];
        }
        res = max(res , sum);
    }
    cout << res << endl;
}