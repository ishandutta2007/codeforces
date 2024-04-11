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

set<pair<int, int> > A[2];
set<pair<int, int> >::iterator it;

set<pair<int, pair<int, int> > > aa[2];
set<pair<int, pair<int, int> > >::iterator it2;

int w, h, n;


int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	scanf("%d%d%d\n", &w, &h, &n);
	A[0].insert(mp(0, w));
	A[1].insert(mp(0, h));

	aa[0].insert(mp(w, mp(0, w)));
	aa[1].insert(mp(h, mp(0, h)));

	for (int i = 0; i < n; i++) {
		char type;
		int x;
		scanf("%c%d\n", &type, &x);

	        int g = 0;
	        if (type == 'V') g = 0; else g = 1;

	        it = A[g].lower_bound(mp(x, 0));
	        it--;

	        int q1 = (*it).F;
	        int q2 = (*it).S;

	        aa[g].erase(mp(q2 - q1, mp(q1, q2)));
	        A[g].erase(it);

	        A[g].insert(mp(q1, x));
	        A[g].insert(mp(x, q2));
	        aa[g].insert(mp(x - q1, mp(q1, x)));
	        aa[g].insert(mp(q2 - x, mp(x, q2)));

	        it2 = aa[0].end();
	        it2--;
	        long long ans = (*it2).F;
	        it2 = aa[1].end();
	        it2--;
	        ans *= (*it2).F;

	        printf("%I64d\n", ans);

	}
	return 0;
}