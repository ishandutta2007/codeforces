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
pair<pair<int, int>, int> q[1000111];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);

		int xx = x / 1000;
		int yy = y;
		if (xx % 2) yy = -yy;

		q[i] = mp(mp(xx, yy), i);
	}
	sort(q, q + n);
	for (int i = 0; i < n; i++) {
		printf("%d", q[i].S + 1);
		if (i + 1 == n) puts(""); else putchar(' ');
	}
	return 0;
}