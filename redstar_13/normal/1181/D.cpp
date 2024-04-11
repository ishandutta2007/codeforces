#include <bits/stdc++.h>

#define pb push_back
#define x first
#define y second
#define INF 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;

#define NN 500011
int n, m, q;
pii p[NN];
INT sum[NN];
int val[NN];
int cnt[NN];
int B[NN<<3];

int ok(int id, INT k) {
	INT tmp=(INT)id*p[id].x;
	tmp -= sum[id];
	if(tmp<=k) return 1;
	return 0;
}

vector<pii> qu[NN];
int ans[NN];

INT solve(INT k, int i) {
	int st=0, ed=m+1;
	while(ed>st+1) {
		int mid = st+ed>>1;
		if(ok(mid, k)==0) ed=mid;
		else st=mid;
	}
	INT tmp=(INT)st*p[st].x-sum[st];
	k-=tmp;
//	cerr<<k<<endl;
	int id=k%st;
	id++;
//	cerr<<i<<' '<<st<<' '<<id<<endl;
	qu[st].pb(pii(id, i));
}

void update(int u) {
	while(u<NN<<3) {
		B[u]++;
		u+=u&-u;
	}
}

int calc(int s) {
	int now=0;
	for(int i=20; i>=0; i--) {
		if(B[now+(1<<i)]>=s) {
//			now+=(1<<i);
		}
		else {
			now+=(1<<i);
			s -= B[now];
		}
	}
	return now+1;
}


int solve() {
	cin >> n >> m >> q;
	for(int i=0; i<n; i++) {
		int u; scanf("%d", &u);
		cnt[u]++;
	}
	
	for(int i=1; i<=m; i++) p[i] = pii(cnt[i], i);
	sort(p+1, p+m+1);
	for(int i=1; i<=m; i++) sum[i] = sum[i-1] + p[i].x;
	for(int i=0; i<q; i++) {
		INT k; scanf("%I64d", &k);
		k -= n;
		k--;
		solve(k, i);
	}
	for(int i=1; i<=m; i++) {
		update(p[i].y);
		for(pii tmp : qu[i]) {
			int s=tmp.x, id=tmp.y;
			ans[id] = calc(s);
		}
	}
	for(int i=0; i<q; i++) printf("%d\n", ans[i]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);
#endif
	solve();
    return 0;
}