#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    n = unique(s.begin(), s.end()) - s.begin();
    int a = 0, b = 0;
    for(int i = 0; i < n; i ++) if(s[i] == '0') a ++;
    if(a == 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << y + 1ll * (a-1) * min(x, y) << endl;
}