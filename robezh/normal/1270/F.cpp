#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50, SZ = 300;

int n;
string str;
ll res = 0;
ll psum[N];
int nxt[N];
unordered_map<ll, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> str;
    n = str.length();
    str = " " + str;
    int la = n + 1;
    nxt[la] = la;
    for(int i = n; i >= 1; i--) {
        if(str[i] == '1') la = i;
        nxt[i] = la;
    }
    for(int i = 1; i <= n; i++) psum[i] = psum[i-1] + (str[i] == '1');
    for(int i = 1; i <= n; i++) {
        int pos = nxt[i];
        for(int j = 1; j <= n / SZ && pos <= n; j++) {
            int nx = nxt[pos + 1];
            res += max(0, (nx - i) / j - SZ) - max(0, (pos - i) / j - SZ);
            pos = nx;
        }
    }
    ll heavy_count = 0;
    for(int k = 1; k <= SZ; k++) {
        mp.clear();
        mp[0]++;
        for(int i = 1; i <= n; i++) {
            int &c = mp[k * psum[i] - i];
            heavy_count += (c++);
        }
    }
    cout << (res + heavy_count) << '\n';
}