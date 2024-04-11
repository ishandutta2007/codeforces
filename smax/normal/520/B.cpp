#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    int ret = 0;
    while (m != n) {
        if (m < n || m % 2 == 1)
            m++;
        else
            m /= 2;
        ret++;
    }

    cout << ret << "\n";

    return 0;
}