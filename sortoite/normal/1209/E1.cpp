#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

int a[50][2020], b[50], mx[50], n;
pii p[2020];
int dp[15][8096], val[8096];
vector<int> vec;

inline void update(int id) {
	for(int i=1; i<=n; i++) b[i]=a[i][id];
	for(int i=1<<n; i--; ) val[i]=0;
	for(int cnt=n; cnt--; ) {
		int tmp=b[n];
		for(int i=n; i>=2; i--) b[i]=b[i-1];
		b[1]=tmp;
		
		for(int i=1<<n; i--; ) {
			int sum=0;
			for(int j=1, u=i; j<=n; j++, u>>=1) if(u&1) {
				sum+=b[j];
			}
			smax(val[i], sum);
		}
	}
}

inline void solve() {
	int m; scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%d", a[i]+j);
		}
	}
	for(int i=1; i<=m; i++) {
		p[i]=pii(a[1][i], i);
		for(int j=2; j<=n; j++) smax(p[i].x, a[j][i]);
	}
	sort(p+1, p+m+1, [](pii a, pii b) {return a>b;});
	
	int N=min(n, m);
	vec.clear(), vec.pb(0);
	for(int i=N; i>=1; i--) vec.pb(p[i].y);
	
	for(int i=1; i<=N; i++) {
		for(int j=1<<n; j--; ) dp[i][j]=0;
	}
	for(int i=1; i<=N; i++) {
		update(vec[i]);
		for(int j=1<<n; j--; ) {
			for(int k=j; ; k=(k-1)&j) {
				smax(dp[i][j], dp[i-1][j^k]+val[k]);
				if(k==0) break;
			}
		}
	}
	printf("%d\n", dp[N][(1<<n)-1]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) solve();
}