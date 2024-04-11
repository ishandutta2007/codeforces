#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
int n;
vector<int> s, c;
void read() {
    cin >> n;
    s.resize(n);
    for (auto &i : s) cin >> i;
    c.resize(n);
    for (auto &i : c) cin >> i;
}
int ans;
void run() {
    
    vector<int> help = c;
    for (int i = n - 1; i >= 0; i--) {
        int add = 1e18;
        for (int j = 0; j < i; j++) {
            if (s[j] < s[i])
                chkmin(add, c[j]);
        }
        c[i] += add;
    }
    for (int i = n - 1; i >= 0; i--) {
        int add = 1e18;
        for (int j = 0; j < i; j++) {
            if (s[j] < s[i])
                chkmin(add, c[j]);
        }
        help[i] += add;
    }
    ans = 1e18;
    for (auto i : help)
        chkmin(ans, i);
}

void write() {
    if (ans == 1e18) ans = -1;
    cout << ans << endl;

}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}