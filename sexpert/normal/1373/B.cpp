#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        vector<int> cnt(2);
        string s;
        cin >> s;
        for(auto c : s)
            cnt[c - '0']++;
        cout << (min(cnt[0], cnt[1]) % 2 ? "DA\n" : "NET\n");
    }   
}