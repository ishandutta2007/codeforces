#include<bits/stdc++.h>
const int N=100005;
using namespace std;
int n,q,now,op[N],qx[N],qy[N],ln[N],
ans[N],b[3][N],t,tx,ty;
struct opt{
	int no,x,y,v;
}a[N*3];
inline void add(int no,int x){
	a[t++]={no,x,tx,1},a[t++]={no,x,ty,-1};
	swap(tx,ty);
}
inline void ins(int no,int x,int v){
	for(;x;x-=x&-x)b[no][x]+=v;
}
inline int qry(int no,int x){
	int y=0;
	for(;x<=n*2;x+=x&-x)
	y+=b[no][x];
	return y;
}
int cnt;
bool cmp(opt a,opt b){
	return a.y==b.y?abs(a.v)>abs(b.v):a.y<b.y;
}
inline void sol(int l,int r){
	if(l==r)return;
	int mi=l+r>>1;
	t=0;
	for(int i=l;i<=mi;i++)
	if(op[i]){
		if(op[i]&1)tx=qy[i],ty=qy[i]+ln[i]+1;
		else tx=qy[i]-ln[i],ty=qy[i]+1;
		if(op[i]==1)
		add(2,qx[i]+qy[i]+ln[i]),add(0,qx[i]-1);
		if(op[i]==2)
		add(1,qx[i]+ln[i]-qy[i]+n),add(0,qx[i]-1);
		if(op[i]==3)
		add(0,qx[i]),add(1,qx[i]-ln[i]-qy[i]-1+n);
		if(op[i]==4)
		add(0,qx[i]),add(2,qx[i]+qy[i]-ln[i]-1);

	}
	for(int i=mi+1;i<=r;i++)
	if(!op[i])a[t++]={i,qx[i],qy[i],0};
	sort(a,a+t,cmp);
	for(int i=0;i<t;i++)
	if(a[i].v)ins(a[i].no,a[i].x,a[i].v);
	else ans[a[i].no]+=qry(0,a[i].x)+qry(1,a[i].x-a[i].y+n)+qry(2,a[i].x+a[i].y);
	for(int i=0;i<t;i++)
	if(a[i].v)ins(a[i].no,a[i].x,-a[i].v);
	sol(l,mi),sol(mi+1,r);
}
int main(){
	//freopen("dat.txt","r",stdin);
	//freopen("me.txt","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&now);
		if(now<2)
		scanf("%d%d%d%d",op+i,qx+i,qy+i,ln+i);
		else scanf("%d%d",qx+i,qy+i);
	}
	sol(1,q);
	for(int i=1;i<=q;i++)
	if(!op[i])printf("%d\n",ans[i]);
}