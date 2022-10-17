#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Maxn 1000000
struct Edge{
	int s,t,d;
	friend bool operator <(Edge a,Edge b){
		return a.d<b.d;
	}
}e[Maxn+5];
int n,m,f[Maxn+5];
int get(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=get(f[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&e[i].s,&e[i].t,&e[i].d);
	}
	sort(e+1,e+m);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<m;i++){
		if(get(e[i].s)!=get(e[i].t)){
			f[get(e[i].s)]=get(e[i].t);
			if(get(e[0].s)==get(e[0].t)){
				cout<<e[i].d<<endl;
				return 0;
			}
		}
	}
	puts("1000000000");
	return 0;
}