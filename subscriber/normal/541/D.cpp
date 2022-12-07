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
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int f[1000111];

vector<int> pr;

long long dp[1000111];

long long ok[1000111];

map<long long, vector<long long> > ve;

int u[1000111];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	for (int i = 2; i <= 1000000; i++) if (!f[i]) {
		pr.pb(i);
		int j = i + i;
		while (j <= 1000000) {
			f[j] = 1;
			j += i;
		}
	}
	
	
	vector<long long> e;
	long long x;
	cin >> x;
	for (int i = 1; i * 1ll * i <= x; i++) if (x % i == 0){ 
		e.pb(i);
		if (i * 1ll * i != x) e.pb(x / i);
	}
	sort(e.begin(), e.end());

	for (int i = 0; i < e.size(); i++) {
		ok[i] = -1;
		if (e[i] <= 2) continue;

		long long t = e[i] - 1;
		
		long long d = -1;

		for (int j = 0; j < pr.size(); j++) {
			if (pr[j] * 1ll * pr[j] > t) break;
			if (t % pr[j] == 0) {
				d = pr[j];
				break;
			}
		}
		if (d == -1) d = t;

		ok[i] = d;
		while (t % d == 0) t /= d;
		if (t != 1) ok[i] = -1;
	}

//	for (int i = 0; i < e.size(); i++) cout << e[i] << " " << ok[i] << endl;

	vector<long long> oks;
	for (int i = 0; i < e.size(); i++) if (ok[i] != -1) {
		ve[ok[i]].pb(e[i]);
		oks.pb(ok[i]);
	}		
	sort(oks.begin(), oks.end());
	oks.resize(unique(oks.begin(), oks.end()) - oks.begin());
	
	dp[e.size() - 1] = 1;
	
	for (int i = 0; i < oks.size(); i++) {
		vector<long long> v = ve[oks[i]];
		if (v.size() == 0) continue;

		for (int j = 0; j < v.size(); j++) u[j] = 0;

		for (int j = 0; j < e.size(); j++) {
			for (int k = 0; k < v.size(); k++) {
				long long t = e[j] * v[k];

				while (u[k] + 1 < e.size() && e[u[k] + 1] <= t) u[k]++;
				if (e[u[k]] == t) dp[j] += dp[u[k]];
			}
		}
	}
	cout << dp[0] << endl;

	return 0;
}