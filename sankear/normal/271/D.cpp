#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
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
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef LOCAL
#define LLD "%I64d"
#else
#define LLD "%I64d"
#endif
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;
 
const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int X1 = 10007;
const int X2 = 4243;
const int MOD1 = 42424243;
const int MOD2 = int(1e9) + 7;

struct hash{
	int h1, h2;
	hash(){}
	hash(int _h1, int _h2){
		h1 = _h1;
		h2 = _h2;
	}
};

hash P = hash(X1, X2);
hash h[2300000];
char s[1515];
char t[100];

hash operator + (const hash &a, const hash &b){
	hash c = hash(a.h1 + b.h1, a.h2 + b.h2);
	if(c.h1 >= MOD1){
		c.h1 -= MOD1;
	}
	if(c.h2 >= MOD2){
		c.h2 -= MOD2;
	}
	return c;
}

hash operator * (const hash &a, const hash &b){
	return hash((ll(a.h1) * b.h1) % MOD1, (ll(a.h2) * b.h2) % MOD2);
}

hash operator + (const hash &a, char b){
	return a + hash(b, b);
}

bool operator == (const hash &a, const hash &b){
	return a.h1 == b.h1 && a.h2 == b.h2;
}

bool operator < (const hash &a, const hash &b){
	if(a.h1 != b.h1){
		return a.h1 < b.h1;
	}
	return a.h2 < b.h2;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int k;
	scanf("%s %s %d", s, t, &k);
	int n = strlen(s), sz = 0;
	for(int i = 0; i < n; i++){
		int cnt = 0;
		hash cur = hash(0, 0);
		for(int j = i; j < n; j++){
			if(t[s[j] - 'a'] == '0'){
				cnt++;
			}
			if(cnt > k){
				break;
			}
			cur = cur * P + s[j];
			h[sz++] = cur;
		}
	}
	sort(h, h + sz);
	sz = unique(h, h + sz) - h;
	printf("%d\n", sz);
	return 0;
}