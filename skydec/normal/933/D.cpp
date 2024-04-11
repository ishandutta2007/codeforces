#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int P=1000000007;
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
int inv2=Pow(2,P-2);
int inv6=Pow(6,P-2);
LL m;
int cf[4];
int dy[4];
int C2(int x){
	return (x*1ll*(x-1)/2)%P;
}
int S3(int x){
	return ((x*1ll*(x+1)%P)*1ll*(2*x+1)%P)*1ll*inv6%P;
}
int calc(int v,int x){
	v=v*1ll*v%P;

	int _m=m%P;

	int w=(C2((m+1)%P)+P-C2((v+x*1ll*x)%P))%P;

	w=w*1ll*(_m+1)%P;

	int w2=S3(_m);
	int w3=S3((v+x*1ll*x+P-1)%P);

	w=(w*1ll+P-w2+w3)%P;

	return w;
}
int shi[4][4];
void initshi(){
	rep(i,0,3){
		shi[i][0]=1;
		rep(j,0,3)if(i^j){
			int t1=Pow((i*1ll*i-j*1ll*j)%P+P,P-2);
			int t2=(P-(j*1ll*j%P))*1ll*t1%P;
			per(k,3,0){
				shi[i][k]=shi[i][k]*1ll*t2%P;
				if(k)shi[i][k]=(shi[i][k]+shi[i][k-1]*1ll*t1)%P;
			}
		}
	}
}
void initC(int px){
	rep(i,0,3){
		dy[i]=calc(px,i);
	}
	rep(i,0,3){
		cf[i]=0;
		rep(j,0,3)cf[i]=(cf[i]+shi[j][i]*1ll*dy[j])%P;
	}
}
int getBound(LL x){
	int l=0;
	int r=1000000;
	int ret=0;
	while(l<r){
		int mid=(l+r)>>1;
		if(mid*1ll*mid<=x)ret=mid,l=mid+1;
		else r=mid;
	}
	if(l*1ll*l<=x)ret=l;
	return ret;
}
int sss[4][1000005];
int getV(int l,int r){
	if(l>r)return 0;
	int ans=0;
	rep(i,0,3){
		int w=sss[i][r];
		if(l)w=(w+P-sss[i][l-1]);
		ans=(ans+cf[i]*1ll*w)%P;
	}
	return ans;
}
void initF(int n){
	rep(l,0,3)rep(i,0,n){
		if(i)sss[l][i]=sss[l][i-1];
		sss[l][i]=(sss[l][i]+Pow(i,2*l))%P;
	}
}
int main(){
	initshi();
	initF(1000000);
	scanf("%lld",&m);
	int ans=0;
	for(int x=0;x*1ll*x<=m;++x){
		initC(x);
		int y=getBound(m-x*1ll*x);
		ans=(ans+getV(0,y))%P;
	}
	ans=ans*4ll%P;
	initC(0);
	int w=getV(0,0);
	ans=(ans+P-(3ll*w%P))%P;

	initC(0);
	int y=getBound(m);
	w=getV(1,y);
	ans=(ans+P-(4ll*w%P))%P;
	printf("%d\n",ans);
	return 0;
}