#include<bits/stdc++.h>
using namespace std;

const int MX = 100005;
const int INF = 1000000005;

namespace WinnerTree {
	typedef int value;
	
	struct Max {
		value operator()(const value& a, const value& b) const{
			return max(a, b);
		}
	};
	
	template<typename _operator, value init> struct WinnerTree {
		value v[MX * 4];
		int n;
		_operator calc;
	
		void build(int an) {
			for (n = 1; n < an; n *= 2);
			fill(v, v + n * 2 + 5, init);
		}
		
		void update(int i, value val) {
			i += n;
			v[i] = val;
			for (i /= 2; i; i /= 2) v[i] = calc(v[i * 2], v[i * 2 + 1]);
		}
		
		//	Get value from [st, en)
		
		value get(int st, int en) {
			st += n, en += n;
			value rlt = init;
			while (st < en) {
				if (st & 1) rlt = calc(rlt, v[st]);
				if (en & 1) rlt = calc(rlt, v[en - 1]);
				st = (st + 1) / 2;
				en /= 2;
			}
			return rlt;
		}
	};
} ;

typedef WinnerTree::WinnerTree <WinnerTree::Max, -INF> MaxTree;
MaxTree X;

template <typename T, typename U>
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

int nxt[MX];
int a[MX], n, dp[MX];
int s[MX];

int main() {
	
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	
	nxt[1] = 0;
	for (int i = 2; i <= n; i ++) {
		int cur = i -1;
		while (a[cur] < a[i] && cur) cur = nxt[cur];
		nxt[i] = cur;
	}
	X.build(n + 1);
	s[n + 1] = 0;
	for (int i = n; i > 0; i --) {
		s[i] = s[i + 1] + a[i];
		X.update(i, s[i]);
	}
	int rlt = 0;
	dp[1] = 0;
	for (int i = 2; i <= n; i ++) {
		if (nxt[i]) dp[i] = dp[nxt[i]] + s[nxt[i] + 1] - s[i + 1];
		else dp[i] = 0;
		chkmax(dp[i], X.get(nxt[i] + 1, i + 1) - s[i]);
		chkmax(rlt, dp[i]);
	}
	cout << rlt << endl;
}