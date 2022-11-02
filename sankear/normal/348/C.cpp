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
#define len(s) int((s).size())
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
typedef long long int64;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned long long lint;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = int(1e5);
const int MAGIC = 333;

ll a[N + 10], ans[N + 10];
vi lst[N + 10];
int link[N + 10], s[N + 10];
ll add[N + 10];
bool used[N + 10];
int inter[N][N / MAGIC];

inline void gen(){
	freopen("input.txt", "w", stdout);
	int n = int(1e5), m = 2, q = int(1e5);
	cout << n << " " << m << " " << q << endl;
	for(int i = 0; i < n; i++){
		cout << rand() % int(1e8) << " ";
	}
	cout << endl;
	for(int i = 0; i < m; i++){
		int sz = 1 + rand() % 50000;
		cout << sz;
		for(int j = 0; j < sz; j++){
			cout << " " << 1 + rand() % n;
		}
		cout << endl;
	}
	for(int i = 0; i < q; i++){
		if(rand() % 2 == 0 && false){
			cout << "? " << 1 + rand() % m << endl;
		}
		else{
			cout << "+ " << 1 + rand() % m << " " << rand() % int(1e4) << endl;
		}
	}
	exit(0);
}

int main(){
	//gen();
	cerr << "mem = " << sizeof(inter) / 1024 / 1024 << endl;
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 0; i < n; i++){
		scanf(LLD, &a[i]);
	}
	for(int i = 0; i < m; i++){
		int sz;
		scanf("%d", &sz);
		lst[i].resize(sz);
		for(int j = 0; j < sz; j++){
			scanf("%d", &lst[i][j]);
			lst[i][j]--;
		}
		if(sz >= MAGIC){
			ans[i] = 0;
			for(int j = 0; j < sz; j++){
				ans[i] += a[lst[i][j]];
			}
		}
	}
	int ptr = 0;
	for(int i = 0; i < m; i++){
		if(sz(lst[i]) >= MAGIC){
			s[ptr] = i;
			link[i] = ptr;
			for(int j = 0; j < sz(lst[i]); j++){
				used[lst[i][j]] = true;
			}
			for(int j = 0; j < m; j++){
				int res = 0;
				for(int z = 0; z < sz(lst[j]); z++){
					if(used[lst[j][z]]){
						res++;
					}
				}
				inter[j][ptr] = res;
			}
			ptr++;
			for(int j = 0; j < sz(lst[i]); j++){
				used[lst[i][j]] = false;
			}
		}
	}
	int sz = 0;
	for(int i = 0; i < q; i++){
		char ch;
		scanf(" %c", &ch);
		if(ch == '?'){
			int num;
			scanf("%d", &num);
			num--;
			ll sum = 0;
			if(sz(lst[num]) < MAGIC){
				for(int j = 0; j < sz(lst[num]); j++){
					sum += a[lst[num][j]];
				}
				for(int j = 0; j < ptr; j++){
					sum += ll(inter[num][j]) * add[j];
				}
			}
			else{
				sum += ans[num];
				for(int j = 0; j < ptr; j++){
					sum += ll(inter[num][j]) * add[j];
				}
			}
			printf(LLD"\n", sum);
			continue;
		}
		int num, ADD;
		scanf("%d %d", &num, &ADD);
		num--;
		if(sz(lst[num]) < MAGIC){
			for(int j = 0; j < sz(lst[num]); j++){
				a[lst[num][j]] += ADD;
			}
			for(int j = 0; j < ptr; j++){
				ans[s[j]] += ll(inter[num][j]) * ADD;
			}
			continue;
		}
		add[link[num]] += ADD;
	}
	return 0;
}