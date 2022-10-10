#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<string> inp(n);
    map<string, int> cnt;
    for(auto &x : inp) {
        cin >> x;
        string t;
        t += x[0];
        t += x[x.size() - 1];
        cnt[t]++;
    }
    if(cnt["00"] && cnt["11"] && !cnt["10"] && !cnt["01"]) {
        cout << "-1\n";
        return;
    }
    if(cnt["00"] == n || cnt["11"] == n) {
        cout << "0\n";
        return;
    }
    if(cnt["01"] < cnt["10"]) {
        swap(cnt["01"], cnt["10"]);
        for(auto &s : inp)
            reverse(s.begin(), s.end());
    }
    int def = cnt["01"] - cnt["10"];
    if(def <= 1) {
        cout << "0\n";
        return;
    }
    vector<int> ans;
    set<string> all;
    for(auto x : inp)
        all.insert(x);
    for(int i = 0; i < n; i++) {
        string t;
        t += inp[i][0];
        t += inp[i].back();
        if(t == "01") {
            string s = inp[i];
            reverse(s.begin(), s.end());
            if(!all.count(s)) {
                def -= 2;
                ans.push_back(i + 1);
                if(def <= 1)
                    break;
            }
        }
    }
    cout << ans.size() << '\n';
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