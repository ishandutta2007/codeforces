#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=200000;
const int Inf=0x3f3f3f3f;
int n,k;
int l[Maxn+5];
int f[Maxn+5];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&l[i]);
	}
	sort(l+1,l+1+n,greater<int>());
	f[0]=1;
	f[1]=-1;
	int ans=Inf;
	int sum=0;
	for(int i=0,j=1;i<Maxn-1;i++){
		sum+=f[i];
		f[i+1]+=f[i];
		if(sum+f[i+1]>=k){
			ans=min(ans,i+1);
		}
		while(f[i]>0&&j<=n){
			int u=((l[j]-1)>>1);
			int v=l[j]-1-u;
			f[i+2]++;
			f[i+2+u]--;
			f[i+2]++;
			f[i+2+v]--;
			f[i]--;
			sum--;
			j++;
		}
	}
	if(ans==Inf){
		puts("-1");
	}
	else{
		printf("%d\n",ans);
	}
	return 0;
}