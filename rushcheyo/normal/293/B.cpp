#include<cstdio>
const int P=1000000007;
int n,m,k,lg[1025],col[15][15],f[15][15],v[15];
int dfs(int x,int y){
	if(y>m)x++,y=1;
	if(x>n)return 1;
	int l=f[x-1][y]|f[x][y-1],fst=-1,ans=0;
	for(int s=((1<<k)-1)&~l;s;s-=s&-s){
		int i=lg[s&-s];
		if(col[x][y]==-1||col[x][y]==i){
			f[x][y]=l|(1<<i);
			v[i]++;
			if(v[i]==1){
				if(fst==-1)fst=dfs(x,y+1);
				ans+=fst;
			}else ans+=dfs(x,y+1);
			if(ans>=P)ans-=P;
			v[i]--;
		}
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(n+m-1>k)return puts("0"),0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",col[i]+j);
			if(col[i][j]--)v[col[i][j]]++;
		}
	for(int i=2;i<1<<k;i<<=1)lg[i]=lg[i>>1]+1;
	printf("%d\n",dfs(1,1));
	return 0;
}