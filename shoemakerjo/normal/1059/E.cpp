#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
#define ll long long

int n;
int L;
ll S;
const ll inf = 1e18+1;

ll seg[maxn*4];
ll lazy[maxn*4];


int mystart[maxn];
int myend[maxn];
vector<int> ch[maxn];
int par[18][maxn];
ll pardist[18][maxn];
ll dpsum[maxn];
ll dp[maxn];
ll w[maxn];

vector<int> setinf[maxn];

vector<int> preorder;

void predfs(int u) {
	mystart[u] = preorder.size();
	preorder.push_back(u);
	for (int v : ch[u]) predfs(v);
	myend[u] = preorder.size()-1;
}

int walk(int u, int k) {
	for (int i = 17; i >= 0; i--) {
		if (k & (1 << i)) {
			u = par[i][u];
		}
	}
	return u;
}

void delaze(int ss, int se, int si) {
	seg[si] += lazy[si];
	seg[si] = min(seg[si], inf); //why not
	if (ss != se) {
		lazy[si*2+1] += lazy[si];
		lazy[si*2+2] += lazy[si];
	}
	lazy[si] = 0;

}

void update(int us, int ue, ll diff, int ss = 0, int se = n, int si = 0)  {
	if (us > ue || ss > se || us > se || ue < ss) return;
	int mid = (ss+se)/2;
	delaze(ss, se, si);
	if (us <= ss && se <= ue) {
		lazy[si] += diff;
		delaze(ss, se, si);
		return;
	}
	update(us, ue, diff, ss, mid, si*2+1);
	update(us, ue, diff, mid+1, se, si*2+2);
	seg[si] = min(seg[si*2+1], seg[si*2+2]);
}

ll query(int qs, int qe, int ss = 0, int se = n, int si = 0) {
	if (qs > qe || ss > se || qs > se || qe < ss) return inf;
	delaze(ss, se, si);
	if (qs <= ss && se <= qe) return seg[si];
	int mid  = (ss+se)/2;
	return min(query(qs, qe, ss, mid, si*2+1),
		query(qs, qe, mid+1, se, si*2+2));
}

void go(int u) {
	//main function

	for (int v : ch[u]) go(v); //make sure they go first

	for (int v : setinf[u]) {
		update(mystart[v], mystart[v], inf - query(mystart[v], mystart[v]));
	}

	for (int v : ch[u]) {
		dpsum[u] += dp[v];
	}

	dp[u] = dpsum[u] + 1; //i guess this is the starting value
	update(mystart[u], myend[u], dpsum[u]);

	dp[u] = min(dp[u], query(mystart[u], myend[u]) + 1); 
	update(mystart[u], mystart[u], dpsum[u] - dp[u] - query(mystart[u], mystart[u]));
	update(mystart[u]+1, myend[u], 0 - dp[u]);
}

int main() {
	fill(seg, seg+maxn*4, inf);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> L >> S;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		if (w[i] > S) {
			cout << -1 << endl;
			return 0;
		}
	}
	int p;
	for (int i = 2; i <= n; i++) {
		cin >> p;
		ch[p].push_back(i);
		par[0][i] = p;
	}

	par[0][1] = -1;
	pardist[0][1] = S+1; //will never take it then
	for (int i = 2; i <= n; i++) {
		pardist[0][i] = w[par[0][i]];
	}
	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= n; j++) {
			if (par[i-1][j] != -1) {
				par[i][j] = par[i-1][par[i-1][j]];
				pardist[i][j] = pardist[i-1][j]  + pardist[i-1][par[i-1][j]];
			}
			else {
				par[i][j] = -1;
				pardist[i][j] = S+1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int ctake = 1;
		ll numleft = S - w[i];
		int cur = i;
		for (int j = 17; j >= 0; j--) {
			if (pardist[j][cur] <= numleft) {
				numleft -= pardist[j][cur];
				ctake += (1 << j);
				cur = par[j][cur];
			}
		}
		ctake = min(ctake, L);
		int cv = walk(i, ctake);
		if (cv != -1) setinf[cv].push_back(i);
	}

	predfs(1);
	assert(preorder.size() == n);

	go(1);

	cout << dp[1] << endl;

}