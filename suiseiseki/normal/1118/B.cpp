#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 200000
int a[Maxn+5];
int sum_l[Maxn+5][2];
int sum_r[Maxn+5][2];
int main(){
	int n;
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		sum_l[i][0]=sum_l[i-1][0];
		sum_l[i][1]=sum_l[i-1][1];
		sum_l[i][i&1]+=a[i];
	}
	for(int i=n;i>0;i--){
		sum_r[i][0]=sum_r[i+1][0];
		sum_r[i][1]=sum_r[i+1][1];
		sum_r[i][i&1]+=a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if((sum-a[i])&1){
			continue;
		}
		if(sum_l[i-1][0]+sum_r[i+1][1]==((sum-a[i])>>1)){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}