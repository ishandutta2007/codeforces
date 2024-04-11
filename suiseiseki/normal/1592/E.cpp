#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxn=1000000;
const int Maxv=(1<<20);
const int Inf=0x3f3f3f3f;
int n;
int a[Maxn+5];
int b[Maxn+5];
int val[2][Maxv+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	memset(val,0x3f,sizeof val);
	int ans=0;
	for(int h=19;h>=0;h--){
		for(int i=1,j;i<=n;i=j+1){
			j=i;
			if(((a[i]>>h)&1)==0){
				continue;
			}
			while(j<=n&&((a[j]>>h)&1)==1){
				j++;
			}
			j--;
			val[(i-1)&1][0]=i-1;
			for(int k=i,s=0;k<=j;k++){
				s^=(a[k]>>(h+1));
				if(val[k&1][s]!=Inf){
					ans=std::max(ans,k-val[k&1][s]);
				}
				else{
					val[k&1][s]=k;
				}
			}
			val[(i-1)&1][0]=Inf;
			for(int k=i,s=0;k<=j;k++){
				s^=(a[k]>>(h+1));
				val[k&1][s]=Inf;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}