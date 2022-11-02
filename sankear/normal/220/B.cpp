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
#include <complex>
#include <queue>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define next _next
#define prev _prev
#define rank _rank
#define sz(s) int((s).size())
#define fs first
#define sc second

typedef long long ll;
typedef unsigned long long ull;
typedef complex <double> tc;
typedef pair <int, int> pii;
typedef vector <int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int MAXA = 320;

int a[100100], b[100100], val[100100], sz[100100];
int s[650][100010];

inline int get(int *s, int l, int r){
	return s[r] - (l > 0 ? s[l - 1] : 0);
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//cout << (sizeof(a) + sizeof(val) + sizeof(sz) + sizeof(s)) / 1024 / 1024 << endl;
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b, b + n);
	int k = unique(b, b + n) - b;
	for(int i = 0; i < n; i++){
		sz[lower_bound(b, b + k, a[i]) - b]++;
	}
	int cnt = 0;
	for(int i = 0; i < k; i++){
		if(b[i] <= MAXA){
			for(int j = 0; j < n; j++){
				s[cnt][j] = (j > 0 ? s[cnt][j - 1] : 0) + (a[j] == b[i]);
			}
			val[cnt++] = b[i];
		}
		else{
			if(sz[i] < b[i]){
				continue;
			}
			for(int j = 0; j < n; j++){
				s[cnt][j] = (j > 0 ? s[cnt][j - 1] : 0) + (a[j] == b[i]);
			}
			val[cnt++] = b[i];
		}
	}
	for(int i = 0; i < m; i++){
		int l, r;
		scanf("%d %d", &l, &r);
		l--;
		r--;
		int ans = 0;
		for(int j = 0; j < cnt; j++){
			if(get(s[j], l, r) == val[j]){
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}