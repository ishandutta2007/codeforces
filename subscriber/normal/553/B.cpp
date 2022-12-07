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

int n;
long long k, fi[55];

int ans[55];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> k;
	k--;
	fi[0] = 1;
	fi[1] = 1;
	for (int i = 2; i <n; i++) fi[i] = min(fi[i - 1] + fi[i - 2], k + 1);

	int l = 0;
	while (l < n) {
		if (fi[n - l - 1] > k) {
			ans[l] = l;
			l++;
		} else {
			k -= fi[n - l - 1];
			ans[l] = l + 1;
			ans[l + 1] = l;
			l += 2;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] + 1;
		if (i + 1 == n) puts(""); else putchar(' ');
	}
	return 0;
}