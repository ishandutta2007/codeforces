#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> takeA(n), takeB(n);
    int a = -1, b = -1;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int x;
            cin >> x;
            if(!takeA[i] && !takeB[x - 1]) {
                takeA[i] = 1;
                takeB[x - 1] = 1;
            }
        }
        if(!takeA[i])
            a = i;
    }
    if(a == -1) {
        cout << "OPTIMAL\n";
        return;
    }
    cout << "IMPROVE\n";
    for(int j = n - 1; j >= 0; j--) {
        if(!takeB[j]) {
            cout << a + 1 << " " << j + 1 << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}