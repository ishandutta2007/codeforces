#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,a[N],fat[N];
vector<int> g[N];
vector<int> v;
vector<int> nodes[N];

int id(int x){
	return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;
}

int L[N],R[N],C;
void dfs(int u,int p){
	L[u]=++C; fat[u]=p;
	for(auto v: g[u]){
		if(v==p) continue;
		dfs(v,u);
	}
	R[u]=C;
}

bool cmp(int x,int y){
	return L[x] < L[y];
}


int tag[N];
void ban(int l,int r){
	tag[l]++; tag[r+1]--;
}
void output(){
	int ans=0;
	for(int i=1;i<=n;i++) {
		tag[i]+=tag[i-1]; if(tag[i]==0) ans++;
	}
	printf("%d\n", ans);
}


int bit[N];
void change(int pos) {
	while(pos<N) {
		bit[pos]++; pos+=pos&(-pos);
	}
}
int query(int pos){
	int ans=0;
	while(pos){
		ans+=bit[pos]; pos-=pos&(-pos);
	}
	return ans;
}
int sum(int l,int r){
	return query(r) - query(l-1);
}
void clear(int pos){
	while(pos<N){
		bit[pos]=0; pos+=pos&(-pos);
	}
}
void add(vector<int>& vec) {
	vector<int> stk;
	for(auto u: vec) {
		while(stk.size()) {
			int x = stk.back();
			if(L[u] > R[x]) stk.pop_back();
			else {
				if(stk.size() >= 2) {
					printf("0\n"); exit(0);
				}
				break;
			}
		}
		stk.push_back(u);
	}

	for(auto u: vec)
		change(L[u]);
	
	int cnt_bu=0;
	for(auto u: vec){

		if(sum(L[u],R[u])>1) {
			if(sum(L[u],R[u]) != vec.size()) {
				printf("0\n"); exit(0);
			}
			ban(1, L[u]-1);
			ban(R[u]+1, n);
			ban(L[u], L[u]);
			int cnt_laji = 0;
			for(auto v: g[u]) {
				if(v==fat[u]) continue;
				if (sum(L[v], R[v]) == 0) ban(L[v], R[v]);
				else {
					cnt_laji ++;
				}
			}
			if (cnt_laji >= 2) {
				printf("0\n"); exit(0);
			}
			cnt_bu++;
		} else {
			ban(L[u],R[u]);
		}
		if(cnt_bu > 1) {printf("0\n"); exit(0);}
	}

	for(auto u: vec)
		clear(L[u]);
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]); v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()), v.end());

	for(int i=1;i<=n;i++){
		a[i]=id(a[i]);
		nodes[a[i]].push_back(i);
	}

	for(int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}

	dfs(1,1);	
	for(int i=1;i<=n;i++) {
		if(nodes[i].size() >= 2) {
			sort(nodes[i].begin(), nodes[i].end(), cmp);
			add(nodes[i]);
		}
	}
	output();
}