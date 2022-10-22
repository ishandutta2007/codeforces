/*
Contest: Codeforces Round #643
Problem: Codeforces 1355E
Author: tzc_wk
Time: 2020.5.16
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y1010101010101
#define y0			y0101010101010
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),a=read(),b=read(),c=read(),pre[100005],suf[100005],x[100005];
inline int find(int less,int more){
	if(less<0||more<0)	return 1ll<<60;
//	cout<<less<<" "<<more<<" "<<less*a+more*b-(((a+b-c)>0)?((a+b-c)*min(less,more)):0)<<endl;
	return less*a+more*b-(((a+b-c)>0)?((a+b-c)*min(less,more)):0);
}
signed main(){
	fz(i,1,n)	x[i]=read();
	sort(x+1,x+n+1);
	fz(i,1,n)	pre[i]=pre[i-1]+x[i];
	fd(i,n,1)	suf[i]=suf[i+1]+x[i];
	int ans=1ll<<60;
	fz(i,1,n){
		int more=suf[i]-x[i]*(n-i+1);
		int less=x[i]*(i-1)-pre[i-1];
//		cout<<less<<" "<<more<<endl;
//		if(less<more){
			ans=min(ans,find(less,more));
//		}
		if(less>=more){
			int t=(less-more)/n;
			less=less-(i-1)*t;
			more=more+(n-i+1)*t;
			if(t>=0&&t<=x[i]-x[i-1])	ans=min(ans,find(less,more));
			less=less-(i-1);
			more=more+(n-i+1);
			if(t+1>=0&&t+1<=x[i]-x[i-1])	ans=min(ans,find(less,more));
			less=less+(i-1)*2;
			more=more-(n-i+1)*2;
			if(t-1>=0&&t-1<=x[i]-x[i-1])	ans=min(ans,find(less,more));
		}
//		cout<<less<<" "<<more<<" "<<a+b-c<<endl;
//		cout<<(less*a+more*b-(((less+more-c)>0)?((less+more-c)*min(less,more)):0))<<endl;
//		ans=min(ans,less*a+more*b-(((a+b-c)>0)?((a+b-c)*min(less,more)):0));
	}
	cout<<ans<<endl;
	return 0;
}
/*x[i-1]+1~x[i]*/
/*h-1 -> less-(i-1),more+(n-i+1)*/
/*less*a+more*b-(a+b-c)*i*/
/*
less-(i-1)*t=more+(n-i+1)*t
less-more=n*t
t=(less-more)/n;
*/