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
#define M 1000000007
#define N 211111
using namespace std;
typedef pair<int,int> pt;

int n;
int x[N], y[N];
int num[N];
int sz;
vector<pt> ans;

int b[55];
int cont[55][55];
int nn[55][55];
int did[55];
int mem[55][55];


void go(int i, int j) {
	ans.pb(mp(i + 1, j + 1));
	x[i] ^= x[j];
}

int a[55][55];
int B[55];
int need[55];
int r[55];

void gau() {
		//cont
		//need
		for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++) a[i][j] = cont[j][i];
		for (int i = 0; i < sz; i++) B[i] = need[i];
		
		int s = 0;
		for (int i = 0; i < sz; i++) {
			int f = -1;
			for (int j = s; j < sz; j++) if (a[j][i] == 1) {
				f = j;
				break;
			}
			if (f == -1) {
				continue;
			} 
			if (f != s) {
//				swap(id[f], id[s]);
				for (int j = 0; j < sz; j++) swap(a[f][j], a[s][j]);
				swap(B[f], B[s]);
			}
			for (int j = 0; j < sz; j++) if (j != s && a[j][i] == 1) {
				for (int k = 0; k < sz; k++) a[j][k] ^= a[s][k];
				B[j] ^= B[s];
			}
			s++;
			
		}
		for (int i = 0; i < sz; i++) r[i] = 0;

		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++) if (a[i][j] == 1 && B[i] == 1) r[j] = 1;
}

void build(int f, int z) {
	if (z) {
		for (int i = 0; i < sz; i++) need[i] = nn[f][i];
		gau();
	}		

	if (r[f] == 0) {
		go(f, f);
		for (int j = 0; j < sz; j++) cont[f][j] = 0;
	}
	for (int i = 0; i < sz; i++) if (i != f && r[i]) {
		go(f, i);
		for (int j = 0; j < sz; j++) cont[f][j] ^= cont[i][j];
	}
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &x[i]);

	sz = 0;
	for (int b = 29; b >= 0; b--) {
		int f = -1;
		for (int i = sz; i < n; i++) if (x[i] & pw(b)) {
			f = i;
			break;
		}
		if (f == -1) continue;

		if (f != sz) go(sz, f);
		for (int i = 0; i < n; i++) if (i != sz && (x[i] & pw(b)) > 0) go(i, sz);
		num[sz] = b;
		sz++;
	}
	for (int i = 0; i < n; i++) scanf("%d", &y[i]);

	int bad = 0;
	for (int i = sz; i < n; i++) {
		int t = y[i];
		for (int j = 0; j < sz; j++) if (t & pw(num[j])) {
			go(i, j);
			t ^= x[j];
		}
		if (t != 0) bad = 1;
	}
	for (int i = 0; i < sz; i++) b[i] = x[i];

	for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++) cont[i][j] = 0;
	for (int i = 0; i < sz; i++) cont[i][i] = 1;

	for (int g = sz - 1; g >= 0; g--) {
		int t = y[g];
		if (t == 0) continue;
		for (int i = 0; i < sz; i++) {
			if (t & pw(num[i])) {
				nn[g][i] = 1;
				t ^= b[i];
			} else nn[g][i] = 0;
		}
		if (t != 0) bad = 1;
	}

	for (int it = 0; it < sz; it++) {
		int ok = 0;
		for (int i = 0; i < sz; i++) if (!did[i]) {	
			int v = -1;
			for (int j = 0; j < sz; j++) need[j] = nn[i][j];
			gau();
			for (int j = 0; j < sz; j++) if (!did[j] && r[j] == 1) {
				v = j;
				break;
			}
			if (v != -1) {
				ok = 1;
				if (i != v) {
					for (int j = 0; j < sz; j++) swap(cont[i][j], cont[v][j]);
					go(v, i);
					go(i, v);
					go(v, i);
				}
				build(i, 1);
				did[i] = 1;
				break;
			}
		}
		if (!ok) break;
	}

	for (int i = 0; i < sz; i++) if (!did[i]) {
		for (int j = 0; j < sz; j++) need[j] = nn[i][j];
		gau();
		for (int j = 0; j < sz; j++) mem[i][j] = r[j];
	}
	for (int i = 0; i < sz; i++) if (!did[i]) {
		for (int j = 0; j < sz; j++) r[j] = mem[i][j];
		build(i, 0);
	}

 	for (int i = 0; i < n; i++) if (x[i] != y[i]) {
 		puts("-1");
 		return 0;
 	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].F, ans[i].S);
		
	return 0;
}