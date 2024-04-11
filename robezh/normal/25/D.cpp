#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

typedef pair<int, int> P;

vector<P> red;
vector<P> con;
int u[1005];

int find(int i){
	return u[i] == i ? i : u[i] = find(u[i]);
}

void unite(int i, int j){
	u[find(i)] = find(u[j]);
}

bool same(int i, int j){
	return find(i) == find(j);
}

int main(){
	int n;
	scanf("%d", &n);
	int a,b;
	for(int i = 1; i <= n; i++) u[i] = i;
	for(int i = 1; i <= n-1; i++){
		scanf("%d%d", &a, &b);
		if(!same(a,b)) unite(a,b);
		else{
			red.push_back(P(a,b));
		}
	}
	int pivot = 0;
	for(int i = 1; i <= n; i++){
		if(u[i] == i){
			pivot = i;
			break;
		}
	}
	for(int i = 1; i <= n; i++){
		if(u[i] == i && i != pivot){
			con.push_back(P(i, pivot));
		}
	}
	printf("%d\n", con.size());
	for(int i = 0; i < con.size(); i++){
		P p1 = red[i], p2 = con[i];
		printf("%d %d %d %d\n", p1.first, p1.second, p2.first, p2.second);
	}
}