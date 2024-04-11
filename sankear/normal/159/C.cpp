#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

struct td{
	int num, sz, h, l, r;
};

int cv[30];
td d[200200];
char t[2020];
char ans[200200], s[200200];

inline void calc(int v){
	d[v].sz = d[d[v].l].sz + d[d[v].r].sz + 1;
}

void split(int v, int k, int &l, int &r){
	if(v == 0){
		l = r = 0;
		return;
	}
	if(d[d[v].l].sz + 1 <= k){
		split(d[v].r, k - d[d[v].l].sz - 1, d[v].r, r);
		l = v;
	}
	else{
		split(d[v].l, k, l, d[v].l);
		r = v;
	}
	calc(v);
}

int merge(int l, int r){
	if(l == 0){
		return r;
	}
	if(r == 0){
		return l;
	}
	int res;
	if(d[l].h > d[r].h){
		d[l].r = merge(d[l].r, r);
		res = l;
	}
	else{
		d[r].l = merge(l, d[r].l);
		res = r;
	}
	calc(res);
	return res;
}

void dfs(int v, char ch){
	if(v == 0){
		return;
	}
	ans[d[v].num] = ch;
	dfs(d[v].l, ch);
	dfs(d[v].r, ch);
}

int main(){
	srand(time(NULL));
    //freopen("cantor.in", "r", stdin);
    //freopen("cantor.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	scanf("%d %s", &k, t);
	int n = 0, len = strlen(t);
	for(int i = 0; i < k; i++){
		for(int j = 0; j < len; j++){
			s[n++] = t[j];
		}
	}
	int sz = 0;
	for(int i = 0; i < n; i++){
		d[++sz].num = i;
		d[sz].sz = 1;
		d[sz].h = rand();
		cv[s[i] - 'a'] = merge(cv[s[i] - 'a'], sz);
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int num;
		char ch;
		scanf("%d %c", &num, &ch);
		int need = ch - 'a';
		int p1, p2, p3;
		split(cv[need], num, p1, p3);
		split(p1, num - 1, p1, p2);
		cv[need] = merge(p1, p3);
	}
	for(int i = 0; i < 26; i++){
		dfs(cv[i], 'a' + i);
	}
	for(int i = 0; i < n; i++){
		if(ans[i] > 0){
			printf("%c", ans[i]);
		}
	}
	printf("\n");
	return 0;
}