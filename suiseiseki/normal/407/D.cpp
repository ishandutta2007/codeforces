#include <cstdio>
#define Maxn 400
int n,m;
int a[Maxn+5][Maxn+5];
int f[Maxn+5][Maxn+5];
int pre[Maxn+5][Maxn*Maxn+5];
int mx(int a,int b){
	return a>b?a:b;
}
int max4(int a,int b,int c,int d){
	return mx(mx(a,b),mx(c,d));
}
int max5(int a,int b,int c,int d,int e){
	return mx(a,max4(b,c,d,e));
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int d=1;d<=m;d++){
			for(int l=1,r=d;r<=m;l++,r++){
				if(l==r){
					f[l][l]=mx(f[l][l],pre[l][a[i][l]]);
				}
				else if(a[i][l]==a[i][r]){
					f[l][r]=i;
				}
				else{
					f[l][r]=max5(f[l][r],f[l][r-1],f[l+1][r],pre[r][a[i][l]],pre[l][a[i][r]]);
				}
				ans=mx(ans,(i-f[l][r])*(r-l+1));
			}
		}
		for(int j=1;j<=m;j++){
			pre[j][a[i][j]]=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}