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

long long a, b;

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> a >> b;
	if (a == b || __gcd(a, b) > 1) {
		puts("Impossible");
		return 0;
	}
	vector<pair<long long, char> > ans;
	while (a + b > 2) {
		if (a > b) {
			long long t = (a - 1) / b;
			ans.pb(mp(t, 'A'));
			a -= b * t;			
		} else {
			long long t = (b - 1) / a;
			ans.pb(mp(t, 'B'));
			b -= a * t;
		}
	}
//	reverse(ans.begin(), ans.end());
//	long long x = 1, y = 

	for (int i = 0; i < ans.size(); i++) cout << ans[i].F << ans[i].S;
	cout << endl;
	return 0;
}