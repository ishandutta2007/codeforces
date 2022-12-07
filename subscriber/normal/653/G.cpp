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
int f[1000111];
vector<int> p[500555];

int fu[1000111], inv[1000111];

int pv(int a, int b) {
	if (b == 0) return 1;
	long long r = pv(a, b / 2);
	r = r * r % M;
	if (b % 2) r = r * a % M;
	return r;
}

int C(int n, int k) {
	if (k < 0 || k > n) return 0;
	return fu[n] * 1ll * inv[k] % M * inv[n - k] % M;
}

int gr(int B, int A, int co) {
	if (B <= A) {
		int ret = 0;
		int sum = 0;
		for (int i = 0; i <= B; i++) {
			ret = (ret + C(B, i) * 1ll * sum) % M;

			if (co == 0) {
				sum = (sum + C(A, i)) % M;
			} else if (i > 0) {
				sum = (sum + C(A, i - 1)) % M;
			}
		}
		return ret;
	} else {
		int ret = 0;
		int all = pv(2, B);

		int sum = 0;
		if (co == 1) sum = C(B, 0);
		for (int i = 0; i <= A; i++) {
			sum = (sum + C(B, i + co)) % M;
			
			ret = (ret + C(A, i) * 1ll * (all - sum + M)) % M;			
		}
		return ret;
	}
	

//	int ret = 0;


//	for (int i = 0; i <= B; i++) for (int j = 0; j < i - co; j++) ret = (ret + C(B, i) * 1ll * C(A, j)) % M;
//	return ret;
}

int solve(vector<int> e) {
	int ret = 0;
	//right
	{
		for (int i = 0; i < 20; i++) {
			int A = 0;
			for (int k = 0; k <= i; k++) A += e[k];

			int sum = A;

			int B = n - A;

			if (sum > 0) ret = (ret + gr(B, A - 1, 1) * 1ll * sum) % M;
		}			
	}
	//left
	{
		for (int i = 0; i < 20; i++) {
			int A = 0;
			for (int k = i; k < 20; k++) A += e[k];

			int sum = A;

			int B = n - A;

			if (sum > 0) ret = (ret + gr(B, A - 1, 0) * 1ll * sum) % M;
		}			
	}
/*	for (int i = 0; i < 20; i++) cout << e[i] << " ";
	cout << endl;
	cout << " - " << ret << endl;*/
	return ret;
}

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	fu[0] = 1;
	for (int i = 1; i <= 300000; i++) fu[i] = fu[i - 1] * 1ll * i % M;
	for (int i = 0; i <= 300000; i++) inv[i] = pv(fu[i], M - 2);

	ios::sync_with_stdio(false);
	for (int i = 2; i <= 300000; i++)if (!f[i]) {
		int j = i + i;
		while (j <= 300000) {
			f[j] = i;
			j += i;
		}
	}

	cin >> n;
	for (int i = 0; i < 300000; i++) if (!f[i]) p[i] = vector<int>(20, 0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		while (x > 1) {
			int t = f[x];
			if (t == 0) t = x;

			int cn = 0;

			while (x % t == 0) {
				cn++;
				x /= t;
			}

			p[t][cn]++;
		}
	}
	int ans = 0;
	for (int i = 2; i < 300000; i++) if (!f[i]) {
		int sum = 0;
		for (int j = 0; j < 20; j++) sum += p[i][j];
		if (sum == 0) continue;
		p[i][0] = n - sum;

		ans = (ans + solve(p[i])) % M;
	}
	cout << ans << endl;

	return 0;
}