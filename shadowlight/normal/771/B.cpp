#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string now = "Aa";
    vector <string> ans;
    for (int i = 0; i < k - 1; i++) {
        ans.push_back(now);
        if (now.back() == 'z') {
            now += "a";
        } else {
            now.back()++;
        }
    }
    for (int i = 0; i < n - k + 1; i++) {
        string s;
        cin >> s;
        if (s == "NO") {
            ans.push_back(ans[i]);
        } else {
            ans.push_back(now);
            if (now.back() == 'z') {
                now += "a";
            } else {
                now.back()++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}