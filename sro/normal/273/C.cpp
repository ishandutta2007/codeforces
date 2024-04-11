#include <bits/stdc++.h>
using namespace std;
//Coded by 
//The most attractive girl in the world

int n,m;
vector<int> nei[300005];
int col[300005];
int cyka[300005];
char ans[300005];
set<pair<int,int> > qs; 

void func(int now){
	qs.erase(make_pair(-cyka[now],now));
	cyka[now]=0;
	for(int i:nei[now]){
		if(col[now]==col[i]){
			cyka[now]++;
		}
	}
	qs.insert(make_pair(-cyka[now],now));
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		nei[a].push_back(b);
		nei[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		cyka[i]=nei[i].size();
		qs.insert(make_pair(-cyka[i],i));
	}
	while(1){
		int x=qs.begin()->second;
		if(cyka[x]<=1){
			break;
		}
		col[x]^=1;
		func(x);
		for(int i:nei[x]){
			func(i);
		}
	}
	for(int i=1;i<=n;i++){
		ans[i]=col[i]+'0';
	}
	puts(ans+1);
	return 0;
}