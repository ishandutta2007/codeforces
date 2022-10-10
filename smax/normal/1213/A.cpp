#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, numOdd = 0, numEven = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a % 2 == 0)
            numEven++;
        else
            numOdd++;
    }

    if (numOdd > numEven)
        cout << numEven << "\n";
    else
        cout << numOdd << "\n";

    return 0;
}