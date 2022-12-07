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
#define N 411111

#define TASK "1"

using namespace std;

long long a[1011][1011];
long long ans[1011];
int n;

vector<long long> solve(long long ab, long long ac, long long bc) {
	long long g = __gcd(ab, ac);
	long long b = ab / g;
	long long c = ac / g;

	long long x = bc / (b * c);

	int s = sqrt(x + 0.5);

	b *= s;
	c *= s;
	return {ab / b, b, c};

}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];

	for (int i = 2; i < n; i++) {
		auto v = solve(a[0][1], a[0][i], a[1][i]);
		ans[0] = v[0];
		ans[1] = v[1];
		ans[i] = v[2];
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	return 0;
}