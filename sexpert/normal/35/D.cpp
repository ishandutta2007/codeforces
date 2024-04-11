#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, X;
    cin >> n >> X;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        c *= (n - i);
        v[i] = c;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        if(v[i] > X) {
            cout << i << '\n';
            return 0;
        }
        X -= v[i];
    }
    cout << n << '\n';
}