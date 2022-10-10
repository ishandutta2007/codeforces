#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    if(*min_element(v.begin(), v.end()) == *max_element(v.begin(), v.end())) {
        cout << "1\n";
        for(int i = 0; i < n; i++)
            cout << "1 ";
        cout << '\n';
        return;
    }
    int cnt = 0;
    int st = -1;
    for(int i = 0; i < n; i++) {
        if(v[i] == v[(i + 1) % n])
            st = i;
    }
    if(n % 2 && st == -1) {
        cout << "3\n";
        vector<int> ans;
        ans.push_back(0);
        for(int i = 1; i < n; i++) {
            if(v[i] != v[i - 1])
                ans.push_back(ans.back() ^ 1);
            else
                ans.push_back(ans.back());
        }
        for(auto &x : ans)
            x++;
        ans[0] = 3;
        for(int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << '\n';
        return;
    }
    if(st == -1)
        st = 0;
    else
        st = (st + 1) % n;
    vector<int> ans(n);
    ans[st] = 0;
    for(int i = 1; i < n; i++) {
        if(v[(st + i) % n] != v[(st + i + n - 1) % n])
            ans[(st + i) % n] = ans[(st + i + n - 1) % n] ^ 1;
        else
            ans[(st + i) % n] = ans[(st + i + n - 1) % n];
    }
    for(auto &x : ans)
        x++;
    cout << "2\n";
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