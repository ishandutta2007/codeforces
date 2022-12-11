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

const int N = 2e5+5;

int n;
char s[N];
int q;
struct Sam_Node{
	int len,fa,st,w;
	int son[26];
}sam[N];
int key[N],tot;

int add(int now,int c){
	int x=++tot;
	sam[x].len=sam[now].len+1;
	for(;now!=-1&&!sam[now].son[c];now=sam[now].fa)sam[now].son[c]=x;
	if (now==-1)sam[x].fa=0;
	else{
		int y=sam[now].son[c];
		if (sam[y].len==sam[now].len+1)sam[x].fa=y;
		else{
			int tmp=++tot;
			sam[tmp]=sam[y];
			sam[tmp].len=sam[now].len+1;
			sam[y].fa=sam[x].fa=tmp;
			for(;now!=-1&&sam[now].son[c]==y;now=sam[now].fa)sam[now].son[c]=tmp;
		}
	}
	return x;
}

int que[N],lef[N],rig[N];
int cnt[N];
int Left[N],Right[N];
int u,pt[N];
char kc[N];
int k,id[N];

bool cmp(int x,int y){return kc[x]<kc[y];}

void dfs(int x){
	u=0;
	for(int y=lef[x];y;y=rig[y]){
		kc[y]=s[sam[y].st+sam[x].len];
		pt[++u]=y;
	}
	sort(pt+1,pt+1+u,cmp);
	lef[x]=0;
	fo(i,1,u)rig[pt[i]]=0;
	fd(i,u,1){
		int y=pt[i];
		rig[y]=lef[x];
		lef[x]=y;
	}
	Left[x]=k+1;
	if (sam[x].w)id[++k]=sam[x].w;
	for(int y=lef[x];y;y=rig[y])dfs(y);
	Right[x]=k;
}

struct Sgt_Node{
	int l,r,tot;
}tree[N*20];
int rt[N],sgt;

void add(int &now,int qf,int l,int r,int x){
	tree[now=++sgt]=tree[qf];
	tree[now].tot++;
	if(l==r)return;
	int mid=(l+r)/2;
	if (x<=mid)add(tree[now].l,tree[qf].l,l,mid,x);
	else add(tree[now].r,tree[qf].r,mid+1,r,x);
}

int getone(int now,int qf,int l,int r,int x,int y){
	if (x>y)return -1;
	if (tree[now].tot-tree[qf].tot==0)return -1;
	if (x<=l&&r<=y){
		if(l==r)return l;
		int mid=(l+r)/2;
		int ret=getone(tree[now].l,tree[qf].l,l,mid,x,y);
		if (ret==-1)ret=getone(tree[now].r,tree[qf].r,mid+1,r,x,y);
		return ret;
	}
	int mid=(l+r)/2,ret=-1;
	if (x<=mid)ret=getone(tree[now].l,tree[qf].l,l,mid,x,y);
	if (ret==-1&&y>mid)ret=getone(tree[now].r,tree[qf].r,mid+1,r,x,y);
	return ret;
}

char qry[N];

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int now=0;
	sam[0].fa=-1;
	fd(i,n,1){
		now=add(now,s[i]-'a');
		key[i]=now;
	}
	fo(i,1,n)sam[key[i]].st=sam[key[i]].w=i;
	fo(i,0,tot)cnt[sam[i].len]++;
	fo(i,1,n)cnt[i]+=cnt[i-1];
	fo(i,0,tot)que[cnt[sam[i].len]--]=i;
	fd(i,tot+1,2){
		int x=que[i];
		rig[x]=lef[sam[x].fa];
		lef[sam[x].fa]=x;
		if (!sam[sam[x].fa].st)sam[sam[x].fa].st=sam[x].st;
	}
	dfs(0);
	fo(i,1,k)add(rt[i],rt[i-1],1,n,id[i]);
	q=get();
	fo(cas,1,q){
		int l=get(),r=get();
		scanf("%s",qry+1);
		int L=strlen(qry+1);
		int now=0;
		int key=-1;
		fo(i,1,L+1){
			char v;
			if(i>L)v=0;else v=qry[i];
			if (i<=sam[now].len){
				char c=s[sam[now].st+i-1];
				if (v==c);
				else{
					if (v<c){
						int x=getone(rt[Right[now]],rt[Left[now]-1],1,n,l,r+1-i);
						if (x!=-1)key=x;
					}
					break;
				}
			}
			else{
				for(int x=lef[now];x;x=rig[x])
				if (kc[x]>v){
					int t=getone(rt[Right[x]],rt[Left[x]-1],1,n,l,r-i+1);
					if (t!=-1){
						key=t;
						break;
					}
				}
				int to=0;
				for(int x=lef[now];x;x=rig[x])
				if (kc[x]==v){to=x;break;}
				if (!to)break;
				now=to;
			}
		}
		if (key==-1)printf("-1\n");
		else{
			bool can=0;
			fo(i,1,L){
				putchar(s[key+i-1]);
				if (s[key+i-1]>qry[i]){can=1;break;}
			}
			if (!can)putchar(s[key+L]);
			putchar('\n');
		}
	}
	return 0;
}