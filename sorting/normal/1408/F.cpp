#include <bits/stdc++.h>

using namespace std;

vector<array<int, 2>> ans;

void solve(int l, int r){
    if(l == r) return;

    int mid = (l + r) >> 1;
    solve(l, mid);
    solve(mid + 1, r);

    for(int i = l; i <= mid; ++i)
        ans.push_back({i, i + mid + 1 - l});
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int t = 1;
    while(t <= n) t <<= 1;
    t >>= 1;

    solve(1, t);
    solve(n - t + 1, n);

    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i][0] << " " << ans[i][1] << "\n";
}