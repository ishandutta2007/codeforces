#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double L, v1, v2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> L >> v1 >> v2;
    cout << v1 * L / (v1 + v2) << "\n";
}