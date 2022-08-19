//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 5005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int dis[maxn][maxn]; 
int nx[maxn][4], cnt[maxn];
int q[maxn], fr, ed;
int x[3];
int op;
int nm = 0;
int n, m;
bool vis[maxn];
void read() {
	vis[x[0]] = vis[x[1]] = vis[x[2]] = 1;
	nm++;
	if (nm > n) exit(0);
	cout << x[0] << ' ' << x[1] << ' ' << x[2] << endl;
	fflush(stdout);	
	for (int j = 0; j < 3; j++)
		if (x[j] == op) exit(0);
	cin >> op;
}
int cal(int u, int a, int b, int c) {
	return min((dis[u][a]), min(dis[u][b], dis[u][c]));
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		int fl = 1;
		for (int j = 0; j < cnt[u]; j++)
			if (nx[u][j] == v) 
				fl = 0;
		if (fl) {
			nx[u][cnt[u]++] = v;
			nx[v][cnt[v]++] = u;
			assert(cnt[u] <= 3);
			assert(cnt[v] <= 3);
		}
	}
	int mg = maxn, mp = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			dis[i][j] = maxn;
		int um = 0;
		fr = ed = 0;
		dis[i][i] = 0;
		q[ed++] = i;
		while (fr < ed) {
			int fs = q[fr++], w = dis[i][fs] + 1;
			for (int j = 0; j < cnt[fs]; j++) {
				int v = nx[fs][j];
				if (dis[i][v] > w) {
					dis[i][v] = w;
					q[ed++] = v;
				}
			}
		}
		for (int j = 1; j <= n; j++)
			um = max(um, dis[i][j]);
		if (um < mg) {
			mg = um;
			mp = i;
		}
	}
	x[0] = mp;
	for (int i = 1; i < 3; i++) {
		int cm = 0, pl = 0;
		for (int j = 1; j <= n; j++) {
			int um = 0;
			for (int s = 0; s < i; s++)
				um += dis[x[s]][j];
			if (um > cm) 
				cm = um, pl = j;
		}
		x[i] = pl;
	} 
	
	while (1) {
		read();
		int bst = 1e9;
		int e[3];
		int y[3];
		for (y[0] = -1; y[0] < cnt[x[0]]; y[0]++) {
			for (y[1] = -1; y[1] < cnt[x[1]]; y[1]++)
				for (y[2] = -1; y[2] < cnt[x[2]]; y[2]++) {
					int h[3];
					for (int j = 0; j < 3; j++)
						if (y[j] == -1) h[j] = x[j];
						else h[j] = nx[x[j]][y[j]];
			
					int ev = cal(op, h[0], h[1], h[2]);
					int cu = maxn;
					if (ev == 0) cu = -1;
					else {
						vi r(3);
						r[0] = 0, r[1] = 1, r[2] = 2;
						int mn = maxn * 10;
						for (int j = 0; j < 6; j++) {
							int cr = 0;
							for (int s = 0; s < cnt[op]; s++)
								cr += dis[nx[op][s]][h[r[s]]];
							mn = min(mn, cr);
							next_permutation(r.begin(), r.end());
						}
						cu = mn;
					}
					if (cu < bst) {
					//	cout << "UPD" << endl;
						bst = cu;
						for (int m = 0; m < 3; m++)
							e[m] = h[m];
					}
				}
		}
		for (int j = 0; j < 3; j++)
			x[j] = e[j];
	}
	return 0;
}