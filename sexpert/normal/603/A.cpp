#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
    int n;
    string s;
    cin >> n >> s;
    s += '*';
    int cnt = 1;
    for(int i = 1; i <= n; i++) {
        if(s[i] == s[i - 1])
            cnt++;
        else {
            v.push_back(cnt);
            cnt = 1;
        }
    }
    int ans = v.size(), ct2 = 0;
    for(int i = 0; i < ans; i++) {
        if(v[i] >= 3) {
            cout << ans + 2 << endl;
            return 0;
        }
        if(v[i] == 2)
            ct2++;
    }
    if(ct2 >= 2) {
        cout << ans + 2 << endl;
        return 0;
    }
    if(ans < n)
        cout << ans + 1 << endl;
    else
        cout << ans << endl;
}