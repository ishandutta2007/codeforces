#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int pm = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << x + pm << ' ';
        pm = max(pm, x + pm);
    }
    cout << '\n';
}