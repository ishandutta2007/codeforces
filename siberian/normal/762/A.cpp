#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
 
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
 
int n, k;
 
void read() {
    cin >> n >> k;
}
 
int ans;
 
void run() {
    set <int> help;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            help.insert(i);
            help.insert(n / i);
        }
    }
    if (help.size() < k) {
        ans = -1;
        return;
    }
    k--;
    while (k--) {
        help.erase(help.begin());
    }
    ans = *help.begin();
}
 
void write() {
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