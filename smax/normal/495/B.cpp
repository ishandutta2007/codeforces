#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;

    if (a == b)
        cout << "infinity\n";
    else {
        int x = a - b, ret = 0;
        for (int i=1; i*i<=x; i++)
            if (x % i == 0)
                ret += (i > b) + (i * i != x && x / i > b);
        cout << ret << "\n";
    }

    return 0;
}