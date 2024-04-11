/*
Contest: Educational Codeforces Round 87
Problem: 1354B
Author: tzc_wk
Time: 2020.5.17
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
int nxt[200005][4],pre[200005][4],lst[4];
char s[200005];
inline void solve(){
	cin>>s+1;
	int n=strlen(s+1);
	fz(i,0,n+1)	fill0(nxt[i]),fill0(pre[i]);
	s[n+1]=s[0]=0;
	fz(i,1,3)	lst[i]=0;
	fz(i,1,n){
		fz(j,1,3)	pre[i][j]=lst[j];
		lst[s[i]-'0']=i;
	}
	fz(i,1,3)	lst[i]=0;
	fd(i,n,1){
		fz(j,1,3)	nxt[i][j]=lst[j];
		lst[s[i]-'0']=i;
	}
//	fz(i,1,n)	fz(j,1,3)	cout<<pre[i][j]<<endl;
	int ans=200005;
	fz(i,1,n){
		if(s[i]=='1'){
			if(pre[i][2]&&nxt[i][3])	ans=min(ans,nxt[i][3]-pre[i][2]+1);
			if(pre[i][3]&&nxt[i][2])	ans=min(ans,nxt[i][2]-pre[i][3]+1);
		}
		if(s[i]=='2'){
			if(pre[i][1]&&nxt[i][3])	ans=min(ans,nxt[i][3]-pre[i][1]+1);
			if(pre[i][3]&&nxt[i][1])	ans=min(ans,nxt[i][1]-pre[i][3]+1);
		}
		if(s[i]=='3'){
			if(pre[i][2]&&nxt[i][1])	ans=min(ans,nxt[i][1]-pre[i][2]+1);
			if(pre[i][1]&&nxt[i][2])	ans=min(ans,nxt[i][2]-pre[i][1]+1);
		}
	}
	if(ans==200005)	puts("0");
	else			cout<<ans<<endl;
}
signed main(){
	int T=read();
	while(T--)	solve();
	return 0;
}