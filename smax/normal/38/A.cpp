#include <bits/stdc++.h>
using namespace std;

int d[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, a, b;
    cin >> n;
    for (int i=0; i<n-1; i++)
        cin >> d[i];
    cin >> a >> b;

    int ret = 0;
    for (int i=a-1; i<b-1; i++)
        ret += d[i];

    cout << ret << "\n";

    return 0;
}