#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m = 0;
    cin >> n;
    if(n < 3) {
        cout << "1\n";
        return 0;
    }
    for(m = 1; ;m++) {
        if((1 << (m + 1)) - 1 > n) {
            m--;
            break;
        }
    }
    // m layers, last one has 1 << m
    int bnd = (1 << (m + 1)) - 1;
    for(int k = m; k >= 1; k -= 2)
        bnd += (1 << k)/2;
    if(n == bnd || n == bnd + 1)
        cout << "1\n";
    else
        cout << "0\n";
}