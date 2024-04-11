#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

const int MAXN = 1123456;

int f[MAXN];
int l[MAXN], r[MAXN];
int last[MAXN];
vector<int> rl[MAXN], rr[MAXN];//restrictions

int getF(int i){
	if(i != f[i])
		f[i] = getF(f[i]);
	return f[i];
}

void dfs(int i){
	if(i == -1)
		return;
	dfs(l[i]);
	printf("%d ", i+1);
	dfs(r[i]);
}

int main(){
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int n, m;
	int i, j, k;

	scanf("%d%d", &n, &m);
	for(i = 0; i < n; i++){
		rl[i].clear();
		rr[i].clear();
	}
	for(i = 0; i < m; i++){
		char s[10];
		scanf("%d%d%s", &j, &k, s);
		j--;
		k--;
		if(s[0] == 'L')
			rl[j].pb(k);
		else
			rr[j].pb(k);
	}

	for(i = 0; i < n; i++)
		f[i] = i;
	for(i = 0; i < n; i++)
		last[i] = i;
	for(i = 0; i < n; i++)
		l[i] = r[i] = -1;

	for(i = n-1; i >= 0; i--){
		int lmax, rmax;
		bool bad = false;
		lmax = rmax = i;

		for(j = 0; j < rl[i].size(); j++){
			int t = getF(rl[i][j]);
			if(t <= i)
				bad = true;
			lmax = max(lmax, t);
		}
		for(j = 0; j < rr[i].size(); j++){
			int t = getF(rr[i][j]);
			if(t <= lmax)
				bad = true;
			rmax = max(rmax, t);
		}
		if(bad)
			break;
		while(last[i] != last[lmax]){
			l[last[i]] = last[i]+1;
			f[last[i]+1] = last[i];
			last[i] = last[last[i]+1];
		}
		if(rmax != i){
			r[i] = last[i]+1;
			f[last[i]+1] = i;
			last[i] = last[last[i]+1];
		}
		while(last[i] != last[rmax]){
			r[last[i]] = last[i]+1;
			f[last[i]+1] = last[i];
			last[i] = last[last[i]+1];
		}
	}

	if(i >= 0){
		printf("IMPOSSIBLE\n");
	}
	else{
		while(last[0] != n-1){
			r[last[0]] = last[0]+1;
			f[last[0]+1] = last[0];
			last[0] = last[last[0]+1];
		}
		dfs(0);
		printf("\n");
	}

	return 0;
}