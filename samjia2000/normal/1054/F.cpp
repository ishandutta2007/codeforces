#include<bits/stdc++.h>

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

const int N = 1005;
const int L = 2e6+5;

int n;
struct point{
	int x,y;
}a[N];
map<int,set<int> >X,Y;
struct segment{
	int x,l,r;
	segment(const int x_=0,const int l_=0,const int r_=0){x=x_;l=l_;r=r_;}
}s1[N],s2[N];
int k1,k2;
struct edge{
	int x,nxt;
}e[L];
int h[N],tot,h1[N];
int to1[N],to2[N];
int vis[N],tim;
bool bz1[N],bz2[N];

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}
void inse1(int x,int y){e[++tot].x=y;e[tot].nxt=h1[x];h1[x]=tot;}

bool can(int x){
	if (vis[x]==tim)return 0;
	vis[x]=tim;
	for(int p=h[x];p;p=e[p].nxt)
	if (!to2[e[p].x]||can(to2[e[p].x])){
		to1[x]=e[p].x;
		to2[e[p].x]=x;
		return 1;
	}
	return 0;
}

void dfs1(int x){
	if (vis[x]==tim)return;
	vis[x]=tim;
	for(int p=h[x];p;p=e[p].nxt){
		bz2[e[p].x]=1;
		if (to2[e[p].x])dfs1(to2[e[p].x]);
	}
}

void dfs2(int x){
	if (vis[x]==tim)return;
	vis[x]=tim;
	for(int p=h1[x];p;p=e[p].nxt){
		bz1[e[p].x]=1;
		if (to1[e[p].x])dfs2(to1[e[p].x]);
	}
}

int id1[N],id2[N];
bool del1[N],del2[N];

bool cmp(segment a,segment b){return a.r<b.r;}

int main(){
	n=get();
	fo(i,1,n){
		a[i].x=get();a[i].y=get();
		X[a[i].x].insert(a[i].y);
		Y[a[i].y].insert(a[i].x);
	}
	fo(i,1,n){
		int x=a[i].x,y=a[i].y;
		set<int>::iterator h=X[x].upper_bound(y);
		if (h!=X[x].end())s1[id1[i]=++k1]=segment(x,y,*h);
		h=Y[y].upper_bound(x);
		if (h!=Y[y].end())s2[id2[i]=++k2]=segment(y,x,*h);
	}
	fo(i,1,k1)
		fo(j,1,k2)
		if (s2[j].x>s1[i].l&&s2[j].x<s1[i].r&&s1[i].x>s2[j].l&&s1[i].x<s2[j].r)inse(i,j),inse1(j,i);
	fo(i,1,k1){
		tim++;
		can(i);
	}
	tim++;
	fo(i,1,k1)if (!to1[i])dfs1(i);
	tim++;
	fo(i,1,k2)if (!to2[i])dfs2(i);
	fo(i,1,k1)
	if(to1[i]){
		int x=i,y=to1[i];
		if (bz1[x])del1[x]=1;else del2[y]=1;
	}
	int k=0;
	fo(i,1,k1)if (!del1[i])s1[++k]=s1[i];
	k1=k;
	k=0;
	fo(i,1,k2)if (!del2[i])s2[++k]=s2[i];
	k2=k;
	sort(s1+1,s1+1+k1,cmp);
	sort(s2+1,s2+1+k2,cmp);
	
	k=0;
	fo(i,1,k1){
		bool mrg=0;
		fo(j,1,k)
		if (s1[j].x==s1[i].x&&s1[j].r==s1[i].l){
			s1[j].r=s1[i].r;
			mrg=1;
			break;
		}
		if (!mrg)s1[++k]=s1[i];
	}
	k1=k;
	
	k=0;
	fo(i,1,k2){
		bool mrg=0;
		fo(j,1,k)
		if (s2[j].x==s2[i].x&&s2[j].r==s2[i].l){
			s2[j].r=s2[i].r;
			mrg=1;
			break;
		}
		if (!mrg)s2[++k]=s2[i];
	}
	k2=k;
	
	k=k2;
	fo(i,1,n){
		bool ext=0;
		fo(j,1,k)
		if (s2[j].x==a[i].y&&s2[j].l<=a[i].x&&s2[j].r>=a[i].x){ext=1;break;}
		if (!ext)s2[++k2]=segment(a[i].y,a[i].x,a[i].x);
	}
	printf("%d\n",k2);
	fo(i,1,k2)printf("%d %d %d %d\n",s2[i].l,s2[i].x,s2[i].r,s2[i].x);
	k=k1;
	fo(i,1,n){
		bool ext=0;
		fo(j,1,k)
		if (s1[j].x==a[i].x&&s1[j].l<=a[i].y&&a[i].y<=s1[j].r){ext=1;break;}
		if(!ext)s1[++k1]=segment(a[i].x,a[i].y,a[i].y);
	}
	printf("%d\n",k1);
	fo(i,1,k1)printf("%d %d %d %d\n",s1[i].x,s1[i].l,s1[i].x,s1[i].r);
	return 0;
}