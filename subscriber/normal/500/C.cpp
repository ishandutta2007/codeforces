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

int n, m;

int w[N], b[N], p[N];

int v[N];

int used[N];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) scanf("%d", &w[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]), b[i]--;

	int k = 0;

	for (int i = 0; i < m; i++) if (!used[b[i]]) {
		used[b[i]] = 1;
		p[k++] = b[i];
	}
	for (int i = 0; i < n; i++) if (!used[i]) p[k++] = i;


	for (int i = 0; i < m; i++) {
		int h = -1;
		for (int j = 0; j < n; j++) if (p[j] == b[i]) h = j;

		for (int j = 0; j < h; j++) v[p[j]]++;

		for (int j = h; j > 0; j--) p[j] = p[j - 1];
		p[0] = b[i];
	}

/*	sort(v, v + n);
	sort(w, w + n);
	reverse(w, w + n);*/

	long long ans = 0;
	for (int i = 0; i < n; i++) ans += w[i] * 1ll * v[i];

	cout << ans << endl;


	return 0;
}