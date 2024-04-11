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

vi ch1, ch2, ch3, lst1, lst2, lst3;

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int cur;
		scanf("%d", &cur);
		if(cur == 0){
			ch1.pb(cur);
			continue;
		}
		if(cur < 0){
			ch2.pb(cur);
			continue;
		}
		ch3.pb(cur);
	}
	for(int i = 0; i < sz(ch1); i++){
		lst3.pb(ch1[i]);
	}
	if(sz(ch3) == 0){
		for(int i = 0; i < 2; i++){
			lst2.pb(ch2[i]);
		}
		lst1.pb(ch2[2]);
		for(int i = 3; i < sz(ch2); i++){
			lst3.pb(ch2[i]);
		}
	}
	else{
		for(int i = 0; i < sz(ch3); i++){
			lst2.pb(ch3[i]);
		}
		lst1.pb(ch2[0]);
		for(int i = 1; i < sz(ch2); i++){
			lst3.pb(ch2[i]);
		}
	}
	printf("%d", sz(lst1));
	for(int i = 0; i < sz(lst1); i++){
		printf(" %d", lst1[i]);
	}
	printf("\n%d", sz(lst2));
	for(int i = 0; i < sz(lst2); i++){
		printf(" %d", lst2[i]);
	}
	printf("\n%d", sz(lst3));
	for(int i = 0; i < sz(lst3); i++){
		printf(" %d", lst3[i]);
	}
	printf("\n");
	return 0;
}