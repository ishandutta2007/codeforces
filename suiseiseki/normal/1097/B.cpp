#include <cstdio>
#define Mod 360
int a[20];
bool f[400][2];
int main(){
	int n;
	scanf("%d",&n);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=0;j<Mod;j++){
			if(f[j][0]){
				f[(j+a[i])%Mod][1]=1;
				f[(j-a[i]+Mod)%Mod][1]=1;
			}
		}
		for(int j=0;j<Mod;j++){
			f[j][0]=f[j][1];
			f[j][1]=0;
		}
	}
	if(f[0][0]){
		puts("YES");
	}
	else{
		puts("NO");
	}
	return 0;
}