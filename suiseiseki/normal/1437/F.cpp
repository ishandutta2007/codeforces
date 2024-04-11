#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=5000;
const int Mod=998244353;
int n;
int a[Maxn+5];
int f[Maxn+5][Maxn+5];
int s[Maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>0;j--){
			if((a[j]<<1)<=a[i]){
				s[i]=j;
				break;
			}
		}
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s[i]+1;j++){
			f[i][j]=(f[i][j]+f[s[i]][j-1])%Mod;
		}
		for(int j=1;j<=s[i]+1;j++){
			f[i][j]=(f[i][j]+1ll*(s[i]-j+2)*f[i][j-1])%Mod;
		}
		for(int j=0;j<i;j++){
			f[i][j]=(f[i][j]+f[i-1][j])%Mod;
		}
	}
	printf("%d\n",f[n][n]);
	return 0;
}