#include <bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for (int i = (x); i < (y); i++)

int main() {
    long long n,m; cin >> n >> m;
    if (m == 1) {
        cout << n - 1;
    } else cout << n * (m - 1);
}