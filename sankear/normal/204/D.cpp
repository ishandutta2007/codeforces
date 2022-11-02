#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <queue>
#include <cassert>

using namespace std;

//#define HOME
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define next _next
#define rank _rank
#define prev _prev
#define sz(s) int((s).size())

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const double eps = 1e-9;
const double pi = acos(double(-1));
const int inf = int(1e9);
const ll MOD = ll(1e9 + 7);

int sum[1000100];
char s[1000100];
ll suff[1000100];
ll d[1000100][2];

inline int get(int l, int r){
	if(l > r){
		return 0;
	}
	return sum[r] - (l > 0 ? sum[l - 1] : 0);
}

inline void norm(ll &a){
	while(a < 0){
		a += MOD;
	}
	while(a >= MOD){
		a -= MOD;
	}
}

inline ll calc(ll a, ll b){
	ll res = 1;
	while(b > 0){
		if(b % 2 != 0){
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b /= 2;
	}
	return res;
}

pair <int, ll> v1[1000100], v2[1000100];
ll p[1000100], rp[1000100];

int main(){
#ifdef HOME
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif
	/*cout << "1000000 1" << endl;
	for(int i = 0; i < 1000000; i++){
		cout << "X";
	}
	cout << endl;
	return 0;*/
	int n, k;
	scanf("%d %d\n", &n, &k);
	gets(s);
	for(int i = 0; i < n; i++){
		sum[i] = (i > 0 ? sum[i - 1] : 0) + (s[i] == 'W');
	}
	for(int i = 0; i < n; i++){
		if(i - k + 1 >= 0 && get(i - k + 1, i) == 0 && (i - k < 0 || s[i - k] != 'B')){
			d[i][0] = (i - k - 1 >= 0 ? d[i - k - 1][1] : 1);
		}
		d[i][1] = (i > 0 ? d[i - 1][1] : 1) * (s[i] == 'X' ? 2 : 1) - d[i][0];
		norm(d[i][1]);
	}
	int k1 = 0;
	for(int i = 0; i < n; i++){
		if(i + k - 1 < n && get(i, i + k - 1) == 0 && (i == 0 || s[i - 1] != 'B')){
			v1[k1++] = mp(i, d[i + k - 1][0]);
		}
	}
	for(int i = 0; i < n; i++){
		sum[i] = (i > 0 ? sum[i - 1] : 0) + (s[i] == 'B');
	}
	for(int i = n - 1; i >= 0; i--){
		d[i][0] = 0;
		if(i + k - 1 < n && get(i, i + k - 1) == 0 && (i + k >= n || s[i + k] != 'W')){
			d[i][0] = (i + k + 1 < n ? d[i + k + 1][1] : 1);
		}
		d[i][1] = (i < n - 1 ? d[i + 1][1] : 1) * (s[i] == 'X' ? 2 : 1) - d[i][0];
		norm(d[i][1]);
	}
	int k2 = 0;
	for(int i = 0; i < n; i++){
		if(i + k - 1 < n && get(i, i + k - 1) == 0 && (i + k >= n || s[i + k] != 'W')){
			v2[k2++] = mp(i, d[i][0]);
		}
	}
	for(int i = 0; i < n; i++){
		sum[i] = (i > 0 ? sum[i - 1] : 0) + (s[i] == 'X');
	}
	p[0] = 1;
	rp[0] = calc(p[0], MOD - 2);
	for(int i = 1; i <= n; i++){
		p[i] = p[i - 1] * 2;
		norm(p[i]);
		rp[i] = calc(p[i], MOD - 2);
	}
	for(int i = k2 - 1; i >= 0; i--){
		suff[i] = suff[i + 1] + (v2[i].sc * p[v2[i].fs > 0 ? sum[v2[i].fs - 1] : 0]) % MOD;
		norm(suff[i]);
	}
	ll ans = 0;
	int pos = 0;
	for(int i = 0; i < k1; i++){
		while(pos < k2 && v2[pos].fs <= v1[i].fs + k - 1){
			pos++;
		}
		if(pos < 0 || pos >= k2){
			continue;
		}
		ll res = (v1[i].sc * rp[sum[v1[i].fs + k - 1]]) % MOD;
		res = (res * suff[pos]) % MOD;
		ans += res;
		norm(ans);
	}
	cout << ans << endl;
#ifdef HOME
	printf("time = %.18lf\n", (clock() - start) / CLOCKS_PER_SEC);
#endif
	return 0;
}