#include <bits/stdc++.h>
using namespace std;

#define N 11001
typedef long long LL;

int L[N], R[N], val[N], type[N], gas[N], n, m;
LL a[N];
vector <int> id[N];

const LL INF = 1e9;


int main() {
///	freopen("in.txt", "r", stdin);

	scanf("%d %d", &n, &m);

	for(int i = 0; i <= n; i ++) a[i] = INF;

	for(int step = 1; step <= m; step ++) {
		scanf("%d %d %d %d", type + step, L + step, R + step, val + step);
	}

	for(int step = m; step >= 1; step --) {
		if(type[step] == 2){
			for(int i = L[step]; i <= R[step]; i ++) {
				if(a[i] > (LL)val[step]){
					for(auto y : id[i]) gas[y] --;
					id[i].clear();
					id[i].push_back(step);
					gas[step] ++;
					a[i] = val[step];
				}
				else if(a[i] == (LL)val[step]){
					gas[step] ++;
					id[i].push_back(step);
				}
			}
		}
		else{
			for(int i = L[step]; i <= R[step]; i ++) {
				a[i] -= val[step];
			}
		}
	}

	for(int i = 1; i <= n; i ++) {
		if(a[i] < -INF){ puts("NO"); return 0; }
		if(a[i] > 3 * INF) { puts("NO"); return 0; }
		else if(a[i] > INF){
			a[i] = INF;
			for(auto y : id[i]) gas[y] --;
		}
	}

	for(int step = 1; step <= m; step ++) {
		if(type[step] == 2){
			if( gas[step] == 0){ puts("NO"); return 0; }
		}
	}

	puts("YES");
	for(int i = 1; i <= n; i ++) printf("%d ", a[i]); puts("");
}