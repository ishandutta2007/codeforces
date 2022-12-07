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
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	string s;
	int ans = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int x = 0;
		int y = 0;
		for (int j  = i; j < s.size(); j++) {
			if (s[j] == 'U') x++;
			if (s[j] == 'D') x--;
			if (s[j] == 'L') y++;
			if (s[j] == 'R') y--;

			if (x == 0 &&y == 0) ans++;
		}
	}
	cout << ans << endl;

	return 0;
}