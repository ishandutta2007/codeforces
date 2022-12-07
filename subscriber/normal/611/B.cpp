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
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	ios::sync_with_stdio(false);

	long long a, b;
	int ans = 0;
	cin >> a >> b;

	for (int len = 0; len < 70; len++) for (int g = 0; g < len - 1; g++) {
		long long x = 0;

		for (int i = 0; i < len; i++) {
			if (i != g) x += pw(i);
			if (x > b) break;
		}
		if (x >= a && x <= b) ans++;
	}
	cout << ans << endl;
	return 0;
}