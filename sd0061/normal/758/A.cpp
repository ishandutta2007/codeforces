#include <bits/stdc++.h>
using namespace std;

int main() {
    int n , sum = 0 , mx = 0;
    cin >> n;
    for (int i = 0 ; i < n ; ++ i) {
        int x;
        cin >> x;
        sum += x;
        mx = max(mx , x);
    }
    cout << mx * n - sum << endl;
}