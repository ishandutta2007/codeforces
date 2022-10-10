#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);

    int n, numNeg = 0, numZeroes = 0;
    long long ret = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            numZeroes++;
            ret++;
        } else if (abs(a-1) < abs(a+1))
            ret += abs(a-1);
        else {
            ret += abs(a+1);
            numNeg++;
        }
    }

    if (numNeg % 2 == 1 && numZeroes == 0)
        ret += 2;

    cout << ret << "\n";

    return 0;
}