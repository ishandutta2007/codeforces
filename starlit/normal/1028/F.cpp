#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200005;
typedef pair<int,int> pi;
int n,ct,q,op,x,y,d,ne[N],xx[N],yy[N];
ll now;
inline int gcd(int x,int y){
	for(;y;swap(x,y),y=y%x);
	return x;
}
unordered_map<ll,int>P,L;
void ins(int x,int xx,int y,int yy,int v){
	if(x!=xx||y!=yy)v*=2;
	x+=xx,y+=yy;
	register int k=gcd(x,y);
	L[x/k*N+y/k]+=v;
}
int main(){
	for(scanf("%d",&q);q--;){
		scanf("%d%d%d",&op,&x,&y);
		now=1ll*x*x+1ll*y*y;
		if(op>2){
			d=gcd(x,y);
			printf("%d\n",n-L[x/d*N+y/d]);
		}
		else if(op&1){
			n++,d=P[now];
			if(!d)d=P[now]=++ct;
			ne[++ct]=ne[d],ne[d]=ct,xx[ct]=x,yy[ct]=y;
			for(int i=ct;i;i=ne[i])
			ins(xx[i],x,yy[i],y,1);
		}
		else{
			n--,d=P[now];
			for(int i=ne[d];i;i=ne[i])
			ins(xx[i],x,yy[i],y,-1);
			for(int i=d;;i=ne[i])
			if(xx[ne[i]]==x&&yy[ne[i]]==y){
				ne[i]=ne[ne[i]];break;
			}
		}
	}
}