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
#define LLD "%lld"
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
const int N = 50 * 1000;

char s[N + 10];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	gets(s);
	int n = strlen(s), len = 1;
	while(2 * len <= n){
		int pos = -1, res = 0;
		for(int i = 0; i + 2 * len - 1 < n; i++){
			while(i + res < i + len && s[i + res] == s[i + len + res]){
				res++;
			}
			if(res == len){
				pos = i;
				break;
			}
			res = max(res - 1, 0);
		}
		if(pos == -1){
			len++;
			continue;
		}
		for(int i = pos; i + len < n; i++){
			s[i] = s[i + len];
		}
		n -= len;
		s[n] = 0;
	}
	puts(s);
	return 0;
}