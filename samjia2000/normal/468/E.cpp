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
typedef unsigned long long ull;

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

const int N = 65;
const int mo = 1e9+7;
const int MAXN = 2e6;

LL js[100005];
int n,k;
int fa[N];
struct node{
	int x,y,v;
}a[N],p[N];
ull mi[70];
int m;
map<int,int>idx,idy;
int kx,ky;
LL c[N],tmp[N],s[N];
ull suf[N];
struct zt{
	ull u;
	int cnt,val;
}que[MAXN+5];
map<ull,int>id[N];
bool vis[N];
int kth[N];
LL td[N];

int getfather(int x){return fa[x]==x?x:fa[x]=getfather(fa[x]);}

bool cmp(node a,node b){return kth[a.x]<kth[b.x];}

LL dec(LL x,LL y){return x<y?x-y+mo:x+y;}
LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}

int num[N];

int getcnt(ull v){
	int ret=0;
	for(;v;v-=v&-v)ret++;
	return ret;
}

int main(){
	n=get();k=get();
	fo(i,1,k){a[i].x=get(),a[i].y=get(),a[i].v=get()-1;}
	srand(20010419);
	random_shuffle(a+1,a+1+k);
	fo(i,1,k)fa[i]=i;
	js[0]=1;
	fo(i,1,100000)js[i]=js[i-1]*i%mo;
	fo(i,1,k)
		fo(j,i+1,k)
		if (a[i].x==a[j].x||a[i].y==a[j].y){
			int fx=getfather(i),fy=getfather(j);
			fa[fy]=fx;
		}
	mi[0]=1;
	fo(i,1,k)mi[i]=mi[i-1]*2;
	c[0]=1;
	fo(tp,1,k)
	if (getfather(tp)==tp){
		m=0;
		idx.clear();idy.clear();
		kx=ky=0;
		fo(i,1,k)
		if (getfather(i)==tp){
			if (!idx[a[i].x])idx[a[i].x]=++kx;
			if (!idy[a[i].y])idy[a[i].y]=++ky;
			p[++m].x=idx[a[i].x];
			p[m].y=idy[a[i].y];
			p[m].v=a[i].v;
		}
		if (kx<ky){
			swap(kx,ky);
			fo(i,1,m)swap(p[i].x,p[i].y);
		}
		fo(i,1,kx)vis[num[i]=i]=td[i]=0;
		fo(i,1,m)td[p[i].x]|=mi[p[i].y];
		ull now=0;
		fd(i,kx,1){
			int key=0,cnt=0;
			ull tp=0;
			fo(j,1,kx)
			if (!vis[j]){
				if (!key||cnt>getcnt(now|td[j])){
					tp=now|td[j];
					cnt=getcnt(tp);
					key=j;
				}
			}
			vis[key]=1;
			now=tp;
			kth[num[i]=key]=i;
		}
		sort(p+1,p+1+m,cmp);
		suf[m+1]=0;
		fd(i,m,1)suf[i]=suf[i+1]|mi[p[i].y];
		int he=0,ta=1;
		que[1].cnt=0;
		que[1].val=1;
		que[1].u=0;
		int w=1;
		fo(i,1,kx){
			fo(j,0,k)id[j].clear();
			int qw=w;
			while(w<=m&&p[w].x==num[i])w++;
			//qw ~ w-1
			int qt=ta;
			while(he<qt){
				he++;
				ull nu=que[he].u;
				LL nv=que[he].val;
				int cnt=que[he].cnt;
				int to;
				if (id[cnt][nu&suf[w]])to=id[cnt][nu&suf[w]];
				else{
					to=++ta;
					que[to].cnt=cnt;que[to].u=nu;
					que[to].val=0;
					id[cnt][nu&suf[w]]=to;
				}
				que[to].val=add(que[to].val,nv);
				fo(x,qw,w-1)
				if ((nu&mi[p[x].y])==0){
					ull u_=(nu^mi[p[x].y])&suf[w];
					int to;
					if (id[cnt+1][u_])to=id[cnt+1][u_];
					else{
						to=++ta;
						que[to].cnt=cnt+1;
						que[to].u=nu^mi[p[x].y];
						que[to].val=0;
						id[cnt+1][u_]=to;
					}
					que[to].val=add(que[to].val,nv*p[x].v%mo);
				}
			}
		}
		fo(i,0,k)tmp[i]=s[i]=0;
		for(;he<ta;){
			he++;
			s[que[he].cnt]=add(s[que[he].cnt],que[he].val);
		}
		fo(i,0,k)
			fo(j,0,k-i)
			tmp[i+j]=add(tmp[i+j],c[i]*s[j]%mo);
		fo(i,0,k)c[i]=tmp[i];
	}
	LL ans=0;
	fo(i,0,k)ans=add(ans,c[i]*js[n-i]%mo);
	printf("%I64d\n",ans);
	return 0;
}