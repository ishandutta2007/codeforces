#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;
const int Maxn=2000;
const int Maxm=500000;
int n,m;
int u[Maxm+5],v[Maxm+5];
bitset<Maxn<<1|1> a[Maxn+5];
void gauss(int n){
	for(int i=1;i<=n;i++){
		int now=0;
		for(int j=i;j<=n;j++){
			if(a[j][i]){
				now=j;
			}
		}
		if(now!=i){
			swap(a[i],a[now]);
		}
		for(int j=1;j<=n;j++){
			if(i!=j&&a[j][i]){
				a[j]^=a[i];
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
		a[u[i]][v[i]]=1;
	}
	for(int i=1;i<=n;i++){
		a[i][i+n]=1;
	}
	gauss(n);
	for(int i=1;i<=m;i++){
		if(a[v[i]][u[i]+n]){
			puts("NO");
		}
		else{
			puts("YES");
		}
	}
	return 0;
}