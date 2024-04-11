#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int mn = 1 << 30 , mx = -1 << 30;
    for (int i = 0 ; i < 7 ; ++ i) {
        int sum = 0;
        for (int j = 0 ; j < n ; ++ j) {
            if ((i + j) % 7 < 2) {
                sum ++;
            }
        }
        mn = min(mn , sum);
        mx = max(mx , sum);
    }
    cout << mn << ' ' << mx << endl;
}