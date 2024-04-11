#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <complex>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define next _next
#define prev _prev
#define rank _rank

typedef long long ll;
typedef long long llong;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int maxn = int(1e7);

int a[100100], b[100100];
int mind[10000100];
int primes[1000100], p1[1000100], p2[1000100], need1[1000100], need2[1000100];

int main(){
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("painting.in", "r", stdin);
    //freopen("painting.out", "w", stdout);
	int sz = 0;
	for(int i = 2; i <= maxn; i++){
		if(mind[i] == 0){
			mind[i] = i;	
			primes[sz++] = i;
		}
		for(int j = 0; j < sz && primes[j] <= mind[i] && ll(i) * primes[j] <= maxn; j++){
			mind[i * primes[j]] = primes[j];
		}
	}
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		int cur;
		scanf("%d", &cur);
		a[i] = cur;
		while(cur > 1){
			p1[lower_bound(primes, primes + sz, mind[cur]) - primes]++;
			cur /= mind[cur];
		}
	}
	for(int i = 0; i < m; i++){
		int cur;
		scanf("%d", &cur);
		b[i] = cur;
		while(cur > 1){
			p2[lower_bound(primes, primes + sz, mind[cur]) - primes]++;
			cur /= mind[cur];
		}
	}
	for(int i = 0; i < sz; i++){
		need1[i] = p1[i] - min(p1[i], p2[i]);
		need2[i] = p2[i] - min(p1[i], p2[i]);
	}
	for(int i = 0; i < n; i++){
		int cur = a[i];
		while(cur > 1){
			int pos = lower_bound(primes, primes + sz, mind[cur]) - primes;
			if(p1[pos] > need1[pos]){
				a[i] /= mind[cur];
				p1[pos]--;
			}
			cur /= mind[cur];
		}
	}
	for(int i = 0; i < m; i++){
		int cur = b[i];
		while(cur > 1){
			int pos = lower_bound(primes, primes + sz, mind[cur]) - primes;
			if(p2[pos] > need2[pos]){
				b[i] /= mind[cur];
				p2[pos]--;
			}
			cur /= mind[cur];
		}
	}
	printf("%d %d\n", n, m);
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);	
	}
	printf("\n");
	for(int i = 0; i < m; i++){
		printf("%d ", b[i]);	
	}
	printf("\n");
	return 0;
}