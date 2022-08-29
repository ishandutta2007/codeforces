#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int N=110000;
typedef long long LL;
LL sum[N];bool rev[N];
int l[N],r[N],s[N],fa[N],val[N];int rt;
inline void up(int x){
	s[x]=s[l[x]]+s[r[x]]+1;
	sum[x]=val[x]+sum[l[x]]+sum[r[x]];
}
int build(int L,int R){
	if(R<L)return 0;
	if(L==R){
		val[L]=s[R]=sum[R]=1;
		return L;
	}
	int mid=(L+R)>>1;
	
	val[mid]=1;
	l[mid]=build(L,mid-1);
	r[mid]=build(mid+1,R);
	
	fa[l[mid]]=fa[r[mid]]=mid;
	up(mid);
	return mid;
}	
inline void down(int x){
	if(rev[x]){
		int tmp=l[x];l[x]=r[x];r[x]=tmp;
		rev[l[x]]^=1;rev[r[x]]^=1;
		rev[x]=0;
	}
}
inline void left(int x){
	int y=fa[x];int z=fa[y];
	r[y]=l[x];if(l[x])fa[l[x]]=y;
	if(l[z]==y)l[z]=x;else if(r[z]==y)r[z]=x;fa[x]=z;
	fa[y]=x;l[x]=y;
	up(y);up(x);
}
inline void right(int x){
	int y=fa[x];int z=fa[y];
	l[y]=r[x];if(r[x])fa[r[x]]=y;
	if(l[z]==y)l[z]=x;else if(r[z]==y)r[z]=x;fa[x]=z;
	fa[y]=x;r[x]=y;
	up(y);up(x);
}
int q[N];
inline void splay(int x){
	q[q[0]=1]=x;for(int k=x;fa[k];k=fa[k])q[++q[0]]=fa[k];
	for(int i=q[0];i>=1;i--)down(q[i]);
	while(fa[x]){
		int y=fa[x];int z=fa[y];
		if(!z){
			if(l[y]==x)right(x);else left(x);
		}
		else{
			if(r[z]==y){
				if(r[y]==x)left(y),left(x);
				else right(x),left(x);
			}
			else{
				if(l[y]==x)right(y),right(x);
				else left(x),right(x);
			}
		}
	}
	rt=x;
}
inline int findk(int k){
	int now=rt;
	while(1){
		down(now);
		if(s[l[now]]+1==k)return now;
		if(s[l[now]]+1<k){
			k-=(s[l[now]]+1);
			now=r[now];
		}
		else now=l[now];
	}
}
inline void del(int x){
	int p=findk(x+1);
	splay(p);
	l[rt]=0;
	up(rt);
}
LL get(int R){
	if(R==s[rt])return sum[rt];
	splay(findk(R+1));
	down(rt);
	return sum[l[rt]];
}	
int n,Q;
int main(){
	scanf("%d%d",&n,&Q);
	rt=build(1,n);
	while(Q--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int xx;scanf("%d",&xx);
			if(xx>s[rt]/2){
				xx=s[rt]-xx;
				rev[rt]^=1;
			}
			
			for(int i=1;i<=xx;i++){
				int u=findk(i);
				int v=findk(xx+xx-i+1);
				splay(v);
				val[v]+=val[u];
				up(v);
			}
			
			del(xx);
		}
		else{
			int L,R;scanf("%d%d",&L,&R);L++;
			LL _ans=get(R);
			_ans-=get(L-1);
			printf("%I64d\n",_ans);
		}
	}
	return 0;
}