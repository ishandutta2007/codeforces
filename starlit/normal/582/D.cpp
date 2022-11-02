#include<bits/stdc++.h>
const int N=4004,M=1e9+7,L=1e4;
using namespace std;
int l,d,p,m,S[N],f[4][N],g[4][N],
tp,i,k,a,b;
long long B[N];
inline int cal(int s){//s<p
	if(s<0)return 0;
	return(s+2ll)*(s+1)/2%M;
}
inline void trans(int v){
	//cerr<<"trans "<<b<<'/'<<a<<":"<<v<<endl;
	f[b<<1|a][k+b]=(f[b<<1|a][k+b]+1ll*v*tp)%M;
}
char A[N];
int main(){
//	freopen("dat.txt","r",stdin);
	scanf("%d%d%s",&p,&m,A);
	d=strlen(A)-1;
	l=1+(d>>2);
	for(i=d;~i;i--)
	B[i>>2]=B[i>>2]*10+A[d-i]-48;
	for(d=0;l;d++){
	//	for(i=l-1;~i;i--)
	//	cerr<<(int)B[i]<<' ';
	//	cerr<<endl;
		for(i=l-1;~i;i--)
		S[d]=(1LL*L*S[d]+B[i])%p;
	//	cerr<<"?"<<S[d]<<endl;
		for(i=l-1;~i;i--)
		i?B[i-1]+=B[i]%p*L:0,B[i]/=p;
		for(;l&&!B[l-1];l--);
	}
	reverse(S,S+d);
//	for(int s=0;s<d;s++)
//	cerr<<S[s]<<' ';cerr<<endl;
	if(d<m)return puts("0"),0;
	f[1][0]=1;
	i=0;
	for(register int j,tv;i<d;i++){
		//cerr<<i<<"=====\n";
		for(j=0;j<4;j++)
		for(k=0;k<=i;k++)
		g[j][k]=f[j][k],f[j][k]=0;
		for(j=0;j<4;j++)
		for(k=0;k<=i;k++)
		if(tp=g[j][k]){
			//cerr<<"("<<j<<','<<k<<")"<<tp<<endl;
			for(b=0;b<2;b++){//
				a=0;
				if(j&1){
					if(j&2)trans((1ll*(S[i]-b+1)*p+
					(p-1ll-S[i]+b)*(p+S[i]-b)/2-cal(p-b-1))%M);
					else trans(cal(S[i]-1-b));
					a=1;
					j&2?trans(p-S[i]+b-1):trans(S[i]-b+1);
				}
				else tv=cal(p-1-b),
				j&2?trans((1ll*p*p-tv)%M):trans(tv);
			}
		}
	}
	tp=0;
	for(i=0;i<2;i++)
	for(int j=m;j<=d;j++)
	(tp+=f[i][j])%=M;
	printf("%d",(M+tp)%M);
}