#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,a,b,c;
//ll s[8];
int pri[N],top,cc[N],cp[N];
int cnt(int x){return cc[x];}
bool is[N];
/*struct mat{
	int a[8][8];
}tABC,tAB,tBC,tCA,tA,tB,tC;
mat mul(mat x,mat y){
	static mat z;memset(z.a,0,sizeof z.a);
	for(int i=0;i<8;++i)for(int k=0;k<8;++k)for(int j=0;j<8;++j)z.a[i][j]+=x.a[i][k]*y.a[k][j];
	return z;
}
mat pw(mat x,int R){
	static mat z;memset(z.a,0,sizeof z.a);
	for(int i=0;i<8;++i)z.a[i][i]=1;
	for(;R;R>>=1,x=mul(x,x))if(R&1)z=mul(z,x);
	return z;
}
mat gen(int x,int y,int zz){	
	static mat z;memset(z.a,0,sizeof z.a);
	for(int i=0;i<3;++i)if(x==1||i!=1)
		for(int j=0;j<3;++j)if(y==1||j!=1)
			for(int k=0;k<3;++k)if(zz==1||k!=1)
			{
				int p=0,q=0;
				if(i>0)q|=1;
				if(i==2)p|=1;
				if(j>0)q|=2;
				if(j==2)p|=2;
				if(k>0)q|=4;
				if(k==2)p|=4;
				z.a[p][q]=1;
			}
	return z;
}*/
bool check(int x,int y,int z){
	for(int i=0;i<3;++i)
	for(int j=0;j<3;++j)if(i!=j)
	for(int k=0;k<3;++k)if(k!=i&&k!=j)
		if((x&(1<<i))&&(y&(1<<j))&&(z&(1<<k)))
			return 1;
	return 0;
}
bool che[8][8][8];
int main(){
	is[1]=1;cc[1]=1;cp[1]=0;
	for(int i=2;i<=100000;++i){
		if(!is[i]){
			pri[++top]=i;
			cc[i]=2;
			cp[i]=1;
		}
		for(int j=1;j<=top&&1ll*pri[j]*i<=100000;++j){
			is[pri[j]*i]=1;
			if(i%pri[j]==0){
				cc[pri[j]*i]=cc[i]/(cp[i]+1)*(cp[i]+2),cp[pri[j]*i]=cp[i]+1;
				break;
			}else cc[pri[j]*i]=cc[i]*2,cp[pri[j]*i]=1;
		}
	}
	//tABC=gen(1,1,1);tAB=gen(1,1,0);tBC=gen(0,1,1);tCA=gen(1,0,1);tA=gen(1,0,0);tB=gen(0,1,0);tC=gen(0,0,1);
	scanf("%d",&n);rep(i,7)rep(j,7)rep(k,7)if(check(i,j,k))che[i][j][k]=1;else che[i][j][k]=0;
	rep(i,n){
		scanf("%d%d%d",&a,&b,&c);
		int A=cnt(a),B=cnt(b),C=cnt(c),AB=cnt(__gcd(a,b)),BC=cnt(__gcd(b,c)),CA=cnt(__gcd(c,a)),ABC=cnt(__gcd(__gcd(a,b),c));
		AB-=ABC,BC-=ABC,CA-=ABC;
		A-=AB+CA+ABC,B-=AB+BC+ABC,C-=CA+BC+ABC;
		//printf("%d %d %d %d %d %d %d\n",A,B,C,AB,BC,CA,ABC);
		//ll s=ABC;
		//s+=(AB+ABC)*(C+BC+CA+ABC)-ABC;
		//s+=(BC+ABC)*(A+CA+AB+ABC)-ABC;
		//s+=(CA+ABC)*(B+AB+BC+ABC)-ABC;
		//printf("%lld\n",s);
		//s+=A*(B*(C+BC+CA+ABC)+BC*(C+BC+CA+ABC-1)+AB*(C+BC+CA+ABC-1)+ABC*(C+BC+CA+ABC-1));
		//s+=AB*(B*(C+BC+CA+ABC-1)+BC*(C+BC+CA+ABC-2)+(AB-1)*(C+BC+CA+ABC-2)+ABC*(C+BC+CA+ABC-1));;
		//s+=CA*(B*(C+BC+CA+ABC-1)+BC*(C+BC+CA+ABC-2)+AB*(C+BC+CA+ABC-2)+ABC*(C+BC+CA+ABC-2));;
		//s+=ABC*(B*(C+BC+CA+ABC-1)+BC*(C+BC+CA+ABC-2)+AB*(C+BC+CA+ABC-2)+(ABC-1)*(C+BC+CA+ABC-2));;
		int s[8];
		s[1]=A;s[2]=B;s[3]=AB;s[4]=C;s[5]=CA;s[6]=BC;s[7]=ABC;
		ll ss=ABC;
		rep(i,7)rep(j,7)if(che[i][j][j]){
			if(i!=j)ss+=s[i]*s[j];else ss+=s[i]*(s[j]-1);
		}
		rep(i,7)rep(j,i)rep(k,j)if(che[i][j][k]){
			ll tp;
			if(i==j&&j==k)tp=s[i]*(s[i]-1)*(s[i]-2)/6;
			else if(i==j)tp=s[i]*(s[i]-1)/2*s[k];
			else if(i==k)tp=s[i]*(s[i]-1)/2*s[j];
			else if(j==k)tp=s[j]*(s[j]-1)/2*s[i];
			else tp=s[i]*s[j]*s[k];
			ss+=tp;
		}
		/*mat z;memset(z.a,0,sizeof z.a);
		for(int i=0;i<8;++i)z.a[i][i]=1;
		z=mul(z,pw(tA,A));
		z=mul(z,pw(tB,B));
		z=mul(z,pw(tC,C));
		z=mul(z,pw(tAB,AB));
		z=mul(z,pw(tBC,BC));
		z=mul(z,pw(tCA,CA));
		z=mul(z,pw(tABC,ABC));*/
		printf("%lld\n",ss);
	}
	//system("pause");
	return 0;
}