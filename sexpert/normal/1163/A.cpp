#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if(m <= n/2)
        cout << max(1, m) << '\n';
    else
        cout << n - m << '\n';
}