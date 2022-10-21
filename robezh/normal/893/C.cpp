#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int u[100005];
int n,m;
int mon[100005];
int e[100005];

int find(int i){
	return u[i] == i ? i : u[i] = find(u[i]);
}

int same(int i, int j){
	return find(i) == find(j);
}

void unite(int i, int j){
	int fi = find(i), fj = find(j);
	u[fi] = fj;
	e[fj] = min(e[fi], e[fj]);
	e[fi] = 0;
}


int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) u[i] = i;
	for(int i = 1; i <= n; i++) scanf("%d", &mon[i]), e[i] = mon[i];
	int a, b;	
	for(int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		if(!same(a,b)){
			unite(a, b);
		}
	}
	long long res = 0;
	for(int i = 1; i <= n; i++) res += e[i];
	cout << res; 
}