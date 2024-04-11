#include <bits/stdc++.h>
using namespace std;
const int N=100000+10;
int n,m;
int cnt[N];
vector<int> d[N];
set<int> st[N];
void init(){
	bool f[N]={0};
	for(int i=2;i<N;i++){
		if(f[i]==0){
			for(int j=i;j<N;j+=i){
				d[j].push_back(i); f[j]=1;
			}
		}
	}
}
void add(int x){
	for(auto y: d[x]){
		if(st[y].size()){
			printf("Conflict with %d\n", *st[y].begin());
			return;
		}
	}
	for(auto y: d[x]){
		st[y].insert(x);
	}	
	cnt[x]++;
	printf("Success\n");
}
void del(int x){
	for(auto y: d[x]){
		st[y].erase(x);
	}
	printf("Success\n");
	cnt[x]--;
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		char s[2]; scanf("%s",s);
		int x; scanf("%d",&x);
		if(s[0]=='+'){
			if(cnt[x]){
				printf("Already on\n"); continue;
			} 
			add(x);
		} else {
			if(cnt[x]==0){
				printf("Already off\n"); continue;
			}
			del(x);
		}
	}
}