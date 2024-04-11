#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

map<int, int> M; 
int u[100005];
int n,a,b;
int num[100005], sta[100005], good[100005];

int find(int i){
	return u[i] == i ? i : u[i] = find(u[i]);
}

void unite(int i, int j){
	u[find(i)] = find(j);
}

int main(){
	scanf("%d%d%d", &n, &a, &b);
	for(int i = 0; i < n; i++) scanf("%d", &num[i]), M[num[i]] = i, u[i] = i;
	for(int i = 0; i < n; i++){
		if((bool)M.count(a-num[i])) unite(M[a-num[i]],i), sta[i] |= 1;
		if((bool)M.count(b-num[i])) unite(M[b-num[i]],i), sta[i] |= 2;
	}
//	for(int i = 0; i < n; i++){
//		if(M.count(a-num[i])) sta[M[a-num[i]]] &= sta[i];
//		if(M.count(b-num[i])) sta[M[b-num[i]]] &= sta[i];
//	}
	for(int i = 0; i < n; i++) good[i] = 3;
	for(int i = 0; i < n; i++){
		good[find(i)] &= sta[i];
	}
	for(int i = 0; i < n; i++){
		if(good[i] == 0) {
			//cout << i;
			return !printf("NO");
		}
	}
	printf("YES\n");
	for(int i = 0; i < n; i++){
		int st = good[find(i)];
		
		printf("%d ", ((st&1) == 0 ? 1 : 0));
	}
}