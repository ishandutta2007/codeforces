#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool good(int x) {
    int r = 0;
    while(x > 0) {
        r += (x % 10);
        x /= 10;
    }
    return (r % 4 == 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a;
    cin >> a;
    for(int n = a; ; n++) {
        if(good(n)) {
            cout << n << '\n';
            return 0;
        }
    }
}