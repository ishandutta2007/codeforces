#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, O, Z;
char t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    for (cin >> N; N; N--) {
        cin >> t;
        if (t == '0') Z++;
        else O++;
    }

    cout << max(O, Z) - min(O, Z) << "\n";
}