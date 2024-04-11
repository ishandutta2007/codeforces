#include<bits/stdc++.h>

#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
typedef vector<int> VI;
int power(int a, int b, int m, int ans=1) {
	for(; b; b>>=1, a=1LL*a*a%m) if(b&1) ans=1LL*ans*a%m;
	return ans;
}

int n;
INT k;
const int NN = 1000111;
int ans[NN];

void dfs(INT re, int d) {
	int p = n-d+1;
	if(p-d>=re) {
		int w=d+re;
		swap(ans[d], ans[w]);
		return ;
	}
	else {
		swap(ans[d], ans[p]);
		dfs(re-p+d, d+1);
	}
}

int solve() {
	cin >> n >> k;
	INT mx=0, mn=0;
	for(int i=1; i<=n; i++) mn+=i, ans[i] = i;
	for(int i=1; i<=n; i++) mx+=max(i, n-i+1);
	if(k<mn) return puts("-1");
	if(k>mx) k=mx;
	dfs(k-mn, 1);
	cout << k << endl;
	for(int i=1; i<=n; i++) printf("%d ", i); puts("");
	for(int i=1; i<=n; i++) printf("%d ", ans[i]);
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	solve();
	return 0;
}