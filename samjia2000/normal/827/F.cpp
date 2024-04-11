#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 5e5+5;
const int INF = 1.05e9;

int n,m;
int lef[N],rig[N],u;
struct EDGE{
	int x,l,r;
	EDGE(const int x_=0,const int l_=0,const int r_=0){x=x_;l=l_;r=r_;}
	friend bool operator <(EDGE a,EDGE b){
		if (a.l!=b.l)return a.l<b.l;
		if (a.x!=b.x)return a.x<b.x;
		return a.r<b.r;
	}
};
set<EDGE>to[N];
int lv[N*2][2];
struct edge{
	int x,r,nxt;
}e[N*4];
int h[N*2],tot;

void inse(int x,int y,int r){e[++tot].x=y;e[tot].r=r;e[tot].nxt=h[x];h[x]=tot;}

struct node{
	int l,r,minv[2];
	int ad[2],val[2],w[2];
}tree[N*4];
int rt,nt;
int dis[N*2][2];
int len;

void update(int now){
	int l=tree[now].l,r=tree[now].r;
	fo(c,0,1){
		tree[now].minv[c]=min(tree[l].minv[c],tree[r].minv[c]);
		if (tree[l].val[c]<tree[r].val[c])tree[now].val[c]=tree[l].val[c],tree[now].w[c]=tree[l].w[c];
		else tree[now].val[c]=tree[r].val[c],tree[now].w[c]=tree[r].w[c];
	}
}

void build(int &now,int l,int r){
	now=++nt;
	tree[now].ad[0]=tree[now].ad[1]=INF;
	if (l==r){
		tree[now].minv[0]=lv[l][0];
		tree[now].minv[1]=lv[l][1];
		tree[now].val[0]=dis[l][0];tree[now].val[1]=INF;
		tree[now].w[0]=tree[now].w[1]=l;
		return;
	}
	int mid=(l+r)/2;
	build(tree[now].l,l,mid);
	build(tree[now].r,mid+1,r);
	update(now);
}

bool bz[N*2][2];

void down(int now){
	int l=tree[now].l,r=tree[now].r;
	fo(c,0,1)
	if (tree[now].ad[c]!=INF){
		int ad=tree[now].ad[c];
		if (ad<tree[l].ad[c]){
			tree[l].ad[c]=ad;
			tree[l].val[c]=min(tree[l].val[c],max(tree[l].minv[c],ad));
		}
		if (ad<tree[r].ad[c]){
			tree[r].ad[c]=ad;
			tree[r].val[c]=min(tree[r].val[c],max(tree[r].minv[c],ad));
		}
		tree[now].ad[c]=INF;
	}
}

void clear(int now,int l,int r,int x,int c){
	if (l==r){
		bz[x][c]=1;
		dis[x][c]=tree[now].val[c];
		tree[now].val[c]=INF;
		tree[now].minv[c]=INF;
		return;
	}
	down(now);
	int mid=(l+r)/2;
	if (x<=mid)clear(tree[now].l,l,mid,x,c);
	else clear(tree[now].r,mid+1,r,x,c);
	update(now);
}

void change(int now,int l,int r,int x,int y,int v,int c){
	if (x<=l&&r<=y){
		if (v<tree[now].ad[c]){
			tree[now].ad[c]=v;
			tree[now].val[c]=min(tree[now].val[c],max(tree[now].minv[c],v));
		}
		return;
	}
	down(now);
	int mid=(l+r)/2;
	if (x<=mid)change(tree[now].l,l,mid,x,y,v,c);
	if (y>mid)change(tree[now].r,mid+1,r,x,y,v,c);
	update(now);
}

void dijsktra(){
	while(min(tree[1].val[0],tree[1].val[1])<INF){
		int c=0;
		if (tree[1].val[1]<tree[1].val[0])c=1;
		int x=tree[1].w[c];
		clear(1,1,len,x,c);
		for(int p=h[x];p;p=e[p].nxt)
		if (e[p].r>dis[x][c]){
			int r=dis[x][c]+1+(e[p].r-dis[x][c]-1)/2*2;
			int y=e[p].x;
			if(lef[y]<=rig[y]&&lv[lef[y]][c^1]<=r){
				int w=lef[y],LEFT=lef[y],RIGHT=rig[y];
				while(LEFT<=RIGHT){
					int mid=(LEFT+RIGHT)/2;
					if (lv[mid][c^1]<=r)w=mid,LEFT=mid+1;
					else RIGHT=mid-1;
				}
				change(1,1,len,lef[y],w,dis[x][c]+1,c^1);
			}
		}
	}
}

int main(){
	n=get();m=get();
	fo(i,1,m){
		int x=get(),y=get(),l=get(),r=get();
		to[x].insert(EDGE(y,l,r));
		to[y].insert(EDGE(x,l,r));
	}
	if (n==1)return printf("0\n"),0;
	len=0;
	fo(i,1,n){
		lef[i]=len+1;
		if(i==n){
			len++;
			lv[len][0]=0;lv[len][1]=1;
			dis[len][0]=dis[len][1]=INF;
		}
		for(set<EDGE>::iterator h=to[i].begin();h!=to[i].end();h++){
			len++;
			lv[len][0]=lv[len][1]=(*h).l;
			if (lv[len][0]&1)lv[len][0]++;
			else lv[len][1]++;
			dis[len][0]=dis[len][1]=INF;
			if (i==1&&lv[len][0]==0)dis[len][0]=0;
			inse(len,(*h).x,(*h).r);
		}
		rig[i]=len;
	}
	build(rt,1,len);
	dijsktra();
	int ans=INF;
	fo(i,1,len)
		fo(c,0,1)
		if (!bz[i][c])clear(1,1,len,i,c);
	fo(i,lef[n],rig[n])ans=min(ans,min(dis[i][0],dis[i][1]));
	if (ans==INF)ans=-1;
	cout<<ans<<endl;
	return 0;
}