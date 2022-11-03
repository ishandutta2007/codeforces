/*
ID: Sfiction
OJ: CF
PROB: 500E
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=2E5+100;

int n;
int p[MAXN],l[MAXN];
int r[MAXN];
int u[MAXN][20],cost[MAXN][20];

void Init(){
	static int pos,sta[MAXN];

	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d%d",&p[i],&l[i]);
	pos=-1;
	for (int i=n;i;--i){
		r[i]=p[i]+l[i];
		while (pos>=0 && r[i]>=p[sta[pos]]){
			r[i]=max(r[i],r[sta[pos]]);
			--pos;
		}
		if (pos<0){
			u[i][0]=n+1;
			cost[i][0]=0;
		}
		else{
			u[i][0]=sta[pos];
			cost[i][0]=p[sta[pos]]-r[i];
		}
		sta[++pos]=i;
	}
	for (int i=n;i;--i){
		int j;
		for (j=0;u[i][j]<=n;++j){
			u[i][j+1]=u[u[i][j]][j];
			cost[i][j+1]=cost[i][j]+cost[u[i][j]][j];
		}
		for (;j<20;++j){
			u[i][j]=n+1;
			cost[i][j]=0;
		}
	}
}

int main(){
	Init();
	int q,x,y;
	scanf("%d",&q);
	while (q--){
		scanf("%d%d",&x,&y);
		int i,j,ans=0;
		for (j=0;u[x][j]<=n;++j);
		for (i=x;j>=0;--j)
			if (u[i][j]<=y){
				ans+=cost[i][j];
				i=u[i][j];
			}
		printf("%d\n",ans);
	}
	return 0;
}