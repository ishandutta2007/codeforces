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

const int inf = int(1e6);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 1000;

char s[N + 10];
int cnt[30];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	gets(s);
	int n = strlen(s);
	int m;
	scanf("%d", &m);
	for(int i = 0; i < n; i++){
		cnt[s[i] - 'a']++;
	}
	int ans = -1, l = 1, r = inf;
	while(l <= r){
		int mid = (l + r) / 2, sum = 0;
		for(int i = 0; i < 26; i++){
			sum += (cnt[i] + mid - 1) / mid;
		}
		if(sum <= m){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	if(ans == -1){
		puts("-1");
		return 0;
	}
	int ptr = 0;
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < (cnt[i] + ans - 1) / ans; j++){
			s[ptr++] = 'a' + i;
		}
	}
	while(ptr < m){
		s[ptr++] = 'a';
	}
	s[ptr] = 0;
	printf("%d\n%s\n", ans, s);
	return 0;
}