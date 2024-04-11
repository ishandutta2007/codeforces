#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, ret = 0;
    cin >> n >> x;
    for (int i=1; i<=n; i++)
        if (x % i == 0 && x / i <= n)
            ret++;
    cout << ret << endl;
    
    return 0;
}