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
const int N = 100;

char pos[N + 10][10];
bool used[2 * N + 10];
queue <int> q;
int str[N + 10], str2[N + 10], d[2 * N + 10], p[2 * N + 10];
int c[2 * N + 10][2 * N + 10], w[2 * N + 10][2 * N + 10], f[2 * N + 10][2 * N + 10];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%s %d", pos[i], &str[i]);
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &str2[i]);
	}
	int s = n + m, t = s + 1;
	for(int i = 0; i < m; i++){
		c[s][i] = 1;
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(strcmp(pos[j], "ATK") == 0){
				if(str2[i] >= str[j]){
					c[i][j + m] = 1;
					w[i][j + m] = str[j] - str2[i];
					w[j + m][i] = str2[i] - str[j];
				}
			}
			else{
				if(str2[i] > str[j]){
					c[i][j + m] = 1;
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		c[i + m][t] = 1;
	}
	int ans = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j <= t; j++){
			d[j] = inf;
			used[j] = false;
		}
		d[s] = 0;
		used[s] = true;
		q.push(s);
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			used[cur] = false;
			for(int j = 0; j <= t; j++){
				if(c[cur][j] - f[cur][j] > 0 && d[j] > d[cur] + w[cur][j]){
					d[j] = d[cur] + w[cur][j];
					p[j] = cur;
					if(!used[j]){
						used[j] = true;
						q.push(j);
					}
				}
			}
		}
		if(d[t] == inf){
			break;
		}
		for(int j = t; j != s; j = p[j]){
			f[p[j]][j]++;
			f[j][p[j]]--;
		}
		int res = 0;
		for(int j = 0; j < m; j++){
			for(int z = 0; z < n; z++){
				res -= f[j][z + m] * w[j][z + m];
			}
		}
		ans = max(ans, res);
	}
	int sumX = 0, sumY = 0;
	for(int i = 0; i < m; i++){
		sumX += str2[i];
	}
	for(int i = 0; i < n; i++){
		if(strcmp(pos[i], "ATK") == 0){
			sumY += str[i];
		}
	}
	for(int i = 0; i <= t; i++){
		for(int j = 0; j <= t; j++){
			c[i][j] = f[i][j] = w[i][j] = 0;
		}
	}
	for(int i = 0; i < m; i++){
		c[s][i] = 1;
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(strcmp(pos[j], "ATK") == 0){
				if(str2[i] >= str[j]){
					c[i][j + m] = 1;
				}
			}
			else{
				if(str2[i] > str[j]){
					c[i][j + m] = 1;
					w[i][j + m] = str2[i];
					w[j + m][i] = -str2[i];
				}
			}
		}
	}
	for(int i = 0; i < n; i++){
		c[i + m][t] = 1;
	}
	int flow = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= t; j++){
			d[j] = inf;
			used[j] = false;
		}
		d[s] = 0;
		used[s] = true;
		q.push(s);
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			used[cur] = false;
			for(int j = 0; j <= t; j++){
				if(c[cur][j] - f[cur][j] > 0 && d[j] > d[cur] + w[cur][j]){
					d[j] = d[cur] + w[cur][j];
					p[j] = cur;
					if(!used[j]){
						used[j] = true;
						q.push(j);
					}
				}
			}
		}
		if(d[t] == inf){
			break;
		}
		flow++;
		for(int j = t; j != s; j = p[j]){
			f[p[j]][j]++;
			f[j][p[j]]--;
		}
	}
	int res = 0;
	for(int j = 0; j < m; j++){
		for(int z = 0; z < n; z++){
			res -= f[j][z + m] * w[j][z + m];
		}
	}
	if(flow == n){
		ans = max(ans, sumX - sumY + res);
	}
	printf("%d\n", ans);
	return 0;
}