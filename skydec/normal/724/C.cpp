#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<set>
#include<map>
#include<vector>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)((x).size()))
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double DB;
const DB pi=acos(-1.0);
const int S=100000;
const int N=110000;
struct po{
	int x,y,id;
}a[N];
po gt;
inline bool operator <(const po &a,const po &b){
	return a.x<b.x;
}
set<po> add[N<<1],dec[N<<1];
int n,m,k;
LL ans[N];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,k){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].id=i;
		ans[i]=-1;
		add[a[i].x+a[i].y].insert(a[i]);
		dec[a[i].x-a[i].y+S].insert(a[i]);
	}
	int x=0;int y=0;
	int dx=1;
	int dy=1;
	LL nowt=0;
	rep(gtw,0,(n+m)*5){
		if(dx==dy){
			int po=x-y+S;
			if(dx==-1){
				while(dec[po].size()){
					gt=*(--dec[po].end());
					int ui=x-gt.x;
					nowt+=ui;
					x+=dx*ui;
					y+=dy*ui;
					if(ans[gt.id]==-1)
					ans[gt.id]=nowt;
					dec[po].erase(gt);
				}
				int ui=min(x,y);
				nowt+=ui;
				x+=dx*ui;
				y+=dy*ui;
				if(x==0&&y==0)break;
				if(x==0)dx*=-1;
				else dy*=-1;
			}
			else{
				while(dec[po].size()){
					gt=*(dec[po].begin());
					int ui=gt.x-x;
					nowt+=ui;
					x+=dx*ui;
					y+=dy*ui;
					if(ans[gt.id]==-1)
					ans[gt.id]=nowt;
					dec[po].erase(gt);
				}
				int ui=min(n-x,m-y);
				nowt+=ui;
				x+=dx*ui;
				y+=dy*ui;
				if(x==n&&y==m)break;
				if(x==n)dx*=-1;
				if(y==m)dy*=-1;
			}
		}
		else{
			int po=x+y;
			if(dx==-1){
				while(add[po].size()){
					gt=*(--add[po].end());
					int ui=x-gt.x;
					nowt+=ui;
					x+=dx*ui;
					y+=dy*ui;
					if(ans[gt.id]==-1)
					ans[gt.id]=nowt;
					add[po].erase(gt);
				}
				int ui=min(x,m-y);
				nowt+=ui;
				x+=dx*ui;
				y+=dy*ui;
				if(x==0&&y==m)break;
				if(x==0)dx*=-1;
				else dy*=-1;
			}
			else{
				while(add[po].size()){
					gt=*(add[po].begin());
					int ui=gt.x-x;
					nowt+=ui;
					x+=dx*ui;
					y+=dy*ui;
					if(ans[gt.id]==-1)
					ans[gt.id]=nowt;
					add[po].erase(gt);
				}
				int ui=min(n-x,y);
				nowt+=ui;
				x+=dx*ui;
				y+=dy*ui;
				if(x==n&&y==0)break;
				if(x==n)dx*=-1;
				else dy*=-1;
			}
		}
	}
	rep(i,1,k)printf("%I64d\n",ans[i]);
	return 0;
}