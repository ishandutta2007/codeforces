#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int a;
    cin >> a;

    if (a == 1)
        cout << "1 1\n1\n";
    else
        cout << (a - 1) * 2 << " 2\n1 2\n";

    return 0;
}