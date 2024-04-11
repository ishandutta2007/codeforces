#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define Mod 1000000007
int n;
int f[35][35][2];
void add(int &a,int b){
	a+=b;
	if(a>Mod){
		a-=Mod;
	}
}
int main(){
	scanf("%d",&n);
	f[30][0][1]=1;
	int x,y;
	for(int i=30;i>0;i--){
		for(int j=0;j<=30;j++){
			if(j==0){
				x=1;
				y=0;
			}
			else{
				x=(1<<(j-1))%Mod;
				y=(1<<(j-1))%Mod;
			}
			add(f[i-1][j+1][0],f[i][j][0]);
			add(f[i-1][j][0],(int)((1ll<<j)*f[i][j][0]%Mod));
			if(n&(1<<(i-1))){
				add(f[i-1][j][0],(int)(1ll*x*f[i][j][1]%Mod));
				add(f[i-1][j][1],(int)(1ll*y*f[i][j][1]%Mod));
				add(f[i-1][j+1][1],f[i][j][1]);
			}
			else{
				add(f[i-1][j][1],(int)(1ll*x*f[i][j][1]%Mod));
			}
		}
	}
	int ans=0;
	for(int i=0;i<=30;i++){
		add(ans,f[0][i][0]);
		add(ans,f[0][i][1]);
	}
	printf("%d\n",ans);
	return 0;
}