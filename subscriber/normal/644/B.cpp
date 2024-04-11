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

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	int n, b;
	cin >> n >> b;

	set<long long> qu;

	for (int i = 0; i < n; i++) {
		int t, d;
		scanf("%d%d", &t, &d);

		while (qu.size() > 0 && (*qu.begin()) <= t) qu.erase(qu.begin());

		long long out;
		if (qu.size() == b + 1) {
			printf("-1 ");
			continue;
		}

		if (qu.size() == 0) out = t + d; else {
			set<long long>::iterator it = qu.end();
			it--;
			out = (*it) + d;
		}
		printf("%I64d ", out);
		qu.insert(out);
	}

	return 0;
}