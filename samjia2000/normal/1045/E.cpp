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

const int N = 1e3+5;

int n;
struct point{
	int x,y,col,id;
	void read(){
		x=get();y=get();col=get();
	}
}a[N];
int cross(point a,point b,point c){return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);}
int operator*(point a,point b){return a.x*b.y-a.y*b.x;}
point operator -(point a,point b){a.x-=b.x,a.y-=b.y;return a;}
point operator +(point a,point b){a.x+=b.x,a.y+=b.y;return a;}

int be[N];
point sta[N];
int top;

bool cmp(point a,point b){return a.x==b.x?a.y<b.y:a.x<b.x;}

struct edge{
	int x,y;
	edge(const int x_=0,const int y_=0){x=x_;y=y_;}
}ed[N];
int tot;
point que[N];
int k;

bool inside(point a,point b,point c,point q){
	return ((cross(a,b,q)>=0)!=(cross(a,c,q)>=0))&&((cross(b,a,q)>=0)!=cross(b,c,q)>=0)&&((cross(c,a,q)>=0)!=(cross(c,b,q)>=0));
}

void solve(point A,point B,point C){
	fo(i,1,n)
	if (a[i].col==C.col&&inside(A,B,C,a[i])){
		ed[++tot]=edge(C.id,a[i].id);
		solve(A,B,a[i]);
		solve(a[i],C,A);
		solve(a[i],C,B);
		return;
	}
	fo(i,1,n)if (inside(A,B,C,a[i]))ed[++tot]=edge(A.id,a[i].id);
}

int main(){
	//freopen("data.in","r",stdin);
	n=get();
	int all=0;
	fo(i,1,n){
		a[i].read();
		a[i].id=i;
		all|=1<<a[i].col;
	}
	if (all!=3){
		printf("%d\n",n-1);
		fo(i,1,n-1)printf("%d %d\n",0,i);
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	top=0;
	fo(i,1,n){
		if (top&&sta[top].x==a[i].x)continue;
		while(top>1&&cross(sta[top-1],a[i],sta[top])>=0)top--;
		sta[++top]=a[i];
	}
	fo(i,1,top)be[sta[i].id]=1;
	top=0;
	fd(i,n,1){
		if (top&&sta[top].x==a[i].x)continue;
		while(top>1&&cross(sta[top-1],a[i],sta[top])>=0)top--;
		sta[++top]=a[i];
	}
	fo(i,1,top)if (!be[sta[i].id])be[sta[i].id]=2;
	k=0;
	fo(i,1,n)if (be[a[i].id]==1)que[++k]=a[i];
	fd(i,n,1)if (be[a[i].id]==2)que[++k]=a[i];
	int cnt=0,keyw=0;
	fo(i,1,k)
	if (que[i].col!=que[(i+k-2)%k+1].col){
		cnt++;
		keyw=i;
	}
	if (cnt>2)return printf("Impossible\n"),0;
	if (cnt==0){
		fo(i,1,k-1)ed[++tot]=edge(que[i].id,que[i+1].id);
		point other;
		fo(i,1,n)if (a[i].col!=que[1].col){other=a[i];break;}
		fo(i,1,k-1)solve(que[i],que[i+1],other);
		solve(que[k],que[1],other);
	}
	else{
		int x=keyw;
		for(;que[x].col==que[keyw].col;x=x%k+1){
			if (que[x].col==que[x%k+1].col){
				solve(que[x],que[x%k+1],que[(keyw+k-2)%k+1]);
				ed[++tot]=edge(que[x].id,que[x%k+1].id);
			}
		}
		int lst=(x+k-2)%k+1;
		for(;x!=keyw;x=x%k+1){
			if (que[x].col==que[x%k+1].col){
				solve(que[x],que[x%k+1],que[lst]);
				ed[++tot]=edge(que[x].id,que[x%k+1].id);
			}
		}
	}
	printf("%d\n",tot);
	fo(i,1,tot)printf("%d %d\n",ed[i].x-1,ed[i].y-1);
	return 0;
}