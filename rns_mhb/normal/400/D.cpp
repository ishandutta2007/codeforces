#include <stdio.h>
#define M 501
#define N 101010
int d[M][M];
int root[N], group[N], c[M];
int find_root(int u){
	int v=root[u];
	if(v==u)return u;
	return root[u]=find_root(v);
}
int n, k, m;

int main(){
	//freopen("D.in", "r", stdin);
	//freopen("D.out", "w", stdout);
	int i, j, l, x;
	scanf("%d %d %d", &n, &m, &k);
	for(i=1; i<=k; i++)for(j=1; j<=k; j++)i==j?0:d[i][j]=-1;
	for(i=1; i<=n; i++)root[i]=i;
	for(i=1; i<=k; i++){
		scanf("%d", &x);
		for(j=c[i-1]+1; j<=(c[i]=c[i-1]+x); j++)group[j]=i;
	}

	int gi, gj;
	int a, b;
	while(m--){
		scanf("%d %d %d", &i, &j, &x);
		gi=group[i], gj=group[j];
		if(d[gi][gj]==-1 || d[gi][gj]>x)d[gi][gj]=d[gj][gi]=x;
		if(!x){
			a=find_root(i), b=find_root(j);
			if(a!=b)root[a]=b;
		}
	}
	for(i=1; i<=k; i++){
		x=find_root(c[i]);
		for(j=c[i-1]+1; j<c[i] && x==find_root(j); j++);
		if(j<c[i]){
			puts("No");
			return 0;
		}
	}
	for(l=1; l<=k; l++)for(i=1; i<=k; i++)for(j=1; j<=k; j++)if(d[i][l]>=0&&d[l][j]>=0)
		if(d[i][j]<0 || d[i][j]>d[i][l]+d[l][j])d[i][j]=d[i][l]+d[l][j];
	puts("Yes");
	for(i=1; i<=k; i++){
		for(j=1; j<=k; j++)printf("%d%c", 	d[i][j], j==k?'\n':' ');
	}
	return 0;
}