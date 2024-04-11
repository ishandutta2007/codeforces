#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

map <int, set <int>> mp;

map <int, int> sg;
int dfs(int k) {
	if(k == 0) return 0;
	if(sg.count(k)) return sg[k];
	set <int> st;
	for(int i = 0; i <= 30; i ++) if(k >> i) {
		int t = (k >> (i + 1)) | (k & ((1 << i) - 1));
		st.insert(dfs(t));
	}
	for(int i = 0; ; i ++)
		if(!st.count(i)) {
			sg[k] = i;
			return i;
		}
}

int main() {
	int n; cin >> n;
	
	for(int i = 1; i <= n; i ++) {
		int x; scanf("%d", &x);
		for(int d = 2; d * d <= x; d ++) if(x % d == 0) {
			int c = 0;
			while(x % d == 0) {
				x /= d;
				c ++;
			}
			mp[d].insert(c);
		}
		if(x > 1) mp[x].insert(1);
	}
	int sg = 0;
	for(auto i : mp) {
		int t = 0;
		for(int j : i.second)
			t |= (1 << (j - 1));
		//cout << t << ' ' << dfs(t) << '\n';
		sg ^= dfs(t);
	}
	
	cout << (sg ? "Mojtaba" : "Arpa") << '\n';
	
	return 0;
}