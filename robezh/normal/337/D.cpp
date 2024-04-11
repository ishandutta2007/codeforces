#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int n,m,d;
vector<int> G[100005];
bool aff[100005];
int ind,a,b;
bool used[100005];
int down[100005], up[100005];

void setdown(int x){
	used[x] = true;
	down[x] = -1;
	for(int i = 0; i < G[x].size(); i++){
		if(!used[G[x][i]]){
			int child = G[x][i];
			setdown(child);
			if(down[child] != -1) down[x] = max(down[child] + 1, down[x]);
		}
	}
	if(aff[x]) down[x] = max(down[x], 0);
}

void setup(int x, int par){
	used[x] = true;
	if(par == -1){
		up[x] = -1;
		if(aff[x]) up[x] = 0;
	}
	
	int max1 = -1, max2 = -1;
	for(int i = 0; i < G[x].size(); i++){
		int child = G[x][i];
		if(!used[child]){
			if(down[child] >= max1){
				max2 = max1, max1 = down[child];
			}
			else if(down[child] > max2){
				max2 = down[child];
			}
		}
	}
	for(int i = 0; i < G[x].size(); i++){
		int child = G[x][i];
		if(!used[child]){
			
			if(up[x] == -1) up[child] = -1;
			else up[child] = 1 + up[x];
			
			if(aff[child]) up[child] = max(up[child], 0);
			
			if(down[child] == max1){
				if(max2 != -1) up[child] = max(up[child], max2 + 2);
			}
			else{
				if(max1 != -1) up[child] = max(up[child], max1 + 2);
			}
			setup(child, x);
		}
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &d);
	fill(aff, aff+n+1, false);
	
	for(int i = 0; i < m; i++){
		scanf("%d", &ind);
		aff[ind] = true;
	}
	for(int i = 0; i < n-1; i++){
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	fill(used+1, used+1+n, false);
	setdown(1);
	//for(int i = 1; i <= n; i++) printf("%d ", down[i]);
	//printf("\n");
	fill(used+1, used+1+n, false);
	setup(1, -1);
	//for(int i = 1; i <= n; i++) printf("%d ", up[i]);
	
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(up[i] <= d && down[i] <= d) cnt ++;
	}
	cout << cnt;
}