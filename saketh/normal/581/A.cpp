#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int A, B;
    cin >> A >> B;

    int A1 = min(A, B);
    int A2 = (max(A, B) - A1) / 2;

    cout << A1 << " " << A2 << endl;
}