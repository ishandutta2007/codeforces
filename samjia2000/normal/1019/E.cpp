#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

const int BufferSize=1e7;
char buffer[BufferSize],*head,*tail;
inline char Getchar() {
    if(head==tail) {
        int l=fread(buffer,1,BufferSize,stdin);
        tail=(head=buffer)+l;
    }
    return *head++;
}
inline LL get() {
    LL x=0,f=1;char c=Getchar();
    for(;!isdigit(c);c=Getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=Getchar()) x=x*10+c-'0';
    return x*f;
}

const int N = 2e5+5;

int n,m;
struct point{
	LL x,y;
	point(const LL x_=0,const LL y_=0){x=x_;y=y_;}
	friend bool operator <(point a,point b){return a.x==b.x?a.y>b.y:a.x<b.x;}
};
point operator +(point a,point b){return point(a.x+b.x,a.y+b.y);}
point operator -(point a,point b){return point(a.x-b.x,a.y-b.y);}
LL cross(point a,point b,point c){
	LL tmp=(b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
	db val=db(1)*(b.x-a.x)*(c.y-a.y)-db(1)*(c.x-a.x)*(b.y-a.y);
	if (fabs(val)<1e18)return tmp;
	return val>0?1:-1;
}

bool cmp0(point a,point b){
	LL tmp=a.x*b.y-a.y*b.x;
	db val=db(1)*a.x*b.y-db(1)*a.y*b.x;
	if (fabs(val)<1e18)return tmp<0;
	return val<0;
}
struct edge{
	int x,nxt;
	point ad;
}e[N*2],e1[N*2];
int h[N],tot,h1[N],tot1;
int n1;

void inse1(int x,int y,point ad){e1[++tot1].x=y;e1[tot1].ad=ad;e1[tot1].nxt=h1[x];h1[x]=tot1;}
void inse(int x,int y,point ad){e[++tot].x=y;e[tot].ad=ad;e[tot].nxt=h[x];h[x]=tot;}

int depth[N],Fa[N];
int que[N],fa[N],siz[N],mx[N];
int vis[N],tim;
int height;

void getnew(int x){
	vis[x]=tim;
	int lst=0;
	for(int p=h1[x];p;p=e1[p].nxt)
	if (vis[e1[p].x]<tim){
		int y=e1[p].x,tmp=++n1;
		inse(tmp,y,e1[p].ad);
		inse(y,tmp,e1[p].ad);
		if (!lst){
			inse(x,tmp,point(0,0));
			inse(tmp,x,point(0,0));
		}
		else{
			inse(lst,tmp,point(0,0));
			inse(tmp,lst,point(0,0));
		}
		lst=tmp;
		getnew(y);
	}
}

void getheight(int st){
	tim++;
	int he=0,ta=1;
	vis[que[1]=st]=1;
	fa[st]=0;
	for(;he<ta;){
		int x=que[++he];
		siz[x]=1,mx[x]=0;
		for(int p=h[x];p;p=e[p].nxt)
		if (!depth[e[p].x]&&vis[e[p].x]<tim){
			fa[e[p].x]=x;
			vis[que[++ta]=e[p].x]=tim;
		}
	}
	height=0;
	fd(i,ta,1){
		int x=que[i];
		if (fa[x])siz[fa[x]]+=siz[x],mx[fa[x]]=max(mx[fa[x]],siz[x]);
		mx[x]=max(mx[x],ta-siz[x]);
		if(!height||mx[x]<mx[height])height=x;
	}
}

int build(int up,int D){
	getheight(up);
	int x=height;
	depth[x]=D;
	for(int p=h[x];p;p=e[p].nxt)
	if (!depth[e[p].x])Fa[build(e[p].x,D+1)]=x;
	return x;
}

int num[N];

bool cmp(int x,int y){return depth[x]<depth[y];}

point c0[N*3],c1[N*3],tmp[N*3];
point sta[N];
int top;
int Len;
int key[N],len;
int k;
int u,pt[N];
struct section{
	int st,ed;
}C0[N],C1[N];

void dfs(int x,int D,point now){
	c0[++len]=now;
	vis[x]=tim;
	for(int p=h[x];p;p=e[p].nxt)
	if (vis[e[p].x]<tim&&depth[e[p].x]>D)dfs(e[p].x,D,now+e[p].ad);
}


void ConvexHull(int x){
	int l=C0[x].st,r=C0[x].ed;
	top=0;
	sort(c0+l,c0+r+1);
	fo(i,l,r){
		if (top&&sta[top].x==c0[i].x)continue;
		while(top>1&&cross(sta[top-1],sta[top],c0[i])>=0)top--;
		sta[++top]=c0[i];
	}
	C0[x].ed=C0[x].st+top-1;
	fo(i,1,top)c0[C0[x].st+i-1]=sta[i];
}

void merge(point *a,int la,int ra,point *b,int lb,int rb,point *c,int lc,int &rc){
	top=0;
	int w=0,ha=la,hb=lb;
	while(ha<=ra||hb<=rb){
		point u;
		if (hb>rb||(ha<=ra&&a[ha]<b[hb]))u=a[ha++];
		else u=b[hb++];
		if(top&&sta[top].x==u.x)continue;
		while(top>1&&cross(sta[top-1],sta[top],u)>=0)top--;
		sta[++top]=u;
	}
	rc=lc+top-1;
	fo(i,1,top)c[lc+i-1]=sta[i];
}

void solve(int l,int r){
	if (l==r)return;
	int mid=(l+r)/2;
	solve(l,mid);
	solve(mid+1,r);
	int L=key[l],R=key[mid+1];
	int hl=C0[L].st,hr=C0[R].st;
	Len=0;
	tmp[Len=1]=point(c0[hl].x+c0[hr].x,c0[hl].y+c0[hr].y);
	while(hl<C0[L].ed||hr<C0[R].ed){
		if (hr==C0[R].ed||(hl<C0[L].ed&&cmp0(c0[hl+1]-c0[hl],c0[hr+1]-c0[hr]))){
			tmp[Len+1]=tmp[Len]+(c0[hl+1]-c0[hl]);
			hl++;
		}
		else{
			tmp[Len+1]=tmp[Len]+(c0[hr+1]-c0[hr]);
			hr++;
		}
		Len++;
	}
	merge(c0,C0[L].st,C0[L].ed,c0,C0[R].st,C0[R].ed,c0,C0[L].st,C0[L].ed);
	merge(c1,C1[L].st,C1[L].ed,c1,C1[R].st,C1[R].ed,c1,C1[L].st,C1[L].ed);
	merge(c1,C1[L].st,C1[L].ed,tmp,1,Len,c1,C1[L].st,C1[L].ed);
}

point ans[N*2];
int al;

void rebuild(){
	sort(ans+1,ans+1+al);
	top=0;
	fo(i,1,al){
		if (top&&sta[top].x==ans[i].x)continue;
		while(top>1&&cross(sta[top-1],sta[top],ans[i])>=0)top--;
		sta[++top]=ans[i];
	}
	al=top;
	fo(i,1,al)ans[i]=sta[i];
}

LL calc(LL x,point u){return u.x*x+u.y;}

int digi[100],digiw;

void putans(LL x){
	if (!x){putchar('0');putchar(' ');return;}
	for(;x;x/=10)digi[++digiw]=x%10;
	for(;digiw;)putchar('0'+digi[digiw--]);
	putchar(' ');
}

int main(){
	n=get();m=get();
	fo(i,1,n-1){
		int x=get(),y=get(),k=get(),b=get();
		inse1(x,y,point(k,b));
		inse1(y,x,point(k,b));
	}
	tim++;
	n1=n;
	getnew(1);
	n=n1;
	build(1,1);
	fo(i,1,n)num[i]=i;
	sort(num+1,num+1+n,cmp);
	int lst=0;
	al=1;
	ans[1]=point(0,0);
	fo(i,1,n)
	if (i==n||depth[num[i+1]]>depth[num[i]]){
		int D=depth[num[i]];
		u=len=0;
		fo(j,lst+1,i){
			int x=num[j];
			k=0;
			for(int p=h[x];p;p=e[p].nxt)
			if (depth[e[p].x]>D){
				int y=e[p].x;
				C0[y].st=++len;
				c0[len]=point(0,0);
				tim++;
				dfs(y,D,e[p].ad);
				C0[y].ed=len;
				ConvexHull(y);
				len=len+2*(C0[y].ed-C0[y].st+1);
				C1[y]=C0[y];
				fo(t,C0[y].st,C0[y].ed)c1[t]=c0[t];
				key[++k]=y;
			}
			if (k){
				solve(1,k);
				int p=key[1];
				C0[x]=C0[p],C1[x]=C1[p];
				fo(t,C1[x].st,C1[x].ed)ans[++al]=c1[t];
			}
		}
		rebuild();
		lst=i;
	}
	int w=1;
	fo(i,0,m-1){
		while(w<al&&calc(i,ans[w])<calc(i,ans[w+1]))w++;
		putans(calc(i,ans[w]));
	}
	return 0;
}