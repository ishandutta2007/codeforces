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

struct tp{
	int go, f, c, rev;
};

int sz, k;
char cur[12];
int len[210];
char s[210][12];
char *lst[100000];
bool used[400000];
int pv[400000], pr[400000], next[400000], first[400000], queue[400000];
tp p[400000];

void gen(int x, int y, int z){
	if(z > 0){
		lst[sz] = (char*)malloc(sizeof(char) * (z + 1));
		for(int j = 0; j < z; j++){
			lst[sz][j] = cur[j];
		}
		lst[sz++][z] = '\0';
	}
	if(y >= len[x] || z >= 4){
		return;
	}
	for(int i = y; i < len[x]; i++){
		cur[z] = s[x][i];
		gen(x, i + 1, z + 1);
	}
}

bool cmp(char *a, char *b){
	return strcmp(a, b) < 0;
}

bool qq(char *a, char *b){
	return strcmp(a, b) == 0;
}

inline void add(int a, int b){
	p[++k].go = b;
	p[k].c = 1;
	p[k].rev = k + 1;
	next[k] = first[a];
	first[a] = k;
	p[++k].go = a;
	p[k].rev = k - 1;
	next[k] = first[b];
	first[b] = k;
}

inline bool check(int a, int b){
	int cur = 0;
	for(int i = 0; i < len[a]; i++){
		if(s[a][i] == lst[b][cur]){
			cur++;
			if(lst[b][cur] == '\0'){
				return true;
			}
		}
	}
	return false;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  int n;
	scanf("%d\n", &n);
	sz = 0;
	for(int i = 0; i < n; i++){
		scanf("%s\n", s[i]);
		len[i] = strlen(s[i]);
		gen(i, 0, 0);
	}
	sort(lst, lst + sz, cmp);
	sz = unique(lst, lst + sz, qq) - lst;
	k = 0;
	int s = n + sz;
	int t = s + 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < sz; j++){
			if(check(i, j)){
				add(i, j + n);
			}
		}
	}
	for(int i = 0; i < n; i++){
		add(s, i);
	}
	for(int i = 0; i < sz; i++){
		add(i + n, t);
	}
	int flow = 0;
	while(true){
		for(int i = 0; i <= t; i++){
			used[i] = false;
		}
		used[s] = true;
		int l = 0;
		int r = 1;
		queue[0] = s;
		while(l < r && !used[t]){
			int cur = queue[l++];
			for(int i = first[cur]; i > 0; i = next[i]){
				if(p[i].c - p[i].f > 0 && !used[p[i].go]){
					used[p[i].go] = true;
					pv[p[i].go] = cur;
					pr[p[i].go] = i;
					queue[r++] = p[i].go;
					if(p[i].go == t){
						break;
					}
				}
			}
		}
		if(!used[t]){
			break;
		}
		flow++;
		int i = t;
		while(i != s){
			p[pr[i]].f++;
			p[p[pr[i]].rev].f--;
			i = pv[i];
		}
	}
	if(flow != n){
		printf("-1\n");
		return 0;
	}
	for(int i = 0; i < n; i++){
		for(int j = first[i]; j > 0; j = next[j]){
			if(p[j].go >= n && p[j].go < n + sz && p[j].f > 0){
				printf("%s\n", lst[p[j].go - n]);
				break;
			}
		}
	}
	return 0;
}