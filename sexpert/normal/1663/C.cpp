#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, s = 0;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        s += x;
    }
    cout << s << '\n';
}