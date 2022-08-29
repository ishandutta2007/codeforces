#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
typedef set<int>::iterator it;
const int MAXN=410000;
const int  pyc=100006;
struct Matrix_Area{
	// 
	int n;
	vector<pii>add[MAXN];
	vector<pii>del[MAXN];
	int sum[MAXN*4],cov[MAXN*4];
	
	
	void addmatrix(int x1,int y1,int x2,int y2){
		add[x1].pb(pii(y1,y2));
		del[x2+1].pb(pii(y1,y2));
	}
	
	
	void cover(int me,int l,int r,int x,int y,int v){
		if(x<=l&&r<=y){
			cov[me]+=v;
			if(cov[me]>0)sum[me]=r-l+1;
			else sum[me]=sum[me*2]+sum[me*2+1];
			return;
		}
		int mid=(l+r)>>1;
		if(x<=mid)cover(me*2,l,mid,x,y,v);
		if(y>mid)cover(me*2+1,mid+1,r,x,y,v);
		if(cov[me]>0)sum[me]=r-l+1;
		else sum[me]=sum[me*2]+sum[me*2+1];
	}
	
	
	LL work(){
		LL ans=0;
		rep(i,1,n){
			rep(j,0,add[i].size()-1)cover(1,1,n,add[i][j].fi,add[i][j].se,1);
			rep(j,0,del[i].size()-1)cover(1,1,n,del[i][j].fi,del[i][j].se,-1);
			ans+=1ll*sum[1];
		}
		return ans;
	}
}odd,even;


set<int>zh[MAXN],fu[MAXN];
map<int,bool>bla[MAXN];
map<int,bool>come[5][MAXN];
int n,m,k;int nx,ny;int d;
// NE,NW,SE,SW
int dx[5]={0,-1,-1,1,1};
int dy[5]={0,1,-1,1,-1};


struct road{
	int x1,y1,x2,y2;
	inline road(int _x1=0,int _y1=0,int _x2=0,int _y2=0){
		x1=_x1;y1=_y1;x2=_x2;y2=_y2;
	}
	inline void zhuan(){
		x1+=y1;y1=x1-y1*2;
		x2+=y2;y2=x2-y2*2;
	}	
}a[MAXN*10];int top;


void Qiu(){
	//
	//(x+y,x-y)xy 
	rep(i,1,top){
		a[i].x1+=pyc;
		a[i].x2+=pyc;
		a[i].y1+=pyc;
		a[i].y2+=pyc;
	}
	odd.n=even.n=400000;
	LL rp=0;
	rep(i,1,top){
		if(a[i].x1&1)odd.addmatrix((a[i].x1+1)/2,(a[i].y1+1)/2,(a[i].x2+1)/2,(a[i].y2+1)/2);
		else	even.addmatrix(a[i].x1/2,a[i].y1/2,a[i].x2/2,a[i].y2/2);
	}
	rp=odd.work()+even.work();
	printf("%I64d\n",rp);
}


int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,k){
		int x,y;scanf("%d%d",&x,&y);
		zh[x-y+pyc].insert(x);
		fu[x+y].insert(x);
		bla[x][y]=1;
	}
	rep(i,0,n+1){
		//(0..n,0)
		zh[i+pyc].insert(i);
		fu[i].insert(i);
		bla[i][0]=1;
		//(0..n,m+1)
		zh[i-m-1+pyc].insert(i);
		fu[i+m+1].insert(i);
		bla[i][m+1]=1;
	}
	rep(j,0,m+1){
		//(0,0..m)
		zh[-j+pyc].insert(0);
		fu[0+j].insert(0);
		bla[0][j]=1;
		//(n+1,0..m)
		zh[n+1-j+pyc].insert(n+1);
		fu[n+1+j].insert(n+1);
		bla[n+1][j]=1;
	}
	scanf("%d%d",&nx,&ny);
	char opt[3];scanf("%s",opt+1);
	if(opt[1]=='N'&&opt[2]=='E')d=1;
	if(opt[1]=='N'&&opt[2]=='W')d=2;
	if(opt[1]=='S'&&opt[2]=='E')d=3;
	if(opt[1]=='S'&&opt[2]=='W')d=4;
	bool end=1;
	while(end){
		int mx,my;
		come[d][nx][ny]=1;
		if(d==1){
			//-1 +1
			it bg=fu[nx+ny].lower_bound(nx);
			--bg;
			mx=(*bg)+1;
			my=nx+ny-mx;
			a[++top]=road(nx,ny,mx,my);
			nx=mx;
			ny=my;
			if(bla[nx][ny+1]){
				if(bla[nx-1][ny])d=4;
				else{nx--;d=2;}
			}
			else{
				if(bla[nx-1][ny]){ny++;d=3;}
				else d=4;
			}
		}
		else
		if(d==2){
			//-1 -1
			it bg=zh[nx-ny+pyc].lower_bound(nx);
			--bg;
			mx=(*bg)+1;
			my=mx-nx+ny;
			a[++top]=road(nx,ny,mx,my);
			nx=mx;
			ny=my;
			if(bla[nx-1][ny]){
				if(bla[nx][ny-1])d=3;
				else{ny--;d=4;}
			}
			else{
				if(bla[nx][ny-1]){nx--;d=1;}
				else d=3;
			}
		}
		else
		if(d==3){
			// +1,+1
			it bg=zh[nx-ny+pyc].upper_bound(nx);
			mx=(*bg)-1;
			my=mx-nx+ny;
			a[++top]=road(nx,ny,mx,my);
			nx=mx;
			ny=my;
			if(bla[nx][ny+1]){
				if(bla[nx+1][ny])d=2;
				else {nx++;d=4;}
			}
			else{
				if(bla[nx+1][ny]){ny++;d=1;}
				else d=2;
			}
		}
		else{
			//+1,-1
			it bg=fu[nx+ny].upper_bound(nx);
			mx=(*bg)-1;
			my=nx+ny-mx;
			a[++top]=road(nx,ny,mx,my);
			nx=mx;
			ny=my;
			if(bla[nx][ny-1]){
				if(bla[nx+1][ny])d=1;
				else {nx++;d=3;}
			}
			else{
				if(bla[nx+1][ny]){ny--;d=2;}
				else d=1;
			}
		}
		if(come[d][nx][ny])break;
	}
	rep(i,1,top)a[i].zhuan();
	rep(i,1,top)if(a[i].x1+a[i].y1>a[i].x2+a[i].y2){
		swap(a[i].x1,a[i].x2);
		swap(a[i].y1,a[i].y2);
	}
	Qiu();
	return 0;
}