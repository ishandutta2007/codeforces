#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> seed = {
    {2, 4, 1, 3},
    {2, 4, 1, 3, 5},
    {1, 3, 5, 2, 4, 6},
    {2, 4, 6, 3, 1 , 5, 7}
};

void solve() {
    int n;
    cin >> n;
    if(n <= 3) {
        cout << "-1\n";
        return;
    }
    vector<int> ans = seed[n % 4];
    int st = ans.size() + 1;
    n -= ((n % 4) + 4);
    for(int i = 0; i < n; i += 4) {
        ans.push_back(st + 1);
        ans.push_back(st + 3);
        ans.push_back(st);
        ans.push_back(st + 2);
        st += 4;
    }
    for(auto x : ans)
        cout << x << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}