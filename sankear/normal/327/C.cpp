#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5);
const int M = 5;
const int MOD = int(1e9) + 7;

int n;
char s[N + 10];
int p[N + 10];
pii ans1;

inline void norm(int &a){
	while(a >= MOD){
		a -= MOD;
	}
}

inline int calc(int a, ll b){
	int res = 1;
	while(b > 0){
		if(b % 2 != 0){
			res = (ll(res) * a) % MOD;
		}
		a = (ll(a) * a) % MOD;
		b /= 2;
	}
	return res;
}

pii calc(int k){
	if(k == 1){
		ans1.fs = ans1.sc = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '0' || s[i] == '5'){
				ans1.fs += calc(2, i);
				norm(ans1.fs);
				ans1.sc++;
				norm(ans1.sc);
			}
		}
		return ans1;
	}
	if(k % 2 == 0){
		pii res = calc(k / 2);
		pii ans;
		ans.fs = (res.fs + ll(res.fs) * calc(2, ll(k / 2) * n)) % MOD;
		ans.sc = 2 * res.sc;
		norm(ans.sc);
		return ans;
	}
	pii res = calc(k - 1);
	pii ans;
	ans.fs = (res.fs + ll(ans1.fs) * calc(2, ll(k - 1) * n)) % MOD;
	ans.sc = res.sc + ans1.sc;
	norm(ans.sc);
	return ans;
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	gets(s);
	n = strlen(s);
	int k;
	scanf("%d", &k);
	pii ans = calc(k);
	printf("%d\n", ans.fs);
	return 0;
}