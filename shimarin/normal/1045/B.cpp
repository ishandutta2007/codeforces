#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define cross(i,u) for (register int i=first[u];i;i=last[i])
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read(){
    ll x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=-1;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
const int N = 2e5+10;
int n,m,a[N],b[N];
vector<int>ans;
const ull base = 233;
ull p[N],hashl[N],hashr[N];
inline void init(){
	p[0]=1;
	For(i,1,n) p[i]=p[i-1]*base;
	For(i,1,n-1) hashl[i]=hashl[i-1]*base+(ull)b[i];
	Dow(i,n-1,1) hashr[i]=hashr[i+1]*base+(ull)b[i];
}
inline ull Queryl(int l,int r){return hashl[r]-hashl[l-1]*p[r-l+1];}
inline ull Queryr(int l,int r){return hashr[l]-hashr[r+1]*p[r-l+1];}
inline bool check(int l,int r){return Queryl(l,r)==Queryr(l,r);}
int main(){
	n=read(),m=read();
	For(i,1,n) a[i]=read();
	For(i,1,n-1) b[i]=a[i+1]-a[i];
	init();
	For(i,1,n){
		bool flag=1;
		if (i!=1) flag&=check(1,i-1);
		if (i!=n){
			flag&=(a[1]+a[i]+m==a[i+1]+a[n]);
			if (i!=n-1) flag&=check(i+1,n-1);
		}
		if (flag) ans.push_back((a[1]+a[i])%m); 
	}
	printf("%d\n",ans.size()),sort(ans.begin(),ans.end());
	if (!ans.empty()) For(i,0,ans.size()-1) printf("%d ",ans[i]);
}