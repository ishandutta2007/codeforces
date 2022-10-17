#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int R1, C1, R2, C2;
    cin >> R1 >> C1 >> R2 >> C2;

    // rook
    if (R1 == R2 || C1 == C2)
        cout << "1 ";
    else cout << "2 ";

    // bishop
    if ( (R1 + C1) % 2 != (R2 + C2) % 2 ) cout << "0 ";
    else if ((R1 + C1) == (R2 + C2) || (R1 - C1) == (R2 - C2)) cout << "1 ";
    else cout << "2 ";

    // king
    cout << max(abs(R2 - R1), abs(C2 - C1)) << "\n";
}