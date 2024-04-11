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

const int NN = 400011;
const int MM = 22;
int a[NN];
int mn[NN][MM];
int nxt[NN];
int ans[NN];

inline int get(int st, int ed) {
	int l = ed - st + 1;
	l = 31 - __builtin_clz(l);
	return min(mn[st][l], mn[ed-(1<<l)+1][l]);
}

int solve() {
	cin >> n;
	for(int i=0; i<n; i++) scanf("%d", a+i), a[i]<<=1;
	for(int i=n; i<4*n; i++) a[i] = a[i%n];
	n = n * 4;
	for(int i=0; i<n; i++) mn[i][0] = a[i];
	for(int j=1; j<MM; j++) {
		for(int i=0; i<n; i++) {
			mn[i][j] = min(mn[i][j-1], mn[min(n-1, i+(1<<j-1))][j-1]);
		}
	}
	for(int i=n-1; i>=0; i--) {
		int u = i+1;
		while(u<n and a[u]<=a[i]) u=nxt[u];
		nxt[i] = u;
	}
	ans[n] = n;
	for(int i=n-1; i>=0; i--) {
		int R =nxt[i];
		int u = a[i]/2;
		int st=i, ed=R+1;
		while(ed > st + 1) {
			int mid = st + ed >> 1;
			if(get(i, mid)>=u) st=mid;
			else ed=mid;
		}
		if(st == R) ans[i] = ans[R];
		else ans[i] = st;
//		cerr<<i<<' '<<st<<' '<<R<<' '<<ans[i]<<endl;
	}
	for(int i=0; i<n/4; i++) {
		int u=ans[i];
		printf("%d\n", ans[i]==n ? -1 : ans[i]-i+1);
	}
}
int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	solve();
	return 0;
}