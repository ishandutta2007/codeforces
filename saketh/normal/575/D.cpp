#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cout << 2000 << "\n";

    for (int i = 0; i < 1000; i++) {
        cout << i + 1 << " " << 1 << " " << i + 1 << " " << 2 << "\n";
    }

    for (int i = 999; i >= 0; i--) {
        cout << i + 1 << " " << 1 << " " << i + 1 << " " << 2 << "\n";
    }
}