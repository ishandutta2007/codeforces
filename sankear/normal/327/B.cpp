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
const int MAGIC = int(1e7);
const int N = int(1e5);

bool used[MAGIC + 10];
int a[N + 10];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	int ptr = 2;
	for(int i = 0; i < n; i++){
		while(ptr <= MAGIC && used[ptr]){
			ptr++;
		}
		if(ptr > MAGIC){
			cerr << "FUCK" << endl;
			while(true);
		}
		a[i] = ptr++;
		for(int j = a[i]; j <= MAGIC; j += a[i]){
			used[j] = true;
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	puts("");
	return 0;
}