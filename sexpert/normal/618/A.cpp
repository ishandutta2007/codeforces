#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int k = 25; k >= 0; k--) {
        if(n & (1 << k))
            cout << k + 1 << " ";
    }
    cout << '\n';
}