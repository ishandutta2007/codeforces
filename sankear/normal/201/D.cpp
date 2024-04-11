#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
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
#define link _link
#define hash _hash
#ifdef LOCAL
#define LLD "%I64d"
#else
#define LLD "%I64d"
#endif
 
typedef int ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;
 
const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const ll P = 203;

char buf[100];
int k[20];
ll hh[20];
int link[20], last[20];
ll wh[11][500500];
pair <ll, int> w[500500];
int d[33000][110];
int cnt[33000][20];

int main(){
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", buf);
		int len = strlen(buf);
		hh[i] = 0;
		for(int j = 0; j < len; j++){
			hh[i] = hh[i] * P + buf[j];
		}
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &k[i]);
		for(int j = 0; j < k[i]; j++){
			scanf("%s", buf);
			int len = strlen(buf);
			wh[i][j] = 0;
			for(int z = 0; z < len; z++){
				wh[i][j] = wh[i][j] * P + buf[z];
			}
		}
	}
	int all = (1 << n);
	for(int i = 0; i < all; i++){
		for(int j = 0; j < n; j++){
			for(int z = j + 1; z < n; z++){
				if((i & (1 << z)) != 0){
					cnt[i][j]++;
				}
			}
		}
	}
	int ans = -inf, num;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < k[i]; j++){
			w[j] = mp(wh[i][j], j);
		}
		sort(w, w + k[i]);
		bool fl = true;
		for(int j = 0; j < n; j++){
			int pos = lower_bound(w, w + k[i], mp(hh[j], -inf)) - w;
			if(pos == k[i]){
				fl = false;
				break;
			}
			if(!(w[pos].fs == hh[j])){
				fl = false;
				break;
			}
			link[j] = pos;
			last[j] = upper_bound(w, w + k[i], mp(hh[j], inf)) - w - 1;
		}
		if(!fl){
			continue;
		}
		for(int j = 0; j < all; j++){
			for(int z = 0; z <= n * (n - 1) / 2; z++){
				d[j][z] = inf;
			}
		}
		d[0][0] = 0;
		for(int j = 0; j < all; j++){
			for(int z = 0; z <= n * (n - 1) / 2; z++){
				if(d[j][z] == inf){
					continue;
				}
				for(int h = 0; h < n; h++){
					if((j & (1 << h)) != 0 || w[last[h]].sc < d[j][z]){
						continue;
					}
					int nj = (j | (1 << h));
					int nz = z + cnt[j][h];
					int res = lower_bound(w + link[h], w + last[h] + 1, mp(hh[h], d[j][z])) - w;
					if(res == last[h] + 1 || !(w[res].fs == hh[h])){
						continue;
					}
					d[nj][nz] = min(d[nj][nz], w[res].sc + 1);
				}
			}
		}
		for(int j = 0; j <= n * (n - 1) / 2; j++){
			if(d[all - 1][j] != inf){
				if(n * (n - 1) / 2 - j + 1 > ans){
					ans = n * (n - 1) / 2 - j + 1;
					num = i;
				}
			}
		}
	}
	if(ans == -inf){
		printf("Brand new problem!\n");
		return 0;
	}
	printf("%d\n[:", num + 1);
	for(int i = 0; i < ans; i++){
		printf("|");
	}
	printf(":]\n");
	return 0;
}