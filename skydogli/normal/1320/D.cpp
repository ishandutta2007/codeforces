#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define LL long long
#define mp make_pair
#define fir first
#define sec second
#define pii pair<int,int>
inline void chkmax(int &a,int b){if(a<b)a=b;}
inline void chkmin(int &a,int b){if(a>b)a=b;}
inline int read(){
	   int a=0,fh=1;char c=getchar();
	   while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	   while('0'<=c&&c<='9'){
		   a=a*10+c-48;
		   c=getchar();
	   }
	   return a*fh;
}
#define Mod 998244353
LL pw[MN],h1[MN],h2[MN];
int n,sum[MN];
char ch[MN];
int ask(int l,int r){
	int L=sum[l-1],R=sum[r];
	if(l&1) return (h1[R]-h1[L]*pw[R-L]%Mod+Mod)%Mod;
	else return (h2[R]-h2[L]*pw[R-L]%Mod+Mod)%Mod;
}
int main(){
	n=read();
	scanf("%s",ch+1);
	pw[0]=1;for(int i=1;i<=n;++i)pw[i]=pw[i-1]*3ll%Mod;
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1];
		if(ch[i]=='0'){
			sum[i]++;
			int p=sum[i];
			h1[p]=h1[p-1]*3ll%Mod;
			h2[p]=h2[p-1]*3ll%Mod;
			(h1[p]+=(1+(i&1)))%=Mod;
			(h2[p]+=(1+(!(i&1))))%=Mod;
		}
	}
	int q=read();
	while(q--){
		int l=read(),r=read(),len=read();
	//	cerr<<"? "<<l<<": "<<ask(l,l+len-1)<<endl;
	//	cerr<<"? "<<r<<": "<<ask(r,r+len-1)<<endl;
		puts((ask(l,l+len-1)==ask(r,r+len-1))?"Yes":"No");
	}
	return 0;
}