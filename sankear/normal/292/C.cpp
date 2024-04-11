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

vector <string> ans;
bool good[30];
int len[30], used[30];
char s[30], add[30];

inline bool check(int x, int y){
	int pos = x, ptr = 0;
	for(int i = 0; i < 4; i++){
		if(pos > len[i]){
			pos -= len[i];
			ptr += len[i];
			continue;
		}
		if(pos == 1){
			if(len[i] > 1 && s[ptr] == '0'){
				return false;
			}
		}
		if(pos == len[i]){
			int ch = 0;
			for(int j = 0; j < len[i]; j++){
				ch = ch * 10 + s[ptr + j] - '0';
			}
			if(ch > 255){
				return false;
			}
		}
		break;
	}
	pos = x;
	ptr = y - 1;
	for(int i = 3; i >= 0; i--){
		if(pos > len[i]){
			pos -= len[i];
			ptr -= len[i];
			continue;
		}
		if(pos == len[i]){
			if(len[i] > 1 && s[ptr - len[i] + 1] == '0'){
				return false;
			}
			int ch = 0;
			for(int j = 0; j < len[i]; j++){
				ch = ch * 10 + s[ptr - len[i] + 1 + j] - '0';
			}
			if(ch > 255){
				return false;
			}
		}
		break;
	}
	return true;
}

void gen2(int x, int y, int z){
	if((y + 1) / 2 - x < z){
		return;
	}
	if(x >= (y + 1) / 2){
		int ptr = 0, sz = 0;
		for(int i = 0; i < 4; i++){
			if(i > 0){
				add[sz++] = '.';
			}
			int ch = 0;
			for(int j = 0; j < len[i]; j++){
				ch = ch * 10 + s[ptr] - '0';
				add[sz++] = s[ptr++];
			}
			if(ch > 255){
				return;
			}
		}
		add[sz] = 0;
		ans.pb(add);
		return;
	}
	for(int i = 0; i < 10; i++){
		if(!good[i]){
			continue;
		}
		int nz = z;
		if(used[i] == 0){
			nz--;
		}
		used[i]++;
		s[x] = s[y - x - 1] = '0' + i;
		if(check(x + 1, y)){
			gen2(x + 1, y, nz);
		}
		used[i]--;
	}
}

void gen1(int x, int y, int z){
	if(x >= 4){
		for(int i = 0; i < y; i++){
			s[i] = '?';
		}
		gen2(0, y, z);
		return;
	}
	for(int i = 1; i <= 3; i++){
		len[x] = i;
		gen1(x + 1, y + i, z);
	}
}

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
		good[cur] = true;
	}
	gen1(0, 0, n);
	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
	printf("%d\n", sz(ans));
	for(int i = 0; i < sz(ans); i++){
		printf("%s\n", ans[i].c_str());
	}
	return 0;
}