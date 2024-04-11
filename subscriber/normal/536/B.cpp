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
#define N 2011111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int x[N], s[N];
char a[N];
int need[N], p[N];
int n, m;


int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	scanf("%d%d\n", &n, &m);
	gets(a);
	int k = strlen(a);
	for (int i = 0; i < m; i++) {
		scanf("%d", &x[i]);
		x[i]--;

		s[x[i]]++;
		s[x[i] + k]--;
	}
	int ans = 1;
	int ss = 0;
	for (int i = 0; i < n; i++) {
		ss += s[i];
		if (ss == 0) ans = ans * 26ll % M;
	}
	for (int i = 1; i < m; i++) {
		int d = k - (x[i] - x[i - 1]);
		if (d >= 0) {
			need[d] = 1;
//			cout << d << endl;
		}				
	}
	p[0] = -1;
	for (int i = 1; i < k; i++) {
		int x = p[i - 1];
		while (x != -1 && a[x + 1] != a[i]) x = p[x];
		if (a[x + 1] != a[i]) p[i] = -1; else p[i] = x + 1;
	}
	int x = k - 1;
	while (x != -1) {
		need[p[x] + 1] = 0;
		x = p[x];
	}
	for (int i = 1; i <= k; i++) if (need[i]) {
		puts("0");
		return 0;
	}
	cout << ans << endl;

	return 0;
}