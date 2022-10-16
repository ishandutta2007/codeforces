#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxn=100;
const int Inf=0x3f3f3f3f;
int n;
int a[Maxn+5],b[Maxn+5];
bool _f[2][Maxn*Maxn*2+5];
bool *f[2];
void solve(){
	scanf("%d",&n);
	int sum=0;
	int val=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		val+=a[i]*a[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		sum+=b[i];
		val+=b[i]*b[i];
	}
	memset(_f,0,sizeof _f);
	int cur=0,nxt;
	f[cur][0]=1;
	for(int i=1;i<=n;i++){
		int v=a[i]-b[i];
		nxt=cur^1;
		memset(_f[nxt],0,sizeof _f[nxt]);
		for(int j=-100*(i-1);j<=100*(i-1);j++){
			if(f[cur][j]){
				f[nxt][j+v]=1,f[nxt][j-v]=1;
			}
		}
		cur=nxt;
	}
	int ans=Inf;
	for(int i=-100*n;i<=100*n;i++){
		if(f[cur][i]){
			int s_1=(sum+i)/2,s_2=(sum-i)/2;
			ans=std::min(ans,s_1*s_1+s_2*s_2);
		}
	}
	ans+=val*(n-2);
	printf("%d\n",ans);
}
int main(){
	f[0]=_f[0]+Maxn*Maxn+1;
	f[1]=_f[1]+Maxn*Maxn+1;
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}