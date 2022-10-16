#include <cstdio>
const int Maxn=300000;
int n,q,Mod;
int f[Maxn+5];
int a[Maxn+5];
int num;
void update(int x,int v){
	if(x<1||x>n){
		return;
	}
	if(a[x]){
		num--;
	}
	a[x]=(a[x]+v)%Mod;
	if(a[x]){
		num++;
	}
}
int main(){
	scanf("%d%d%d",&n,&q,&Mod);
	f[1]=f[2]=1%Mod;
	for(int i=3;i<=n+1;i++){
		f[i]=(f[i-1]+f[i-2])%Mod;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int b;
		scanf("%d",&b);
		a[i]=(a[i]-b+Mod)%Mod;
	}
	for(int i=n;i>2;i--){
		a[i]=(0ll+a[i]-a[i-1]-a[i-2]+Mod*2)%Mod;
	}
	a[2]=(a[2]-a[1]+Mod)%Mod;
	for(int i=1;i<=n;i++){
		if(a[i]){
			num++;
		}
	}
	for(int i=1;i<=q;i++){
		char op[5];
		scanf("%s",op);
		int l,r;
		scanf("%d%d",&l,&r);
		if((*op)=='A'){
			update(l,1);
			update(r+1,Mod-f[r-l+2]);
			update(r+2,Mod-f[r-l+1]);
		}
		else{
			update(l,Mod-1);
			update(r+1,f[r-l+2]);
			update(r+2,f[r-l+1]);
		}
		if(num==0){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}