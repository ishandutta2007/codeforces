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


int a, b, c, d;

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> a >> b >> c >> d;

	long double l = 0;
	long double r = 2e9;

	for (int it = 0; it < 500; it++) {
		long double mid = (l + r) / 2;

		long double q1 = (a + mid) * (d + mid);
		q1 = min(q1, (a - mid) * (d + mid));
		q1 = min(q1, (a - mid) * (d - mid));
		q1 = min(q1, (a + mid) * (d - mid));

		long double q2 = (a + mid) * (d + mid);
		q2 = max(q2, (a - mid) * (d + mid));
		q2 = max(q2, (a - mid) * (d - mid));
		q2 = max(q2, (a + mid) * (d - mid));
		

		long double w1 = (b + mid) * (c + mid);
		w1 = min(w1, (b - mid) * (c + mid));
		w1 = min(w1, (b - mid) * (c - mid));
		w1 = min(w1, (b + mid) * (c - mid));

		long double w2 = (b + mid) * (c + mid);
		w2 = max(w2, (b - mid) * (c + mid));
		w2 = max(w2, (b - mid) * (c - mid));
		w2 = max(w2, (b + mid) * (c - mid));
		
		if (max(q1, w1) <= min(q2,w2)) r = mid; else l = mid;
	}
	printf("%.10lf\n", (double) (l + r) / 2);
	return 0;
}