#include<cstdio>
#include<iostream>
using namespace std;
int n,m,q,t,w,f,g,p,lim,a[1<<25],unlimited,illegal;
inline int qp(int b,int f){int res=1;for(;f;f>>=1,b=b*1ll*b%p) if(f&1) res=res*1ll*b%p;return res;}
inline void update(int dep,int pos,int val){
	int x=a[(2<<dep)+pos],y=a[(3<<dep)+pos],&z=a[(1<<dep)+pos];
	if((t>>dep)&1) if(x<0||y<0||x==y) z=x&y;else z=0,illegal+=val;
	else if(x<0&&y<0) z=-1,unlimited+=val;
	else if(x<0||y<0) z=x|y;
	else z=x^y;
}
inline void set(int pos,int val){for(int i=lim;i--;) update(i,pos&((1<<i)-1),val);}
int main(){
	scanf("%d%d%d%d",&n,&m,&t,&w);t=min(t,n&(-n));lim=__lg(n-1)+1;
	for(int i=0;i<(1<<lim);++i) a[i|(1<<lim)]=(i<n?-1:0);
	for(int i=lim;i--;) for(int j=0;j<(1<<i);++j) update(i,j,1);
	for(int d,e;m--;) scanf("%d%d",&d,&e),set(--d,-1),a[(1<<lim)+d]=e,set(d,1);
	for(scanf("%d",&q);q--;printf("%d\n",illegal?0:qp(2,w*(unlimited+(a[1]==-1)))))
		scanf("%d%d%d",&f,&g,&p),set(--f,-1),a[(1<<lim)+f]=g,set(f,1);
	return 0;
}