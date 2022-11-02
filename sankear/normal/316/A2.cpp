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

char s[N + 100];
bool used[20];
ll f[20];
ll c[20][20];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	gets(s);
	int n = strlen(s);
	for(int i = 0; i <= 10; i++){
		c[i][0] = 1;
		for(int j = 1; j <= i; j++){
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	f[0] = 1;
	for(int i = 1; i <= 10; i++){
		f[i] = f[i - 1] * i;
	}
	if(s[0] == '?'){
		ll ans = 9;
		int len = 0;
		for(int i = 1; i < n; i++){
			if(s[i] == '?'){
				len++;
			}
		}
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(s[i] >= 'A' && s[i] <= 'J' && !used[s[i] - 'A']){
				cnt++;
				used[s[i] - 'A'] = true;
			}
		}
		ans *= c[10][cnt] * f[cnt];
		printf(LLD, ans);
		for(int i = 0; i < len; i++){
			printf("0");
		}
		puts("");
		return 0;
	}
	if(s[0] >= 'A' && s[0] <= 'J'){
		ll ans = 1;
		int len = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '?'){
				len++;
			}
		}
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(s[i] >= 'A' && s[i] <= 'J' && !used[s[i] - 'A']){
				cnt++;
				used[s[i] - 'A'] = true;
			}
		}
		ans *= c[9][1] * c[9][cnt - 1] * f[cnt - 1];
		printf(LLD, ans);
		for(int i = 0; i < len; i++){
			printf("0");
		}
		puts("");
		return 0;
	}
	ll ans = 1;
	int len = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '?'){
			len++;
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(s[i] >= 'A' && s[i] <= 'J' && !used[s[i] - 'A']){
			cnt++;
			used[s[i] - 'A'] = true;
		}
	}
	ans *= c[10][cnt] * f[cnt];
	printf(LLD, ans);
	for(int i = 0; i < len; i++){
		printf("0");
	}
	puts("");
	return 0;
}