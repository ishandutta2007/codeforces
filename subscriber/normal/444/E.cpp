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
pair<int, pt> q[3333];
int p[3333], sz[3333], kol[3333];
int maxsz, sum = 0, bad = 0;

int get(int x) {
	if (p[x] == x) return x;
	return p[x] = get(p[x]);
}

void unite(int x, int y) {
	x = get(x);
	y = get(y);
	maxsz = max(maxsz, sz[x] + sz[y]);
	sz[x] += sz[y];
	kol[x] += kol[y];
	if (kol[x] > sum - sz[x]) bad = 1;


	p[y] = x;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d%d", &q[i].S.F, &q[i].S.S, &q[i].F);
		q[i].S.F--;
		q[i].S.S--;
	}
	sort(q, q + n - 1);
	int ans = 0;
	bad = 0;
	for (int i = 0; i < n; i++) {
		p[i] = i;
		scanf("%d", &sz[i]);
		kol[i] = 1;
		sum += sz[i];
	}
	for (int i = 0; i < n; i++) if (kol[i] > sum - sz[i]) bad = 1;
	if (bad == 0 && n > 1) ans = q[0].F;
	for (int i = 0; i < n - 1; ) {
		int j = i;
		while (j < n && q[j].F == q[i].F) {
			unite(q[j].S.F, q[j].S.S);
			j++;
		}		
		i = j;
		if (bad == 0 && i < n) ans = q[i].F;
	}
	cout << ans << endl;
	return 0;
}