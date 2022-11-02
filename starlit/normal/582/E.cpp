#include<bits/stdc++.h>
const int N=1<<16,M=1000000007;
using namespace std;
int n,m,sum[503],u[16][4],re,tp,
f[170][N],cnt;
char S[503];
inline int sig(int x,bool d){
	int y=0;
	for(int i=0;i<n;i++)
	y|=(u[i][x]^d)<<i;
	return y;
}
inline void fmt(int*c,int t,bool d){
	for(int i=1;i<1<<n;i<<=1)
	for(int j=0;j<1<<n;j++)
	if(d^!(j&i))
	c[j]=(c[j]+t*c[j^i])%M;
}
inline void mul(int*a,int*b,int*c,bool d){
	fmt(a,1,d),fmt(b,1,d),fmt(c,1,d);
	for(int i=0;i<1<<n;i++)
	c[i]=(c[i]+a[i]*1ll*b[i])%M;
	fmt(a,-1,d),fmt(b,-1,d),fmt(c,-1,d);
}
inline int cal(int l,int r){
	int no=cnt++;
	if(l==r){
		if(S[l]^63){
			if(S[l]>=97)
			f[no][sig(S[l]-97,1)]=1;
			else f[no][sig(S[l]-65,0)]=1;
		}
		else for(int i=0;i<8;i++)
		f[no][sig(i>>1,i&1)]++;
	}
	else{
		int a,b,mi;
		for(mi=l;sum[mi++]^sum[l-1];);
		a=cal(l+1,mi-2),b=cal(mi+2,r-1);
		if(S[mi]^124)mul(f[a],f[b],f[no],0);
		if(S[mi]^38)mul(f[a],f[b],f[no],1);
	}
	return no;
}
int main(){
	scanf("%s%d",S+1,&n);
	m=strlen(S+1);
	for(int i=1;i<=m;i++)
	sum[i]=sum[i-1]+(S[i]^40?S[i]^41?0:-1:1);
	for(int i=0;i<n;i++){
		for(int j=0;j<4;j++)
		scanf("%d",u[i]+j);
		scanf("%d",&tp),re|=tp<<i;
	}
	printf("%d",(f[cal(1,m)][re]+M)%M);
}