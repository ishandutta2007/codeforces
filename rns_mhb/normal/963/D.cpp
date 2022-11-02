#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
 
typedef int ll;
 
const ll B = 503;
const ll mod = 1e9+7;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    int m;
    cin >> m;
    vector <int> a(m);
    vector <string> b(m);
    for(int i = 0; i < m; i ++) cin >> a[i] >> b[i];
    vector <vector<int> > q(n+1);
    for(int i = 0; i < m; i ++) q[b[i].length()].push_back(i);
    vector <ll> h(m);
    for(int i = 0; i < m; i ++) {
        h[i] = 0;
        for(int j = 0; j < b[i].length(); j ++) h[i] = (1ll*h[i] * B + b[i][j]) % mod;
    }
    vector <ll> pw(n+10);
    pw[0] = 1;
    for(int i = 1; i < n+10; i ++) pw[i] = 1ll*pw[i-1] * B % mod;
    vector <vector<int> > id(m);
    for(int i = 1; i <= n; i ++) {
        if(q[i].empty()) continue;
        vector <ll> v(q[i].size());
        vector <int> c(q[i].size());
        for(int j = 0; j < q[i].size(); j ++) v[j] = h[q[i][j]], c[j] = j;
        sort(c.begin(), c.end(), [&](int ii, int jj) {return v[ii] < v[jj];});
        sort(v.begin(), v.end());
        ll H = 0;
        for(int j = 0; j < n; j ++) {
            H = (1ll*H * B + s[j]) % mod;
            if(j >= i) {
                H = (H - 1ll*pw[i] * s[j-i]) % mod;
                if(H < 0) H += mod;
            }
            if(j < i-1) continue;
            if(H > v.back()) continue;
            int x = lower_bound(v.begin(), v.end(), H) - v.begin();
            if(v[x] != H) continue;
            x = q[i][c[x]];
            id[x].push_back(j);
        }
    }
    for(int i = 0; i < m; i ++) {
        if(id[i].size() < a[i]) {
            puts("-1");
            continue;
        }
        int mn = 1e9;
        for(int j = 0, k = a[i]-1; k < id[i].size(); j ++, k ++) mn = min(mn, id[i][k] - id[i][j]);
        printf("%d\n", mn + b[i].length());
    }
}