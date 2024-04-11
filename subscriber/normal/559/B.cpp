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

char a[N], b[N];
int n;

void go(int l, int r) {
	if ((r - l + 1) % 2) return;
	int mid = (l + r) / 2;
	go(l, mid);
	go(mid + 1, r);

	int ls = 0;
	int d = (r - l + 1) / 2;
	for (int i = 0; i < d; i++) {
		if (a[mid + 1 + i] < a[l + i]) {
			ls = 1;
			break;
		} else if (a[mid + 1 + i] > a[l + i]) {
			ls = 0;
			break;
		}
	}
	if (ls) {
		for (int i = 0; i < d; i++) swap(a[mid + 1 + i], a[l + i]);
	}
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	gets(a);
	gets(b);
	n = strlen(a);

	go(0, n - 1);
	for (int i = 0; i < n; i++) swap(a[i], b[i]);
	go(0, n - 1);

	int ok = 1;
	for (int i = 0; i < n; i++) if (a[i] != b[i]) ok = 0;
	if (ok) puts("YES"); else puts("NO");
	return 0;
}