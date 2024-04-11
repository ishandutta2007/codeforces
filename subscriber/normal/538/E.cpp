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

int n;
vector<int> v[N];

int li;

int solve(int x, int vi, int ch, int pr) {
	if (vi == 0) return 0;
	int mv = 0;
	for (int i = 0; i < v[x].size(); i++) if (v[x][i] != pr) mv = 1;
	if (!mv) {
		if (vi) return 1;
		return 0;
	}

	if (vi == 1 && ch == 0) {
		int sum = 0;
		for (int i = 0; i < v[x].size(); i++) if (v[x][i] != pr) {
			int to = v[x][i];
			sum += solve(to, 1, 1 - ch, x);
		}
		return sum;
	}
	if (vi == 1 && ch == 1) {
		int mi = 1e9;
		for (int i = 0; i < v[x].size(); i++) if (v[x][i] != pr) {
			int to = v[x][i];
			mi = min(mi, solve(to, 1, 1 - ch, x));
		}
		return mi;
	}
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	if (n == 1) {
		puts("1 1");
		return 0;
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	li = 0;
	for (int i = 0; i < n; i++) if (i != 0 && v[i].size() == 1) li++;
	cout << li - solve(0, 1, 1, 0) + 1 << " ";
	cout << solve(0, 1, 0, 0) << endl;
	return 0;
}