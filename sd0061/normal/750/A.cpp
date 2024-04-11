#include <bits/stdc++.h>
using namespace std;
const int N = 200005;


int main() {
    int n , k;
    cin >> n >> k;
    k = 240 - k;
    int cnt = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        if (k >= i * 5) {
            k -= i * 5;
            ++ cnt;
        }
    }
    cout << cnt << endl;
}