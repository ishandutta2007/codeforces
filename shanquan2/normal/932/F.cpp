#include<bits/stdc++.h>
using namespace std;

struct pnt{
	long long x,y;
	long long operator *(const pnt &o)const{
		double t=1.0*x*o.y-1.0*y*o.x;
		if(t>1e18)return 1;
		if(t<-1e18)return -1;
		return x*o.y-y*o.x;
	}
	pnt operator -(const pnt &o)const{
		return (pnt){x-o.x,y-o.y};
	}
	bool operator <(const pnt &o)const{
		return x<o.x || x==o.x && y<o.y;
	}
};
set<pnt> s[100005];
struct edge{
	int nxt,to;
}e[200005];
int n,a[100005],b[100005],siz[100005],pos[100005],ft[100005];
long long f[100005];
void insert(int id,pnt p){
	if(s[id].size()<2){
		s[id].insert(p);
		return;
	}
	set<pnt>::iterator r=s[id].lower_bound(p),l=r,q;
	if(r!=s[id].end()&&!((*r<p)||(p<*r)))return;
	if(l!=s[id].begin()){
		l--;
		if(r!=s[id].end()&&(*r-*l)*(p-*l)>0)return;
		s[id].insert(p);
		q=l;
		while(l!=s[id].begin()){
			q--;
			if((*l-p)*(*q-p)<0)break;
			s[id].erase(l);
			l=q;
		}
	}
	if(r!=s[id].end()){
		q=r++;
		while(r!=s[id].end()){
			if((*r-p)*(*q-p)<0)break;
			s[id].erase(q);
			q=r++;
		}
	}
}
void merge(int x,int y){
	for(auto p:s[y])insert(x,p);
}
const int M=100005;
const long long inf=1e18;
bool check(int p,int x,long long k){
	set<pnt> &S=s[p];
//	for(set<pnt>::iterator it=S.begin();it!=S.end();it++)printf("%lld %lld  ",it->x,it->y);printf("\n");
	set<pnt>::iterator it=S.lower_bound((pnt){x,inf}),l=it,r=it;
	r++;
	if(r==S.end())return 0;
	l--;
	if(l==S.begin())return 1;
//	printf("%lld %lld %lld %lld\n",l->x,l->y,it->x,it->y);
	if((l->y-it->y)>k*(it->x-l->x))return 1;else return 0;
}
long long calc(int p,int x,long long k){
	set<pnt>::iterator it=s[p].lower_bound((pnt){x,-inf}),r=it;r++;
	if(r==s[p].end())return 0;
	return it->y+it->x*k;
}
long long query(int p,long long k){
//	for(set<pnt>::iterator it=s[p].begin();it!=s[p].end();it++)printf("%lld %lld  ",it->x,it->y);printf("\n");
	int h=-M,t=M;
	while(h<t){
		int x=h+t>>1;
		if(check(p,x,k))h=x+1;else t=x;
	}
	return calc(p,h,k);
}
void dfs(int x,int fa){
	siz[x]=0;pos[x]=x;
	for(int i=ft[x];i;i=e[i].nxt)if(e[i].to!=fa){
		int u=e[i].to;
		dfs(u,x);
		if(siz[u]>siz[x])swap(pos[x],pos[u]);
		merge(pos[x],pos[u]);
		siz[x]+=siz[u];
	}
	f[x]=query(pos[x],a[x]);
	insert(pos[x],(pnt){b[x],f[x]});
	siz[x]++;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		s[i].insert((pnt){-M,inf});
		s[i].insert((pnt){M,inf});
	}
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		e[i<<1]=(edge){ft[x],y};ft[x]=i<<1;
		e[i<<1|1]=(edge){ft[y],x};ft[y]=i<<1|1;
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)printf("%I64d ",f[i]);printf("\n");
	return 0;
}