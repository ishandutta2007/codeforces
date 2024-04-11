#include<bits/stdc++.h>
#define bit(xx,ii) (xx>>ii&1)
const int M=1000000007;
using namespace std;
int q,n,L1,R1,L2,R2,K,ans,
f[8],g[8],F[8],G[8],va;
inline long long cal(int A,int B){
	if(A<0||B<0)return 0;
	memset(f,0,32),f[7]=1;
	memset(F,0,32);
	long long res=0;
	//cerr<<"cal "<<A<<','<<B<<endl;
	for(int i=30;~i;i--){
		for(int j=0;j<8;j++)
		g[j]=f[j],G[j]=F[j],f[j]=F[j]=0;
		//cerr<<i<<"=======\n";
		for(int j=0,a,b,c,k;j<8;j++){
			//cerr<<"trans "<<j<<'('<<g[j]<<','<<G[j]<<endl;
			for(a=0;a<1||a<2&&(bit(A,i)||!bit(j,0));a++)
			for(b=0;b<1||b<2&&(bit(B,i)||!bit(j,1));b++){
				c=a^b;
				if(c&&bit(j,2)&&!bit(K,i))continue;
				k=j;
				if(bit(A,i)&&bit(j,0)&&!a)k^=1;
				if(bit(B,i)&&bit(j,1)&&!b)k^=2;
				if(bit(K,i)&&bit(j,2)&&!c)k^=4;
				//cerr<<j<<"-("<<a<<','<<b<<")->"<<k<<endl;
				F[k]=(F[k]+G[j]+(1ll*c*g[j]<<i))%M;
				f[k]=(f[k]+g[j])%M;
			}
		}
	}
	for(int i=0;i<8;i++)res+=F[i]+f[i];
	return res;
}
int main(){
	for(scanf("%d",&q);q--;){
		scanf("%d%d%d%d%d",&L1,&L2,&R1,&R2,&K);
		L1-=2,L2-=2,R1--,R2--,K--;
		ans=(cal(R1,R2)-cal(L1,R2)-cal(L2,R1)+cal(L1,L2))%M;
		printf("%d\n",(ans+M)%M);
	}
}