#include<bits/stdc++.h>
using namespace std;

int ask(vector<int> arr) {
    cout << "? " << arr.size();
    for (auto ind : arr) cout << " " << ind;
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k);
        for (int i = 0; i < k; i++) {
            int cnt;
            cin >> cnt;
            arr[i].resize(cnt);
            for (auto &ind : arr[i]) cin >> ind;
        }
        vector<int> all;
        for (int i = 1; i <= n; i++) all.push_back(i);
        int mx = ask(all);
        int l = 0, r = k + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            all.clear();
            for (int i = 0; i < mid; i++) {
                for (auto ind : arr[i]) all.push_back(ind);
            }
            if (ask(all) == mx) r = mid; else l = mid;
        }
        vector<int> ans(k, mx);
        if (r != k + 1) {
            r--;
            vector<int> used(n + 1, 0);
            for (auto ind : arr[r]) used[ind] = 1;
            all.clear();
            for (int i = 1; i <= n; i++) {
                if (!used[i]) all.push_back(i);
            }
            ans[r] = ask(all);
        }
        cout << "!";
        for (auto elem : ans) cout << " " << elem;
        cout << endl;
        string s;
        cin >> s;
        assert(s == "Correct");
    }
    return 0;
}