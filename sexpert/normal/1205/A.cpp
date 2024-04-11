#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    if(n % 2 == 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<int> smol, big;
    for(int i = 1; i <= n; i += 2) {
        smol.push_back(i);
        big.push_back(2*n - i + 1);
    }
    vector<int> ans(2*n);
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            ans[i] = smol[i/2];
            ans[n + i] = smol[i/2] + 1;
        }
        else {
            ans[i] = big[i/2];
            ans[n + i] = big[i/2] - 1; 
        }
    }
    for(auto a : ans)
        cout << a << " ";
    cout << '\n';
}