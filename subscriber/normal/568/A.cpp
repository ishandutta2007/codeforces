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

const int maxn = 1200111;
int f[maxn], ok[maxn];

int p, q;

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> p >> q;
	f[1] = 1;
	for (int i = 2; i < maxn; i++) if (!f[i]) {
		int j = i + i;
		while (j < maxn) {
			f[j] = 1;
			j += i;
		}
	}
	for (int i = 1; i < maxn; i++) {
		SS q;
		q << i;
		string s = q.str();
		reverse(s.begin(), s.end());
		if (s == q.str()) ok[i] = 1;
	}
	int ans = -1;
	long long q1 = 0, q2 = 0;
	for (int i = 1; i < maxn; i++) {
		if (f[i] == 0) q1++;
		if (ok[i]) q2++;
		if (q2 * p >= q1 * q) ans = i;
	}
	if (ans == -1) puts("Palindromic tree is better than splay tree"); else 
	cout << ans << endl;
	return 0;
}