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

long long ans = 0;

int a[N], od[N];
long long sum[N], out[N];
int p[N];
int n;

int get(int x) {
	if (p[x] == x) return x;
	return p[x] = get(p[x]);
}

void merg(int x, int y) {
	if (x < 0 || x >= n || p[x] == -1) return;
	if (y < 0 || y >= n || p[y] == -1) return;
	x = get(x);
	y = get(y);
	sum[x] += sum[y];
	ans = max(ans, sum[x]);
	p[y] = x;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		cin >> od[i];
		od[i]--;
	}
	for (int i = 0; i < n; i++) p[i] = -1;
	ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		out[i] = ans;

		int id = od[i];

		p[id] = id;
		sum[id] = a[id];
		ans = max(ans, sum[id]);
		merg(id - 1, id);
		merg(id, id + 1);
	}
	for (int i = 0; i < n; i++) cout << out[i] << endl;
	return 0;
}