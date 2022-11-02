#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <double> tc;

const int inf = 10000;

int c[600][600], f[600][600], w[600][600];
bool used[600];
int a[600], b[600], d[600], p[600], pd[600], numin[600], numout[600], num[600], col[600];
char a1[600];
int a2[600], tp[600];

inline int calc(int a){
	int res = 0;
	while(a > 0){
		res += (a % 2);
		a /= 2;
	}
	return res;
}

inline void add(int a, int b, int cc, int ww){
	c[a][b] = cc;
	w[a][b] = ww;
	w[b][a] = -ww;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		b[i] = calc(a[i]);
	}
	int sz = 0;
	for(int i = 0; i < m; i++){
		num[i] = sz++;
	}
	for(int i = 0; i < n; i++){
		numin[i] = sz++;
		numout[i] = sz++;
	}
	int s = sz++;
	int t = sz++;
	int ss = sz++;
	int tt = sz++;
	for(int i = 0; i < m; i++){
		add(s, num[i], 1, 0);
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			add(num[i], numin[j], 1, b[j]);
		}
	}
	for(int i = 0; i < n; i++){
		add(ss, numout[i], 1, 0);
		add(numin[i], tt, 1, 0);
	}
	for(int i = 0; i < n; i++){
		add(numout[i], t, 1, 0);
	}
	add(t, s, inf, 0);
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i] == a[j]){
				add(numout[i], numin[j], 1, 0);
			}
			else{
				add(numout[i], numin[j], 1, b[j]); 
			}
		}
	}
	while(true){
		for(int i = 0; i <= tt; i++){
			d[i] = inf;
			used[i] = false;
			p[i] = -1;
		}
		d[ss] = 0;
		for(int i = 0; i <= tt; i++){
			int v = -1;
			for(int j = 0; j <= tt; j++){
				if(!used[j] && (v == -1 || d[j] < d[v])){
					v = j;
				}
			}
			if(v == -1){
				break;
			}
			used[v] = true;
			for(int j = 0; j <= tt; j++){
				if(c[v][j] - f[v][j] > 0 && d[j] > d[v] + pd[v] + w[v][j] - pd[j]){
					d[j] = d[v] + pd[v] + w[v][j] - pd[j];
					p[j] = v;
				}
			}
		}
		if(d[tt] == inf){
			break;
		}
		for(int i = 0; i <= tt; i++){
			pd[i] += d[i];
		}
		int i = tt;
		while(i != ss){
			f[p[i]][i]++;
			f[i][p[i]]--;
			i = p[i];
		}
	}
	int ans = 0;
	for(int i = 0; i <= tt; i++){
		for(int j = 0; j <= tt; j++){
			ans += f[i][j] * w[i][j];
		}
	}
	ans /= 2;
	sz = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(f[num[i]][numin[j]] > 0){
				int z = j;
				while(true){
					col[z] = i;
					bool fl = false;
					for(int h = z + 1; h < n; h++){
						if(f[numout[z]][numin[h]] > 0){
							z = h;
							fl = true;
							break;
						}
					}
					if(!fl){
						break;
					}
				}
				tp[sz] = 1;
				a1[sz] = 'a' + col[j];
				a2[sz++] = a[j];
			}
		}
	}
	for(int i = 0; i < n; i++){
		tp[sz] = 2;
		a1[sz++] = 'a' + col[i];
		for(int j = i + 1; j < n; j++){
			if(f[numout[i]][numin[j]] > 0){
				if(a[i] != a[j]){
					tp[sz] = 1;
					a1[sz] = 'a' + col[i];
					a2[sz++] = a[j];
				}
			}
		}
	}
	printf("%d %d\n", sz, ans);
	for(int i = 0; i < sz; i++){
		if(tp[i] == 1){
			printf("%c=%d\n", a1[i], a2[i]);
		}
		else{
			printf("print(%c)\n", a1[i]);
		}
	}
	return 0;
}