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
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		char ch = s[i];

		int and1a = ('@' < ch);
		int and1b = ('[' > ch);

		int and2a = ('`' < ch);
		int and2b = ('{' > ch);

		int t1a = (and1a & and1b);
		int t1b = 0;
		if (ch >= 'a' && ch <= 'z') t1b = ch - 'a' + 1;
		if (ch >= 'A' && ch <= 'Z') t1b = ch - 'A' + 1;

		int t2a = t1b;
		int t2b = (and2a && and2b);

		int mi = (t1a * t1b - t2a * t2b);
		ans += mi;
	}
	cout << ans << endl;

	return 0;
}