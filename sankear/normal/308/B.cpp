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
const int N = int(1e6);
const int LEN = int(5e6);
const int steps = 20;

int sum[N + 10], len[N + 10];
char *s[N + 10];
char buf[LEN + 10];
int go[steps + 1][N + 10], val[steps + 1][N + 10];

inline int get_sum(int l, int r){
	return sum[r] - (l > 0 ? sum[l - 1] : 0);
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//cerr << "mem = " << (sizeof(len) + sizeof(sum) + sizeof(buf) + sizeof(go) + sizeof(val)) / 1024 / 1024 << endl;
	int n, r, c;
	scanf("%d %d %d", &n, &r, &c);
	for(int i = 0; i < n; i++){
		scanf("%s", buf);
		len[i] = strlen(buf);
		s[i] = new char[len[i] + 1];
		strcpy(s[i], buf);
	}
	for(int i = 0; i < n; i++){
		sum[i] = (i > 0 ? sum[i - 1] : 0) + len[i];
	}
	int ptr = 0;
	for(int i = 0; i < n; i++){
		if(len[i] > c){
			go[0][i] = -1;
		}
		else{
			ptr = max(ptr, i);
			while(ptr + 1 < n && get_sum(i, ptr + 1) + ptr + 1 - i <= c){
				ptr++;
			}
			go[0][i] = ptr + 1;
			val[0][i] = ptr - i + 1;
		}
	}
	for(int i = 1; i <= steps; i++){
		for(int j = 0; j < n; j++){
			if(go[i - 1][j] == -1 || go[i - 1][j] == n || go[i - 1][go[i - 1][j]] == -1){
				go[i][j] = -1;
				continue;
			}
			go[i][j] = go[i - 1][go[i - 1][j]];
			val[i][j] = val[i - 1][j] + val[i - 1][go[i - 1][j]];
		}
	}
	int ans = 0, best = -1;
	for(int i = 0; i < n; i++){
		int cur = r, ptr = i, res = 0;
		for(int j = steps; j >= 0 && ptr < n; j--){
			if((1 << j) <= cur && go[j][ptr] != -1){
				cur -= (1 << j);
				res += val[j][ptr];
				ptr = go[j][ptr];
			} 
		}
		if(res > ans){
			ans = res;
			best = i;
		}
	}
	if(ans == 0){
		return 0;
	}
	printf("%s", s[best]);
	int cur = len[best];
	for(int i = 1; i < ans; i++){
		if(cur + len[best + i] + 1 <= c){
			if(i > 0){
				printf(" ");
			}
			printf("%s", s[best + i]);
			cur += len[best + i] + 1;
		}
		else{
			puts("");
			printf("%s", s[best + i]);
			cur = len[best + i];
		}
	}
	puts("");
	return 0;
}