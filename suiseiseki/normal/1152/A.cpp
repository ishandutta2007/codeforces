#include <cstdio>
#define Maxn 100000
int a[Maxn+5],b[Maxn+5];
int t_a[2],t_b[2];
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]=(a[i]&1);
		t_a[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		b[i]=(b[i]&1);
		t_b[b[i]]++;
	}
	printf("%d\n",mn(t_a[0],t_b[1])+mn(t_a[1],t_b[0]));
	return 0;
}