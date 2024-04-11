#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <queue>
#include <cassert>

using namespace std;

//#define HOME
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define next _next
#define rank _rank
#define prev _prev
#define sz(s) int((s).size())

typedef unsigned long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const double eps = 1e-9;
const double pi = acos(double(-1));
const ll inf = ll(1e19);

int main(){
#ifdef HOME
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("conference.in", "r", stdin);
	//freopen("conference.out", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	ll ans = 0;
	for(int i = 0; i < n; i++){
		int t, T, x, cost;
		scanf("%d %d %d %d", &t, &T, &x, &cost);
		if(t < T){
			int cnt = m / (T - t);
			ll res = inf;
			for(int j = 0; j <= min(cnt, 10); j++){
				if(m - (T - t) * j > T - t){
					res = min(res, ll(j + 1) * cost + ll(m - j * (T - t)) * x);
				}
				else{
					res = min(res, ll(j + 1) * cost);
				}
			}
			for(int j = cnt; j >= max(cnt - 10, 0); j--){
				if(m - (T - t) * j > T - t){
					res = min(res, ll(j + 1) * cost + ll(m - j * (T - t)) * x);
				}
				else{
					res = min(res, ll(j + 1) * cost);
				}
			}
			ans += res;
		}
		else{
			ans += cost + ll(x) * m;
		}
	}
	cout << ans << endl;
#ifdef HOME
	printf("time = %.18lf\n", (clock() - start) / CLOCKS_PER_SEC);
#endif
	return 0;
}