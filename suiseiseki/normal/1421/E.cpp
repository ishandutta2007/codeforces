#include <cstdio>
#include <cstring>
template<typename Elem>
Elem max(Elem a,Elem b){
	return a>b?a:b;
}
typedef long long ll;
const int Maxn=200000;
int n;
int a[Maxn+5];
ll f[Maxn+5][3][3];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n==1){
		printf("%lld\n",a[1]);
		return 0;
	}
	memset(f,-0x3f,sizeof f);
	f[0][0][0]=f[0][0][1]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			if(i>1){
				if(i&1){
					f[i][j][2]=max(f[i][j][2],f[i-1][j][1]+a[i]);
					f[i][j][2]=max(f[i][j][2],f[i-1][(j+2)%3][0]-a[i]);
				}
				else{
					f[i][j][2]=max(f[i][j][2],f[i-1][(j+2)%3][1]-a[i]);
					f[i][j][2]=max(f[i][j][2],f[i-1][j][0]+a[i]);
				}
			}
			f[i][j][2]=max(f[i][j][2],f[i-1][j][2]+a[i]);
			f[i][j][2]=max(f[i][j][2],f[i-1][(j+2)%3][2]-a[i]);
			if(i&1){
				f[i][j][1]=max(f[i][j][1],f[i-1][(j+2)%3][1]-a[i]);
				f[i][j][0]=max(f[i][j][0],f[i-1][j][0]+a[i]);
			}
			else{
				f[i][j][1]=max(f[i][j][1],f[i-1][j][1]+a[i]);
				f[i][j][0]=max(f[i][j][0],f[i-1][(j+2)%3][0]-a[i]);
			}
		}
	}
	printf("%lld\n",f[n][(1-n%3+3)%3][2]);
	return 0;
}