#include <bits/stdc++.h>
using namespace std;

int power[31] = {1};

bool check(int n, int j) {
    int ret = 0;
    long long maxSplit = 1;
    for (int i=30; i>=0; i--)
        while (n >= power[i]) {
            n -= power[i];
            ret++;
            maxSplit *= power[i];
            if (maxSplit < 0)
                maxSplit = 0;
        }
    return ret <= j && (maxSplit == 0 || j <= maxSplit);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    for (int i=1; i<=30; i++)
        power[i] = power[i-1] * 2;

    int n, p;
    cin >> n >> p;

    int ret = -1, j = 0;
    while (n - j * p > 0) {
        if (check(n - j * p, j)) {
            ret = j;
            break;
        }
        j++;
    }

    cout << ret << "\n";

    return 0;
}