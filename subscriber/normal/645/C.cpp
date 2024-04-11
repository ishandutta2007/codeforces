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

int n, k;
string s;

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> k;
	cin >> s;

	vector<int> e;
	for (int i = 0; i < n; i++)if (s[i] == '0') e.pb(i);

	int l = 1;
	int r = n;

	while (l < r) {
		int mid = (l + r) / 2;

		int ll = 0;
		int rr = 0;

		int ok = 0;

		for (int i = 0; i < e.size(); i++) {
			while (e[i] - e[ll] > mid) ll++;
			while (rr + 1 < e.size() && e[rr + 1] - e[i] <= mid) rr++;
			if (rr - ll + 1 >= k + 1) {
				ok = 1;
				break;
			}
		}
		if (ok) r = mid; else l = mid + 1;
	}
	cout << l << endl;

	return 0;
}