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

int a[N + 10], prev[N + 10], next[N + 10];
vi del, ndel;

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		if(i - 1 >= 0){
			prev[i] = i - 1;
		}
		else{
			prev[i] = -1;
		}
		if(i + 1 < n){
			next[i] = i + 1;
		}
		else{
			next[i] = -1;
		}
	}
	for(int i = 0; i < n; i++){
		if(next[i] != -1 && a[i] > a[next[i]]){
			del.pb(next[i]);
		}
	}
	int ans = 0;
	while(sz(del) > 0){
		ans++;
		int i = 0;
		ndel.clear();
		while(i < sz(del)){
			int j = i;
			while(j + 1 < sz(del) && next[del[j]] == del[j + 1]){
				j++;
			}
			if(prev[del[i]] != -1){
				next[prev[del[i]]] = next[del[j]];
			}
			if(next[del[j]] != -1){
				prev[next[del[j]]] = prev[del[i]];
			}
			if(prev[del[i]] != -1 && next[del[j]] != -1){
				if(a[prev[del[i]]] > a[next[del[j]]]){
					ndel.pb(next[del[j]]);
				}
			}
			i = j + 1;
		}
		del = ndel;
	}
	printf("%d\n", ans);
	return 0;
}