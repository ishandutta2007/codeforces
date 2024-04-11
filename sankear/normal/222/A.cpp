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

int a[200200], cnt[100100];

int main(){
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("painting.in", "r", stdin);
    //freopen("painting.out", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	k--;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);	
	}
	for(int i = 0; i < n; i++){
		a[n + i] = a[k + i];
	}
	int sz = 0;
	for(int i = 0; i < n; i++){
		cnt[a[i]]++;
		if(cnt[a[i]] == 1){
			sz++;
		}
	}
	for(int i = 0; i < n; i++){
		if(sz == 1){
			printf("%d\n", i);
			return 0;
		}
		cnt[a[i]]--;
		if(cnt[a[i]] == 0){
			sz--;	
		}
		cnt[a[i + n]]++;
		if(cnt[a[i + n]] == 1){
			sz++;	
		}
	}
	printf("-1\n");
	return 0;
}