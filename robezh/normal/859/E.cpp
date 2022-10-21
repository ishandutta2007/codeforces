#include<iostream>
#include<cstdio>
using namespace std;

const int mod = 1000000007;

int u[200050];
int edgenum[200050];
int vernum[200050];
bool selfcycle[200050];

int find(int k){
	if(u[k] != k){
		u[k] = find(u[k]);
	}
	return u[k];
}

void unite(int a, int b){
	int edge = 1 + edgenum[find(a)] + edgenum[find(b)];
	int ver = vernum[find(a)] + vernum[find(b)];
	bool cycle = selfcycle[find(a)] || selfcycle[find(b)];
	int oria = find(a), orib = find(b);
	u[find(a)] = find(b);
	edgenum[oria] = 0;
	edgenum[orib] = edge;
	vernum[oria] = 0;
	vernum[orib] = ver;
	selfcycle[orib] = cycle;
}

void deal(int a, int b){
	if(a == b){
		selfcycle[find(a)] = true;
	}
	else if(find(a) == find(b)){
		edgenum[find(a)] ++;
	}
	else{
		unite(a,b);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	fill(edgenum+1, edgenum+1+2*n, 0);
	fill(vernum+1, vernum+1+2*n, 1);
	fill(selfcycle+1, selfcycle+1+2*n, false);
	for(int i = 1; i <= 2*n; i++ ){
		u[i] = i;
	}
	int a,b;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &a, &b);
		deal(a,b);
	}
	long long total = 1;
	for(int i = 1; i <= 2*n; i++){
		if(find(i) == i){
			if(selfcycle[i]){
			}
			else if(vernum[i] == edgenum[i]){
				total *= 2;
				total %= mod;
			}
			else{
				total *= vernum[i];
				total %= mod;
			}
		}
	}
	cout<<total;
}