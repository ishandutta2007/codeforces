#include<bits/stdc++.h>
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

vector<int> A[2];
vector<int> ans;
int a[N];
int n;


int gg(int mid) {
		A[0].clear();
		A[1].clear();
		for (int i = 0; i < n; i++) {
			int x = a[i];
			while (x > mid) x >>= 1;
			A[0].pb(x);
		}
		sort(A[0].rbegin(), A[0].rend());
		int u[2];
		u[0] = u[1] = 0;


		ans.clear();
		while (u[0] < A[0].size() || u[1] < A[1].size()) {
			int t = 0;
			if (u[0] == A[0].size() || (u[1] < A[1].size() && A[1][u[1]] > A[0][u[0]])) t = 1;

			int val = A[t][u[t]];
			u[t]++;

			if (u[0] == A[0].size() && u[1] == A[1].size()){
				ans.pb(val);
				continue;
			}
			t = 0;
			if (u[0] == A[0].size() || (u[1] < A[1].size() && A[1][u[1]] > A[0][u[0]])) t = 1;
			
			if (A[t][u[t]] != val) {
				ans.pb(val);
				continue;
			}

			if (val == 1) return 0;

			A[1].pb(val >> 1);
		}
		return 1;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	int l = 1;
	int r = 1e9 + 1;

	while (l < r) {
		int mid = (l + r) / 2;

		if (gg(mid)) r = mid; else l = mid + 1;
	}
	gg(l);

//	assert(ans.size() == n);

	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	

	return 0;
}