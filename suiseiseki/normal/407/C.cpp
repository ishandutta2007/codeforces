#include <cstdio>
#define Maxn 100000
#define Mod 1000000007
#define Maxk 101
int C[Maxn+Maxk+5][Maxk+5],tmp[Maxn+5][Maxk+5],res[Maxn+5][Maxk+5],a[Maxn+5];
void add(int &a,int b){
	a+=b;
	if(a>=Mod){
		a-=Mod;
	}
	if(a<0){
		a+=Mod;
	}
}
int mn(int a,int b){
	return a<b?a:b;
}
void init(){
	C[0][0]=1;
	for(int i=1;i<=Maxn+Maxk;i++){
		C[i][0]=1;
		for(int j=1;j<=mn(i,Maxk);j++){
			add(C[i][j],C[i-1][j]);
			add(C[i][j],C[i-1][j-1]);
		}
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	init();
	int left,right,k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&left,&right,&k);
		add(tmp[left][k+1],1);
		for(int j=k+1;j>0;j--){
			add(tmp[right+1][j],-C[k+1-j+right-left][k+1-j]);
		}
	}
	for(int i=Maxk;i>=0;i--){
		for(int j=1;j<=n;j++){
			add(res[j][i],res[j][i+1]);
			add(res[j][i],res[j-1][i]);
			add(res[j][i],tmp[j][i]);
		}
	}
	for(int i=1;i<=n;i++){
		add(a[i],res[i][1]);
		printf("%d ",a[i]);
	}
	puts("");
	return 0;
}