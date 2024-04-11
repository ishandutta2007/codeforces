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
#include <complex>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define fs first
#define sc second
#define next _next
#define prev _prev
#define hash _hash
#define link _link
#define y0 yy0
#define y1 yy1

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;
typedef long double ld;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5) + 100;

int res[N];
pii a[N];
pair <int, pii> b[N];
set <pii> s;

int main(){
	int n, m, S;
	scanf("%d %d %d", &n, &m, &S);
	for(int i = 0; i < m; i++){
		scanf("%d", &a[i].fs);
		a[i].sc = i;
	}
	sort(a, a + m);
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i].fs);
		b[i].sc.sc = i;
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i].sc.fs);
	}
	sort(b, b + n);
	int ans = -1, l = 1, r = m;
	while(l <= r){
		int mid = (l + r) / 2, i = m - 1, j = n - 1;
		s.clear();
		ll sum = 0;
		while(i >= 0 && sum <= S){
			while(j >= 0 && b[j].fs >= a[i].fs){
				s.insert(b[j--].sc);
			}
			if(sz(s) == 0){
				break;
			}
			sum += s.begin()->fs;
			s.erase(s.begin());
			i -= mid;
		}
		if(i < 0 && sum <= S){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	if(ans == -1){
		puts("NO");
		return 0;
	}
	s.clear();
	int i = m - 1, j = n - 1;
	while(i >= 0){
		while(j >= 0 && b[j].fs >= a[i].fs){
			s.insert(b[j--].sc);
		}
		for(int j = 0; j < ans; j++){
			if(i - j >= 0){
				res[a[i - j].sc] = s.begin()->sc;
			}
		}
		s.erase(s.begin());
		i -= ans;
	}
	puts("YES");
	for(int i = 0; i < m; i++){
		printf("%d ", res[i] + 1);
	}
	puts("");
	return 0;
}