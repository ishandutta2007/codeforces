#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
struct node{
	int v[4][4];
	node(){
		memset(v,0x15,sizeof(v));
	}
}tr[400010],pr[4];
int n,q;
char str[100010];
node merge(node A,node B){
	node res;
	for(int i=0;i<=3;++i){
		for(int j=i;j<=3;++j){
			for(int k=j;k<=3;++k){
				res.v[i][k]=min(res.v[i][k],A.v[i][j]+B.v[j][k]);
			}
		}
	}
	return res;
}
void pushup(int p){
	tr[p]=merge(tr[p<<1],tr[p<<1|1]);
}
void build(int p,int l,int r){
	if(l==r){
		tr[p]=pr[str[l]-'a'+1];return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);
	pushup(p);
}
void update(int p,int l,int r,int pos,int k){
	if(l==r){
		tr[p]=pr[k];return ;
	}
	int mid=l+r>>1;
	if(pos<=mid) update(p<<1,l,mid,pos,k);else update(p<<1|1,mid+1,r,pos,k);
	pushup(p);
}
void print(){
	int ans=0x7f7f7f7f;
	// for(int i=0;i<3;++i) {for(int j=0;j<=3;++j) printf("%d ",tr[1].v[i][j]);printf("\n");}
	for(int i=0;i<3;++i) ans=min(ans,tr[1].v[0][i]);
	printf("%d\n",ans);
}
int main(){
	n=read(),q=read();
	scanf("%s",str+1);
	pr[1].v[0][0]=1;pr[1].v[2][2]=pr[1].v[3][3]=0;
	pr[1].v[0][1]=pr[1].v[1][1]=0;
	pr[2].v[1][1]=1;pr[2].v[0][0]=pr[2].v[3][3]=0;
	pr[2].v[2][2]=pr[2].v[1][2]=0;
	pr[3].v[2][2]=1;pr[3].v[3][3]=pr[3].v[2][3]=0;pr[3].v[0][0]=pr[3].v[1][1]=0;
	build(1,1,n);
	while(q--){
		int x=read();char c=getchar();
		while(c<'a'||c>'c') c=getchar();
		update(1,1,n,x,c-'a'+1);print();
	}
}