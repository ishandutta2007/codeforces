#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool blocked[(1 << 18)];
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x, m;
    cin >> n >> x;
    m = (1 << n);
    ans.push_back(0);
    blocked[0] = blocked[x] = true;
    for(int i = 0; i < m; i++) {
        if(blocked[i])
            continue;
        ans.push_back(i);
        blocked[i] = blocked[i ^ x] = true;
    }
    cout << ans.size() - 1 << '\n';
    for(int i = 0; i < ans.size() - 1; i++)
        cout << (ans[i] ^ ans[i + 1]) << " ";
    cout << '\n';
}