#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> s(n);
    for(int i = 0; i < n; i++)
        cin >> s[i];
        
    long long ans = 0;
    for(int i = 0; i < m; i++) {
        int a;
        cin >> a;
        vector<int> c(5, 0);
        for(int j = 0; j < n; j++)
            c[int(s[j][i]) - int('A')]++;
            
        int mx = 0;
        for(int j = 0; j < c.size(); j++)
            mx = max(mx, c[j]);
            
        ans += a * mx;
        //cout << mx << ' ' << a << endl;
    }
    
    cout << ans;
}