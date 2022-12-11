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

const int N = 10005;

int A,B;
struct point{
	int x,y,id,deg;
	point(const int x_=0,const int y_=0,const int id_=0,const int deg_=0){x=x_;y=y_;id=id_;deg=deg_;}
}a[N];
int n;

int cross(point a,point b,point c){return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);}
int cross(point a,point b){return a.x*b.y-a.y*b.x;}

int ed[N][2];
int tot;

int gettype(point a){
	if (a.y==0)return a.x>0?1:2;
	return a.y>0?1:2;
}

bool cmp(point a,point b){
	int ta=gettype(a),tb=gettype(b);
	if (ta!=tb)return ta<tb;
	return cross(a,b)>0;
}

int next(int w,int l,int r){return w==r?l:w+1;}

int be[N];

void solve(int l,int r){
	if (l==r||l>r)return;
	int max_deg=0,max_id=0,Id=0;
	fo(i,l,r)
	if (max_deg<a[i].deg){
		max_deg=a[i].deg;
		max_id=i;
	}
	Id=a[max_id].id;
	if (max_deg==1){
		int key=0;
		fo(i,l,r)if (a[i].deg==0){key=i;break;}
		fo(i,l,r)
		if (i!=key){
			tot++;
			ed[tot][0]=a[i].id-A;
			ed[tot][1]=a[key].id;
		}
		return;
	}
	swap(a[l],a[max_id]);
	point st=a[l];
	fo(i,l+1,r){
		a[i].x-=st.x;
		a[i].y-=st.y;
		be[a[i].id]=2;
	}
	sort(a+l+1,a+r+1,cmp);
	int sum=a[l+1].deg-1;
	int w=l+1;
	int lef=0,rig=0;
	fo(i,l+1,r){
		while(next(w,l+1,r)!=i&&cross(a[i],a[next(w,l+1,r)])>0){
			w=next(w,l+1,r);
			sum+=a[w].deg-1;
		}
		if (sum>=1-max_deg&&sum<=-1){lef=i,rig=w;break;}
		if (i<r){
			sum-=a[i].deg-1;
			if (w==i)sum+=a[++w].deg-1;
		}
	}
	fo(i,l+1,r)a[i].x+=st.x,a[i].y+=st.y;
	int need=-sum;
	int l1=l+1,r1=r;
	for(int x=lef;x!=next(rig,l+1,r);x=next(x,l+1,r))be[a[x].id]=1;
	fo(i,l+1,r)
	if (be[a[i].id]==1)swap(a[l1++],a[i]);
	a[l].deg=need;
	solve(l,l1-1);
	fo(i,l,l1-1)
	if (a[i].id==Id){
		a[i].deg=max_deg-need;
		swap(a[i],a[l1-1]);
		break;
	}
	solve(l1-1,r);
}

int main(){
	for(int T=get();T;T--){
		A=get();B=get();
		n=A+B;
		fo(i,1,A)a[i].deg=0;
		fo(i,A+1,A+B)a[i].deg=get();
		fo(i,1,A+B)a[i].id=i;
		fo(i,1,A){
			int x=get(),y=get();
			a[i].x=x,a[i].y=y;
		}
		fo(i,A+1,A+B){
			int x=get(),y=get();
			a[i].x=x,a[i].y=y;
		}
		tot=0;
		solve(1,n);
		printf("YES\n");
		fo(i,1,tot)printf("%d %d\n",ed[i][0],ed[i][1]);
	}
	return 0;
}