#include<bits/stdc++.h>
using namespace std;

const int M=1000000007;
int fexp(int x,int t){
	if(!t)return 1;
	int tmp=fexp(x,t>>1);
	tmp=1ll*tmp*tmp%M;
	return (t&1)?1ll*tmp*x%M:tmp;
}
int k,a,b,pa,pb,f[1005][1005];
int main(){
	scanf("%d%d%d",&k,&a,&b);
	int t=fexp(a+b,M-2);
	pa=1ll*a*t%M;pb=1ll*b*t%M;
	f[0][1]=1;
	int ans=0;
	for(int i=0;i<k;i++){
		for(int j=1;j<k;j++){
			int t=f[i][j];
			f[i][j+1]=(f[i][j+1]+1ll*t*pa)%M;
			if(i+j>=k){
				ans=(ans+1ll*t*pb%M*(i+j))%M;
			}else{
				f[i+j][j]=(f[i+j][j]+1ll*t*pb)%M;
			}
		}
	}
	t=fexp((M+1-pa)%M,M-2);
	t=1ll*pa*pb%M*t%M*t%M;
	for(int i=0;i<k;i++){
		ans=(ans+1ll*f[i][k]*(i+k+t))%M;
	}
	printf("%d\n",ans);
	return 0;
}