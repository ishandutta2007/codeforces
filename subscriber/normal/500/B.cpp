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
int p[666];
string e[666];
vector<int> have, pos;
int ans[666];

int was[666];

void rec(int x) {
	if (was[x]) return;
	was[x] = 1;
	pos.pb(x);
	have.pb(p[x]);
	for (int i = 0; i < n; i++) if (e[x][i] == '1') rec(i);
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &p[i]);

	for (int i = 0; i < n; i++) cin >> e[i];

	for (int i = 0; i < n; i++) if (!was[i]) {
		pos.clear();
		have.clear();
		rec(i);

		sort(pos.begin(), pos.end());
		sort(have.begin(), have.end());
		for (int j = 0; j < pos.size(); j++) ans[pos[j]] = have[j];
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i];
		if (i == n - 1) puts(""); else putchar(' ');
	}
	return 0;
}