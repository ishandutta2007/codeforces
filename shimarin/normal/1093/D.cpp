#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define cross(i,k) for (register int i=first[k];i;i=last[i])
#define int ll
using namespace std;
typedef long long ll;
inline ll read(){
    ll x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=-1;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
const int N = 3e5+10,MOD = 998244353;
inline void upd(int &a,int b){a=a*b%MOD;}
int tot=0,to[2*N],last[2*N],first[2*N];
inline void add(int a,int b){to[++tot]=b;last[tot]=first[a];first[a]=tot;}
int s[N],ss[2],flag,n,m,ans;
inline int power(int a,int b){
	int ans=1,y=a;
	for(;b;b>>=1,y=y*y%MOD) if (b&1) ans=ans*y%MOD;
	return ans;
}
inline void dfs(int x,int fa){
	ss[s[x]]++;
	cross(k,x) if (to[k]!=fa){
		int v=to[k];
		if (s[v]!=-1){if (s[v]==s[x]) flag=1;} 
			else s[v]=s[x]^1,dfs(v,x);
	}
}
main(){
	int T=read();
	while (T--){
		n=read();m=read();
		tot=0;
		For(i,1,n) first[i]=0,s[i]=-1;
		For(i,1,m){int x=read(),y=read();add(x,y);add(y,x);}
		flag=0,ans=1;
		For(i,1,n)
			if(s[i]==-1){
				ss[0]=ss[1]=0;s[i]=1;dfs(i,0);
				if (flag) break;
					else upd(ans,(power(2,ss[0])+power(2,ss[1]))%MOD);
			}
		if (flag) puts("0");
			else printf("%lld\n",ans);
	}
}