#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int l, int r, const vector<int> &v, vector<int> &ans, int d = 0){
    if(l > r) return;
    int idx = max_element(v.begin() + l, v.begin() + r + 1) - v.begin();
    ans[idx] = d;
    solve(l, idx - 1, v, ans, d + 1);
    solve(idx + 1, r, v, ans, d + 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n), ans(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        solve(0, n - 1, a, ans);

        for(int x: ans)
            cout << x << " ";
        cout << "\n";
    }
}