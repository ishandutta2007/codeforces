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

pair<pt, int> q[N];
int n;

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> q[i].F.F >> q[i].F.S;
		q[i].S = i + 1;
	}
	sort(q, q + n);
	long long A = q[1].F.S - q[0].F.S;
	long long B = q[0].F.F - q[1].F.F;
	long long C = -q[0].F.F * A -q[0].F.S * B;

	for (int i = 2; i < n; i++) if (A * q[i].F.F + B * q[i].F.S + C != 0) {
		cout << q[0].S << " " << q[1].S << " " << q[i].S << endl;
		return 0;
	}
	return 0;
}