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
#define y1 fjkxl

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
const int N = 3000;
const int M = int(1e5);

// active, left, right, top, bottom
int sum1[N][N], sum2[N][N], sum3[N][N], sum4[N][N], sum5[N][N], col[N][N];
bool used[M + 10];
int x1[M + 10], y1[M + 10], x2[M + 10], y2[M + 10], lst[M + 10];

inline int get_sum1(int x1, int y1, int x2, int y2){
	int res = sum1[x2][y2];
	if(x1 > 0){
		res -= sum1[x1 - 1][y2];
	}
	if(y1 > 0){
		res -= sum1[x2][y1 - 1];
	}
	if(x1 > 0 && y1 > 0){
		res += sum1[x1 - 1][y1 - 1];
	}
	return res;
}

inline int get_sum2(int p, int l, int r){
	return sum2[p][r] - (l > 0 ? sum2[p][l - 1] : 0);
}

inline int get_sum3(int p, int l, int r){
	return sum3[p][r] - (l > 0 ? sum3[p][l - 1] : 0);
}

inline int get_sum4(int p, int l, int r){
	return sum4[p][r] - (l > 0 ? sum4[p][l - 1] : 0);
}

inline int get_sum5(int p, int l, int r){
	return sum5[p][r] - (l > 0 ? sum5[p][l - 1] : 0);
}

inline bool check(int x1, int y1, int x2, int y2){
	if(get_sum3(y2, x1, x2) != x2 - x1 + 1){
		return false;
	}
	if(get_sum5(x2, y1, y2) != y2 - y1 + 1){
		return false;
	}
	return true;
}

inline void gen(){
	srand(time(NULL));
	freopen("input.txt", "w", stdout);
	int n = int(1e5);
	cout << n << endl;
	for(int i = 0; i < n; i++){
		int x = rand() % N, y = rand() % (N - 1);
		while(col[x][y] == 1 || col[x][y + 1] == 1){
			x = rand() % N;
			y = rand() % N;
		}
		col[x][y] = col[x][y + 1] = 1;
		cout << x << " " << y << " " << x + 1 << " " << y + 2 << endl;
	}
	exit(0);
}

int main(){
	//gen();
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//cerr << "mem = " << (sizeof(col) + sizeof(sum1) + sizeof(sum2) + sizeof(sum3) + sizeof(sum4) + sizeof(sum5)) / 1024 / 1024 << endl;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
		x2[i]--;
		y2[i]--;
		for(int j = x1[i]; j <= x2[i]; j++){
			for(int z = y1[i]; z <= y2[i]; z++){
				sum1[j][z] = 1;
				col[j][z] = i;
			}
		}
		for(int j = x1[i]; j <= x2[i]; j++){
			sum2[y1[i]][j] = sum3[y2[i]][j] = 1;
		}
		for(int j = y1[i]; j <= y2[i]; j++){
			sum4[x1[i]][j] = sum5[x2[i]][j] = 1;
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(i > 0){
				sum1[i][j] += sum1[i - 1][j];
			}
			if(j > 0){
				sum1[i][j] += sum1[i][j - 1];
				sum2[i][j] += sum2[i][j - 1];
				sum3[i][j] += sum3[i][j - 1];
				sum4[i][j] += sum4[i][j - 1];
				sum5[i][j] += sum5[i][j - 1];
			}
			if(i > 0 && j > 0){
				sum1[i][j] -= sum1[i - 1][j - 1];
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = max(x2[i] - x1[i], y2[i] - y1[i]); x1[i] + j < N && y1[i] + j < N; j++){
			if(get_sum1(x1[i], y1[i], x1[i] + j, y1[i] + j) != (j + 1) * (j + 1)){
				break;
			}
			if(get_sum4(x1[i], y1[i], y1[i] + j) != j + 1){
				break;
			}
			if(get_sum2(y1[i], x1[i], x1[i] + j) != j + 1){
				break;
			}
			if(check(x1[i], y1[i], x1[i] + j, y1[i] + j)){
				int sz = 0;
				for(int z = x1[i]; z <= x1[i] + j; z++){
					for(int h = y1[i]; h <= y1[i] + j; h++){
						if(!used[col[z][h]]){
							used[col[z][h]] = true;
							lst[sz++] = col[z][h];
						}
					}
				}
				printf("YES %d\n", sz);
				for(int z = 0; z < sz; z++){
					printf("%d ", lst[z] + 1);
				}
				puts("");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}