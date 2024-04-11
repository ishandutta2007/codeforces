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

int c[60];
int a[60][60];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("operators.in", "r", stdin);
	//freopen("operators.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < c[i]; j++){
			scanf("%d", &a[i][j]);
		}
	}
	int cur = 1;
	vector <pair <pii, pii> > ans;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < c[i]; j++){
			if(a[i][j] != cur){
				bool fl = false;
				for(int z = i; z < n && !fl; z++){
					for(int h = 0; h < c[z]; h++){
						if(a[z][h] == cur){
							swap(a[i][j], a[z][h]);
							ans.pb(mp(mp(i, j), mp(z, h)));
							fl = true;
							break;
						}
					}
				}
			}
			cur++;
		}
	}
	printf("%d\n", sz(ans));
	for(int i = 0; i < sz(ans); i++){
		printf("%d %d %d %d\n", ans[i].fs.fs + 1, ans[i].fs.sc + 1, ans[i].sc.fs + 1, ans[i].sc.sc + 1);
	}
	return 0;
}