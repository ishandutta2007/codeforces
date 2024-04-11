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
#define N 311111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int a[N];
pair<int, int> com[N];
int su[N];

long long ans = 0;
int n, k;

int cnt[1000111];

vector<int> vl;

void solve(int l, int r) {
	if (l == r) return;

	int mid = (l + r) >> 1;

	solve(l, mid);
	solve(mid + 1, r);

	vl.clear();

	for (int i = l; i <= mid; i++) {
		while (vl.size() > 0 && com[i] > com[vl.back()]) vl.pop_back();
		vl.pb(i);
	}				

	int u = mid;

	for (int i = vl.size() - 1; i >= 0; i--) {
		int x = vl[i];
		while (u + 1 <= r && com[u + 1] < com[x]) {
			u++;
			cnt[su[u + 1]]++;
		}
		int to;
		if (i == 0) to = l; else to = vl[i - 1] + 1;

		for (int j = to; j <= x; j++) {
			int h = (su[j] + a[x]) % k;
			ans += cnt[h];
		}
	}
	for (int i = mid + 1; i <= u; i++) cnt[su[i + 1]]--;

	vl.clear();

	for (int i = r; i > mid; i--) {
		while (vl.size() > 0 && com[i] > com[vl.back()]) vl.pop_back();
		vl.pb(i);
	}

	u = mid + 1;

	for (int i = vl.size() - 1; i >= 0; i--) {
		int x = vl[i];
		while (u - 1 >= l && com[u - 1] < com[x]) {
			u--;
			cnt[su[u]]++;	
		}
		int to;
		if (i == 0) to = r; else to = vl[i - 1] - 1;

		for (int j = x; j <= to; j++) {
			int h = (su[j + 1] - (a[x] % k) + k) % k;
			ans += cnt[h];
		}
	}

	for (int i = u; i <= mid; i++) cnt[su[i]]--;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);

		com[i] = mp(a[i], i);
	}
	for (int i = 0; i < n; i++) su[i + 1] = (su[i] + a[i]) % k;
	solve(0, n - 1);
	cout << ans << endl;
	return 0;
}