#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, X, A = 0;
    cin >> N >> X;

    for (int i = 1; i <= N; i++) {
        if(X % i == 0 && X / i <= N) A++;
    }

    cout << A << "\n";
}