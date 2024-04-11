#include<bits/stdc++.h>
#define pls(xx,yy) (xx+=(yy))>=M?xx-=M:0
const int N=2003,M=1000000007;
using namespace std;
int n,m,f1[N],f2[N],g1[N],g2[N];
long long ans;
struct str{
	char s[N];int a[N];
	void cal();
}m1,m2,S,T;
namespace hs{
	const int B=10007,M=1000020221;
	int b[N];
	inline void ini(){
		b[0]=1;
		for(int i=1;i<=max(n,m);i++)
		b[i]=b[i-1]*1ll*B%M;
	}
	inline void cal(char*s,int*a){
		int ln=strlen(s);
		//cerr<<"cal "<<s<<endl;
		for(int i=0;i<ln;i++)
		a[i+1]=(a[i]*1ll*B+s[i]-'a')%M;
		//for(int i=1;i<=ln;i++)
		//cerr<<a[i]<<' ';cerr<<endl;
	}
	inline int get(int*a,int l,int ln){
		return (M+(a[l+ln]-a[l]*1ll*b[ln])%M)%M;
	}
}
inline bool eq(str&a,int l1,str&b,int l2,int ln){
	return hs::get(a.a,l1,ln)==hs::get(b.a,l2,ln);
}//cmp [l,l+ln)
inline void sol(bool d=0){
	for(int i=1;i<=m;i++)
	f1[i]=f2[i]=0;
	//cerr<<"=====\n";
	for(int i=0;;i++){
		f1[0]=f2[0]=1;
		for(int j=0;i+j<=n&&j<<1<=m;j++)
		if(j<<1<m||d&&m>2){
			if(eq(m1,i,S,m-j*2,j)&&eq(m2,i,T,0,j))ans+=f1[m-(j<<1)];
			if(eq(m2,i,S,m-j*2,j)&&eq(m1,i,T,0,j))ans+=f2[m-(j<<1)];
		}
		//for(int j=0;j<=m;j++)
		//cerr<<f1[j]<<','<<f2[j]<<endl;
		//cerr<<">~< "<<ans<<endl;
		if(i==n)break;
		for(int j=0;j<=m;j++)
		g1[j]=f1[j],g2[j]=f2[j],f1[j]=f2[j]=0;
		for(int j=0;j<m;j++){
			if(m1.s[i]==S.s[j]){
				pls(f1[j+1],g1[j]);
				if(j<m-2&&j&&m2.s[i]==S.s[j+1])
				pls(f2[j+2],g1[j]);
			}
			if(m2.s[i]==S.s[j]){
				pls(f2[j+1],g2[j]);
				if(j<m-2&&j&&m1.s[i]==S.s[j+1])
				pls(f1[j+2],g2[j]);
			}
		}
		for(int j=1;j<=i+1&&j<<1<=m;j++)
		if(j<<1<m||d){
			pls(f1[j<<1],eq(m2,i-j+1,T,m-j,j)&&eq(m1,i-j+1,S,j,j));
			pls(f2[j<<1],eq(m1,i-j+1,T,m-j,j)&&eq(m2,i-j+1,S,j,j));
		}
	}
}
int main(){
//	freopen("dat.txt","r",stdin);
	scanf("%s%s%s",m1.s,m2.s,S.s);
	n=strlen(m1.s),m=strlen(S.s);
	hs::ini();
	//cerr<<"???\n";
	for(int i=0;i<m;i++)T.s[i]=S.s[m-i-1];
	hs::cal(m1.s,m1.a);
	hs::cal(m2.s,m2.a);
	hs::cal(S.s,S.a);
	hs::cal(T.s,T.a);
	sol();
	if(m>1)swap(S,T),sol(1);
	printf("%d",(ans%M+M)%M);
	cerr<<clock()<<endl;
}