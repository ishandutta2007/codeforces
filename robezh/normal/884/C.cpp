#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

//vector<int> edge[100005];
int u[100005];
int sizeu[100005];
int n;

int init_union(){
	for(int i = 1; i <= n; i++){
		u[i] = i;
		sizeu[i] = 1;
	}
}

int find(int i){
	if(u[i] != i){
		u[i] = find(u[i]);
	}
	return u[i];
}

int unite(int i, int j){
	sizeu[find(u[j])] = sizeu[find(u[i])] + sizeu[find(u[j])] ;
	u[find(u[i])] = find(u[j]);
	
}

bool same(int i, int j){
	return find(i) == find(j);
}


int main(){
	scanf("%d", &n);
	int tmp;
	init_union();
	for(int i = 1; i <= n; i++){
		scanf("%d", &tmp);
		if(!same(i,tmp)) unite(i, tmp);
	}
	vector<int> res;
	for(int i = 1; i <= n; i++){
		if(u[i] == i){
			res.push_back(sizeu[i]);
			//printf("%d ", sizeu[i]);
		}
	}
	sort(res.begin(), res.end());
	//if(n >= 2) res[res.size()-2] += res[res.size()-1];
	long long sum = 0;
	for(int i = 0; i < res.size(); i++){
		sum += (long long)res[i] * res[i];
	}
	if(res.size() >= 2) sum += (long long)res[res.size()-2] * res[res.size()-1] * 2;
	
	cout<<sum;
}