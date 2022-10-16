#include <cstdio>
#include <algorithm>
const int Maxn=200000;
int n,q;
char a[Maxn+5];
int sum[2][Maxn+5];
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",a+1);
	for(int i=1;i<=n;i++){
		sum[0][i]=sum[0][i-1],sum[1][i]=sum[1][i-1];
		if(a[i]==a[i-1]){
			sum[a[i]-'0'][i]++;
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",std::max(sum[0][r]-sum[0][l],sum[1][r]-sum[1][l])+1);
	}
	return 0;
}