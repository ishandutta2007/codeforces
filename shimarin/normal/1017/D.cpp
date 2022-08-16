#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define cross(i,u) for (register int i=first[u];i;i=last[i])
using namespace std;
typedef long long ll;
inline ll read(){
    ll x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=-1;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
const int N=5e5+10;
int n,Q,m,p[5010],ans[110],A[15],K[5010];
int Ans[N];
struct node{int x,y,p;}a[N];
inline bool cmp(node a,node b){return a.x==b.x?a.y<b.y:a.x<b.x;}
char s[N][15],t[N];
inline void solve(int i){
	memset(ans,0,sizeof ans);
	int I=a[i].x;
	for(int j=0;j<(1<<n);j++){
		int pp=(I^j)^((1<<n)-1);
		if (K[pp]<=100) ans[K[pp]]+=p[j];
	}
	For(j,1,100) ans[j]+=ans[j-1];
}
int main(){
	n=read();Q=read();m=read();
	For(i,1,n) A[i]=read();
	for(int i=0;i<(1<<n);i++){
		int tmp=0;
		For(j,0,n-1) if(i&(1<<(n-j-1)))tmp+=A[j+1];
		K[i]=tmp;
	}
	For(i,1,Q){
		scanf("%s",s[i]+1);int Tmp=0;
		For(j,1,n) Tmp=Tmp*2+s[i][j]-'0';
		p[Tmp]++;
	}
	For(i,1,m){
		scanf("%s",t+1);int Tmp=0;
		For(j,1,n) Tmp=Tmp*2+t[j]-'0';
		a[i]=(node){Tmp,read(),i};
	}
	sort(a+1,a+m+1,cmp),a[0].x=-1;
	For(i,1,m){
		if (a[i].x!=a[i-1].x) solve(i);
		Ans[a[i].p]=ans[a[i].y];
	}
	For(i,1,m) printf("%d\n",Ans[i]);
}