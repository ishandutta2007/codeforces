#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    if(n == 1) {
        cout << "1 1\n1\n";
        return 0;
    }
    cout << 2*(n - 1) << " 2\n1 2\n";
    return 0;
}