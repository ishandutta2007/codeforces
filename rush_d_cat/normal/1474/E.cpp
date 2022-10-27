#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2000000 + 10;
struct edge {
	int u,v,w;
	bool operator<(const edge&o)const{
		return w>o.w;
	}
} e[N]; int tot=0;
int par[N];
int find(int x){
	return par[x]==x?x:par[x]=find(par[x]);
}

void test(int n){
	tot=0;
	for(int i=1;i<=n;i++)par[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			e[++tot]=(edge){i,j,(j-i)*(j-i)};
		}
	}
	sort(e+1,e+1+tot);
	LL sum=0;
	for(int i=1;i<=tot;i++){
		if(find(e[i].u) != find(e[i].v)) {
			sum+=e[i].w;
			par[find(e[i].u)]=find(e[i].v);
			// printf("%d %d\n", e[i].u, e[i].v);
		}
	}


	LL sum3=0;
	for(int i=2;i<=n;i++){
		if(i<=n/2) {
			sum3+=1LL*(n-i)*(n-i);
		}else{
			sum3+=1LL*(i-1)*(i-1);
		}
	}
	printf("n = %d\n", n);
	
	printf("%lld %lld\n", sum, sum3);
	assert(sum == sum3);
}
int main() {
	// test(692);
	int t;
	scanf("%d", &t);
	while (t --) {
		LL n; scanf("%lld", &n);
		if(n==2) {
			printf("1\n2 1\n1\n2 1\n"); continue;
		}
		if(n==3) {
			printf("5\n2 3 1\n2\n1 3\n3 2\n"); continue;
		}
		LL sum3=0;
		for(int i=2;i<=n;i++){
			if(i<=n/2) {
				sum3+=1LL*(n-i)*(n-i);
			}else{
				sum3+=1LL*(i-1)*(i-1);
			}
		}
		printf("%lld\n", sum3);
		vector<int> p(n+1,0);
		p[n]=2;
		for(int i=2;i<n/2;i++) p[i]=i+1;
		p[n/2]=1; p[1]=n/2+1;
		for(int i=n/2+1;i<=n-1;i++) p[i]=i+1;
		for(int i=1;i<=n;i++) printf("%d ", p[i]); printf("\n");
		printf("%d\n", n-1);
		for(int i=2;i<=n/2;i++){
			printf("%d %d\n", i,n);
		}
		for(int i=n/2+1;i<=n-1;i++){
			printf("%d %d\n", i,1);
		}
		printf("%d %d\n", 1,n);
	}
}