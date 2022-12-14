#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;
#define MAX_N 250000

int N, K, M;
vector<int> gp[MAX_N+1];
int p[MAX_N+1], lv[MAX_N+1];
bool vst[MAX_N+1];
bool tf = false;
int sz = 0; 
vector<int> ans[MAX_N+1];


void dfs(int x){
	vst[x] = true;
	bool leaf = true;
	for(int i=0; i<gp[x].size(); i++){
		if(!vst[gp[x][i]]){
			p[gp[x][i]] = x;
			lv[gp[x][i]] = lv[x]+1;
			leaf = false;
			dfs(gp[x][i]);
			if(tf){
				return;
			}
		}
	}
	if(leaf){
		if(lv[x]>=(N/K)){
			tf = true;
			int now = x;
			printf("PATH\n%d\n", lv[x]);
			while(1){
				printf("%d ", now);
				if(now==1)	break;
				now = p[now];
			}
			tf = true;
			return;
		}
		int k1=0, k2=0;
		for(int i=0; i<gp[x].size(); i++){
			if(gp[x][i]!=p[x]){
				if(k1==0)	k1 = gp[x][i];
				else k2 = gp[x][i];
			}
		}
		if(lv[k1]>lv[k2]){
			int tmp = k1; k1 = k2; k2 = tmp;
		}
		if((lv[x]-lv[k2]+1)%3!=0){
			int now = x;
			while(1){
				ans[sz].push_back(now);
				if(now==k2)	break;
				now = p[now];
			}
			sz++;
		}
		else if((lv[x]-lv[k1]+1)%3!=0){
			int now = x;
			while(1){
				ans[sz].push_back(now);
				if(now==k1)	break;
				now = p[now];
			}
			sz++;
		}else{
			ans[sz].push_back(x);
			int now = k2;
			while(1){
				ans[sz].push_back(now);
				if(now==k1)	break;
				now = p[now];
			}
			sz++;
		}
	}
}

int main(){
	scanf("%d%d%d", &N, &M, &K);
	for(int i=0; i<M; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		gp[a].push_back(b);	gp[b].push_back(a);
	}
	lv[1] = 1;
	dfs(1);
	if(tf)	return 0;
	printf("CYCLES\n");
	for(int i=0; i<K; i++){
		printf("%d\n", ans[i].size());
		for(int j=0; j<ans[i].size(); j++){
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}