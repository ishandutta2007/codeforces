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

int m;

string st, s[N];

int fu[N], inv[N];

int su[N], ans[N];

vector<int> need[N];

int ty[N], nn[N];

int p25[N];


int pv(int a, int b) {
	if (b == 0) return 1;
	long long r = pv(a, b / 2);
	r = r * r % M;
	if (b % 2) r = r * a % M;
	return r;
}

int C(int n, int k) {
	if (k < 0 || k > n) return 0;
	return fu[n] * 1ll * inv[k] % M * inv[n - k] % M;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	p25[0] = 1;
	for (int i = 1; i < N; i++) p25[i] = p25[i - 1] * 25ll % M;
	cin >> m;
	cin >> st;
	int curl = st.size();
	for (int i = 0; i < m; i++) {
		cin >> ty[i];
		if (ty[i] == 1) {
			cin >> s[i];
			curl = s[i].size();
		} else {
			need[curl].pb(i);
			cin >> nn[i];
		}			
	}
	fu[0] = 1;
	for (int i = 1; i < N; i++) fu[i] = fu[i - 1] * 1ll * i % M;
	for (int i = 0; i < N; i++) inv[i] = pv(fu[i], M - 2) % M;

	for (int d = 1; d < N; d++) if (need[d].size() > 0) {
		for (int i = 1; i <= 100000; i++) {
			if (i < d) {
				su[i] = 0;
				continue;
			}
			su[i] = C(i - 1, d - 1) * 1ll * p25[i - d] % M;
		}
		for (int i = 1; i <= 100000; i++) su[i] = (su[i - 1] * 26ll + su[i]) % M;

		for (int i = 0; i < need[d].size(); i++) ans[need[d][i]] = su[nn[need[d][i]]];
	}
	for (int i = 0; i < m; i++) if (ty[i] == 2) cout << ans[i] << endl;

	return 0;
}