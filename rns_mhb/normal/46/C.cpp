#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    string t = s;
    sort(t.begin(), t.end());
    t = t + t;
    int ans = 1e9;
    for(int i = 0; i <= n; i ++) {
        int cur = 0;
        for(int j = 0; j < n; j ++) if(s[j] != t[i+j]) cur ++;
        ans = min(ans, cur/2);
    }
    cout << ans << endl;
}