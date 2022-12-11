#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 205;

int n,d,mo;
LL f[N],g[N][N],h[N][N],t[N];

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}

LL c[N][N];

int main(){
	n=get();d=get();mo=get();
	c[0][0]=1;
	fo(i,1,n){
		c[i][0]=1;
		fo(j,1,i)c[i][j]=add(c[i-1][j-1],c[i-1][j]);
	}
	g[0][0]=1;
	fo(i,1,n){
		fo(x,0,d)f[i]=add(f[i],g[x][i-1]);
		t[i]=dec(f[i],g[d][i-1]);
		fo(x,1,d){
			//g[x][i]
			fo(s,1,i)
			if (g[x-1][i-s])g[x][i]=(g[x][i]+g[x-1][i-s]*c[i-1][s-1]%mo*t[s]%mo)%mo;
		}
	}
	LL ans1=0,ans2=0;
	fo(d1,0,d)
		fo(d2,0,d-d1)
			fo(i,0,n-1)
			ans1=(ans1+g[d1][i]*g[d2][n-1-i])%mo;
	fo(i,1,n-1)ans2=(ans2+t[i]*t[n-i])%mo;
	LL ans=dec(ans1,ans2)*(n*(n-1)*2)%mo;
	cout<<ans<<endl;
	return 0;
}