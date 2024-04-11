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

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const double eps = 1e-9;
const double pi = acos(double(-1));
const int inf = int(1e9);

int main(){
#ifdef HOME
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("diplomacy.in", "r", stdin);
	//freopen("diplomacy.out", "w", stdout);
#endif
	int n, m, s;
	scanf("%d %d %d", &n, &m, &s);
	ll ans = 0;
	for(int i = 0; 2 * i + 1 <= n; i++){
		for(int j = 0; 2 * j + 1 <= m; j++){
			if((2 * i + 1) * (2 * j + 1) == s){
				for(int z = 0; z <= i; z++){
					for(int h = 0; h <= j; h++){
						ans += ll(n - 2 * i) * (m - 2 * j);
					}
				}
			}
		}
	}
	for(int i = 0; 2 * i + 1 <= n; i++){
		for(int j = 0; 2 * j + 1 <= m; j++){
			if((2 * i + 1) * (2 * j + 1) == s){
				for(int z = 0; z < i; z++){
					for(int h = 0; h < j; h++){
						ans += ll(n - 2 * i) * (m - 2 * j);
					}
				}
			}
		}
	}
	for(int i = 0; 2 * i + 1 <= n; i++){
		for(int j = 0; 2 * j + 1 <= m; j++){
			for(int z = i; 2 * z + 1 <= n; z++){
				int a = 2 * i + 1, b = 2 * j + 1, c = 2 * z + 1;
				if(a == c){
					if(a * b == s){
						ans += ll(n - c + 1) * (m - b + 1) * j;
					}
				}
				else{
					if(a * b <= s && (s - a * b) % (c - a) == 0){
						int d = (s - a * b)  / (c - a);
						if(d % 2 != 0 && b > d){
							ans += ll(n - c + 1) * (m - b + 1);
						}
					}
				}
			}
		}
	}
	for(int i = 0; 2 * i + 1 <= n; i++){
		for(int j = 0; 2 * j + 1 <= m; j++){
			for(int z = j; 2 * z + 1 <= m; z++){
				int a = 2 * i + 1, b = 2 * j + 1, d = 2 * z + 1;
				if(b == d){
					if(a * b == s){
						ans += ll(n - a + 1) * (m - d + 1) * i;
					}
				}
				else{
					if(a * b <= s && (s - a * b) % (d - b) == 0){
						int c = (s - a * b) / (d - b);
						if(c % 2 != 0 && a > c){
							ans += ll(n - a + 1) * (m - d + 1);
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
#ifdef HOME
	printf("time = %.18lf\n", (clock() - start) / CLOCKS_PER_SEC);
#endif
	return 0;
}