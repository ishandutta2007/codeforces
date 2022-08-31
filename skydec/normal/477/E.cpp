#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
inline void read(int &x){
	x=0;char p=getchar();
	while(!(p<='9'&&p>='0'))p=getchar();
	while(p<='9'&&p>='0')x*=10,x+=p-48,p=getchar();
}
const int N=410000;
inline int MIN(const int &a,const int &b){if(a<b)return a;return b;}
struct info{
	int Max,Min,v1,v2;
	int b1,b2;
}mes[N*4];
int lazy[N*4];int ans[N];
inline info operator +(const info &a,const info &b){
	info c;c=a;
	if(b.Min<c.Min)c.Min=b.Min;
	if(b.Max>c.Max)c.Max=b.Max;
	if(b.v1<c.v1){c.v1=b.v1;c.b1=b.b1;}
	if(b.v2<c.v2){c.v2=b.v2;c.b2=b.b2;}
	return c;
}
inline void tag(int me,int v){
	mes[me].Max+=v;mes[me].Min+=v;
	mes[me].v1+=v;mes[me].v2-=v;
	lazy[me]+=v;
}
inline void down(int me){
	if(lazy[me]==0)return;
	tag(me*2,lazy[me]);
	tag(me*2+1,lazy[me]);
	lazy[me]=0;
}
void add(int me,int l,int r,int x,int y,int v){
	if(l^r)down(me);
	if(x<=l&&r<=y){tag(me,v);return;}
	int mid=(l+r)>>1;
	if(x<=mid)add(me*2,l,mid,x,y,v);
	if(y>mid)add(me*2+1,mid+1,r,x,y,v);
	mes[me]=mes[me*2]+mes[me*2+1];
}
info res;
void getup(int me,int l,int r,int x,int y,int d){
	if(l^r)down(me);
	if(mes[me].Max<d)return;
	if(x<=l&&r<=y){
		if(mes[me].Min>=d){res=res+mes[me];return;}
		int mid=(l+r)>>1;
		getup(me*2,l,mid,x,y,d);
		getup(me*2+1,mid+1,r,x,y,d);
	}
	else{
		int mid=(l+r)>>1;
		if(x<=mid)getup(me*2,l,mid,x,y,d);
		if(y>mid)getup(me*2+1,mid+1,r,x,y,d);
	}
}
void getdown(int me,int l,int r,int x,int y,int d){
	if(l^r)down(me);
	if(mes[me].Min>d)return;
	if(x<=l&&r<=y){
		if(mes[me].Max<=d){res=res+mes[me];return;}
		int mid=(l+r)>>1;
		getdown(me*2,l,mid,x,y,d);
		getdown(me*2+1,mid+1,r,x,y,d);
	}
	else{
		int mid=(l+r)>>1;
		if(x<=mid)getdown(me*2,l,mid,x,y,d);
		if(y>mid)getdown(me*2+1,mid+1,r,x,y,d);
	}
}
void build(int me,int l,int r,int mu){
	lazy[me]=0;
	if(l==r){
		mes[me].Max=mes[me].Min=0;
		mes[me].v1=mes[me].v2=2*l*mu;
		mes[me].b1=mes[me].b2=l;
		return;
	}
	int mid=(l+r)>>1;
	build(me*2,l,mid,mu);
	build(me*2+1,mid+1,r,mu);
	mes[me]=mes[me*2]+mes[me*2+1];
}
int n,q;
struct seg{
	int l,r,val;
};
seg stack[N];int top;int a[N];
int r1[N],r2[N],c1[N],c2[N];
vector<int>Q[N];
int f[20][410000];
int bit[410000];
inline int ask(const int &l,const int &r){
	if(l==r)return a[l];
	if(l>r)return 233333333;
	return MIN(f[bit[r-l+1]-1][l],f[bit[r-l+1]-1][r-(1<<(bit[r-l+1]-1))+1]);
}
inline void Go(){
	rep(i,1,n)Q[i].clear();top=0;
	build(1,1,n,-1);
	
	rep(i,1,n)f[0][i]=a[i];
	rep(j,1,19)rep(i,1,n){
		f[j][i]=f[j-1][i];
		if(i+(1<<(j-1))<=n)f[j][i]=MIN(f[j-1][i+(1<<(j-1))],f[j][i]);
	}
	rep(i,1,n)bit[i]=bit[i/2]+1;
	
	
	rep(i,1,q)if(r2[i]>=r1[i]){
		Q[r2[i]].pb(i);
		ans[i]=MIN(ans[i],r2[i]-r1[i]+abs(MIN(ask(r1[i]+1,r2[i]),c1[i])-c2[i]));
	}
	
	rep(i,1,n){
		while(top&&stack[top].val>=a[i]){
			add(1,1,n,stack[top].l,stack[top].r,-stack[top].val);top--;
		}
		if(!top)stack[top=1]=(seg){1,i,a[i]};
		else{
			stack[top+1]=(seg){stack[top].r+1,i,a[i]};top++;
		}
		add(1,1,n,stack[top].l,stack[top].r,stack[top].val);
		
		rep(j,0,Q[i].size()-1){
			int x=Q[i][j];
			res.Max=-233333333;res.Min=233333333;res.v1=res.v2=233333333;
			getup(1,1,n,r1[x],i,c2[x]);
			ans[x]=MIN(ans[x],res.Min-c2[x]+i-r1[x]+1);
			
			
			res.Max=-233333333;res.Min=233333333;res.v1=res.v2=233333333;
			getdown(1,1,n,r1[x],i,c2[x]);
			ans[x]=MIN(ans[x],c2[x]-res.Max+i-r1[x]+1);
			
			
			res.Max=-233333333;res.Min=233333333;res.v1=res.v2=233333333;
			getup(1,1,n,1,r1[x],c2[x]);
			ans[x]=MIN(ans[x],2*r1[x]+r2[x]-r1[x]-c2[x]+res.v1+(a[res.b1]>ask(res.b1,i)||a[res.b1]>c1[x]));
			
			
			res.Max=-233333333;res.Min=233333333;res.v1=res.v2=233333333;
			getdown(1,1,n,1,r1[x],c2[x]);
			ans[x]=MIN(ans[x],2*r1[x]+r2[x]-r1[x]+c2[x]+res.v2+(a[res.b2]>ask(res.b2,i)||a[res.b2]>c1[x]));
		}
	}
	build(1,1,n,1);top=0;
	per(i,n,1){
		while(top&&a[i]<=stack[top].val){
			add(1,1,n,stack[top].l,stack[top].r,-stack[top].val);top--;
		}
		if(!top){
			stack[top=1]=(seg){i,n,a[i]};
		}
		else{
			stack[top+1]=(seg){i,stack[top].l-1,a[i]};top++;
		}
		add(1,1,n,stack[top].l,stack[top].r,stack[top].val);
		rep(j,0,Q[i].size()-1){
			int x=Q[i][j];
			
			res.Max=-233333333;res.Min=233333333;res.v1=res.v2=233333333;
			getup(1,1,n,i,n,c2[x]);
			ans[x]=MIN(ans[x],(a[res.b1]>ask(r1[x],res.b1)||a[res.b1]>c1[x])-2*r2[x]+r2[x]-r1[x]+res.v1-c2[x]);
			
			res.Max=-233333333;res.Min=233333333;res.v1=res.v2=233333333;
			getdown(1,1,n,i,n,c2[x]);
			ans[x]=MIN(ans[x],(a[res.b2]>ask(r1[x],res.b2)||a[res.b2]>c1[x])-2*r2[x]+r2[x]-r1[x]+res.v2+c2[x]);
		}
	}
}
inline void RevIt(){
	rep(i,1,n/2)swap(a[i],a[n+1-i]);
	rep(i,1,q){r1[i]=n+1-r1[i];r2[i]=n+1-r2[i];}
}
inline void work(){
	Go();RevIt();Go();
}
int main(){
	read(n);
	rep(i,1,n)read(a[i]);
	read(q);
	rep(i,1,q){
		read(r1[i]);read(c1[i]);read(r2[i]);read(c2[i]);
		ans[i]=1+c2[i]+abs(r2[i]-r1[i]);
	}
	work();
	rep(i,1,q)printf("%d\n",ans[i]);
	return 0;
}