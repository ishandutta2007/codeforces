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

char s[1010];
int cnt[30];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", s);
	int n = strlen(s);
	for(int i = 0; i < n; i++){
		cnt[s[i] - 'a']++;
	}
	for(int i = 0; i < 26; i++){
		cnt[i] %= 2;
	}
	bool fl = true;
	for(int i = 0; i < 26; i++){
		if(cnt[i] != 0){
			fl = false;
			break;
		}
	}
	if(fl){
		printf("First\n");
		return 0;
	}
	int ans = 0;
	for(int i = 0; i < 26; i++){
		ans = (ans + cnt[i]) % 2;
	}
	if(ans == 1){
		printf("First\n");
		return 0;
	}
	printf("Second\n");
	return 0;
}