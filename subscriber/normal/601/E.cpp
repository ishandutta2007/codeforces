#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, k, q;
int ty[N], id[N];
int v[N], w[N];

int ans[N];
int in[N], out[N];

int IDS, T;
int inter[N];

int z[N];

const int P = 10000019;

int have[N];

void sol(int l, int r) {
	if (l == r) {
		if (ty[l] == 3) {
			int ma = 0;
			ans[l] = 0;
			for (int i = k; i >= 1; i--) {
				ma = max(ma, z[i]);
				ans[l] = (ans[l] * 1ll * P + z[i]) % M;
			}
//			cout << ans[l] << endl;
		}
		return;
	}
	int mid = (l + r) / 2;

	int mem[k + 1];

	for (int i = 0; i <= k; i++) {
		mem[i] = z[i];
	}
	for (int i = l; i <= r; i++) if (ty[i] != 3) {
		if (in[id[i]] < l && out[id[i]] > mid) {
			for (int j = k - w[id[i]]; j >= 0; j--) 
				z[j + w[id[i]]] = max(z[j + w[id[i]]], z[j] + v[id[i]]);
		}
	}
	sol(l, mid);
	for (int i = 0; i <= k; i++) z[i] = mem[i];	

	for (int i = 0; i <= k; i++) {
		mem[i] = z[i];
	}
	for (int i = l; i <= r; i++) if (ty[i] != 3) {
		if (in[id[i]] <= mid && out[id[i]] > r) {
			for (int j = k - w[id[i]]; j >= 0; j--) 
				z[j + w[id[i]]] = max(z[j + w[id[i]]], z[j] + v[id[i]]);
		}
	}
	sol(mid + 1, r);
	for (int i = 0; i <= k; i++) z[i] = mem[i];	
	
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		ty[i] = 1;
		id[i] = i;
		scanf("%d%d", &v[id[i]], &w[id[i]]);
	}
	IDS = n;
	cin >> q;
	for (int i = 0; i < q; i++) {
		scanf("%d", &ty[n + i]);
		if (ty[n + i] == 2) {
			scanf("%d", &id[n + i]);
			id[n + i]--;
		} else if (ty[n + i] == 1) {
			id[n + i] = IDS;
			IDS++;
			scanf("%d%d", &v[id[n + i]], &w[id[n + i]]);	
		}
	}
	for (int i = 0; i < n + q; i++) out[i] = n + q + 5;
	for (int i = 0; i < n + q; i++) if (ty[i] == 1) {
		in[id[i]] = i;
	} else if (ty[i] == 2) {
		out[id[i]] = i;
	}
	for (int i = 0; i <= k; i++) z[i] = 0;
	sol(0, n + q - 1);
	for (int i = 0; i < n + q; i++) if (ty[i] == 3) printf("%d\n", ans[i]);
	return 0;
}