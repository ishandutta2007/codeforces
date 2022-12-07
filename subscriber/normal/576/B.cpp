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

int n;
int p[N], was[N];


void gop(int t) {
	puts("YES");
	was[t] = 1;
	for (int i = 0; i < n; i++) if (!was[i]) {
		int x = i;
		int sz = 0;
		for(;;) {
			printf("%d %d\n", t + 1, x + 1);

			was[x] = 1;
			sz++;
			x = p[x];
			if (x == i) break;
		}
	}
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		p[i]--;
	}
	int t = -1;


	for (int i = 0; i < n; i++) if (p[i] == i) {
		t = i;
		break;
	}

	if (t != -1) {
		gop(t);
		return 0;
	}			



	for (int i = 0; i < n; i++) if (p[p[i]] == i) {
		t = i;
		break;
	}
	if (t == -1) {
		puts("NO");
		return 0;
	}
	was[t] = 1;
	was[p[t]] = 1;
	for (int i = 0; i < n; i++) if (!was[i]) {
		int x = i;
		int sz = 0;
		for(;;) {
			was[x] = 1;
			sz++;
			x = p[x];
			if (x == i) break;
		}
		if (sz % 2) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	printf("%d %d\n", t + 1, p[t] + 1);
	for (int i = 0; i < n; i++) was[i] = 0;
	was[t] = 1;
	was[p[t]] = 1;
	for (int i = 0; i < n; i++) if (!was[i]) {
		int x = i;
		int sz = 0;
		for(;;) {
			if (sz % 2 == 0) {
				printf("%d %d\n", t + 1, x + 1);
			} else {
				printf("%d %d\n", p[t] + 1, x + 1);
			}

			was[x] = 1;
			sz++;
			x = p[x];
			if (x == i) break;
		}
	}

	return 0;
}