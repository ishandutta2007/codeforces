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

bool used[2000200];
char a[2000200], b[2000200];
pii pos_a[2000200], pos_b[2000200];

inline int get_num(char a, char b){
	if(a == '1' && b == '1'){
		return 0;
	}
	if(a == '1' && b == '0'){
		return 1;
	}
	if(a == '0' && b == '1'){
		return 2;
	}
	return 3;
}

inline char get(int num){
	if(num < 2){
		return '1';
	}
	return '0';
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	gets(a);
	gets(a);
	gets(b);
	for(int i = 0; i < 2 * n; i++){
		pos_a[i] = mp(get_num(a[i], b[i]), i);
	}
	sort(pos_a, pos_a + 2 * n);
	for(int i = 0; i < 2 * n; i++){
		pos_b[i] = mp(get_num(b[i], a[i]), i);
	}
	sort(pos_b, pos_b + 2 * n);
	int ptr_a = 0, ptr_b = 0;
	for(int i = 0; i < 2 * n; i++){
		if(i % 2 == 0){
			while(ptr_a < 2 * n && used[pos_a[ptr_a].sc]){
				ptr_a++;
			}
			a[i / 2] = get(pos_a[ptr_a].fs);
			used[pos_a[ptr_a].sc] = true;
		}
		else{
			while(ptr_b < 2 * n && used[pos_b[ptr_b].sc]){
				ptr_b++;
			}
			b[i / 2] = get(pos_b[ptr_b].fs);
			used[pos_b[ptr_b].sc] = true;
		}
	}
	int i = 0;
	while(i < n && a[i] == b[i]){
		i++;
	}
	if(i == n){
		printf("Draw\n");
		return 0;
	}
	if(a[i] < b[i]){
		printf("Second\n");
		return 0;
	}
	printf("First\n");
	return 0;
}