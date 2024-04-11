#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cout << "?";
    for (int i=1; i<=100; i++)
        cout << " " << i;
    cout << endl;

    int q1;
    cin >> q1;

    cout << "?";
    for (int i=1; i<=100; i++)
        cout << " " << (i << 7);
    cout << endl;

    int q2;
    cin >> q2;

    int ret = 0;
    ret |= q1 & ((1 << 7) - 1) << 7;
    ret |= q2 & ((1 << 7) - 1);

    cout << "! " << ret << endl;

    return 0;
}