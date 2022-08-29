#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j),__tmp=k;i<=__tmp;i++)
#define per(i,j,k) for(int i=(j),__tmp=k;i>=__tmp;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
inline void read(int &x){
	x=0;char p=getchar();
	while(!(p<='9'&&p>='0'))p=getchar();
	while(p<='9'&&p>='0')x*=10,x+=p-48,p=getchar();
}
int fa[610000];int num[3005][6005];int ans=0;
int dx[9]={0,1,1,1,0,-1,-1,-1,0};
int dy[9]={0,-1,0,1,1,1,0,-1,-1};
int n,m,q;
int get(int x){if(x==fa[x])return x;return fa[x]=get(fa[x]);}
int jabby;int cho[610000];
inline bool ck(int x,int y){
	if(m==1)return 0;jabby++;
	rep(kind,0,1){
		rep(k,1,8){
			int xx=x+dx[k];
			int yy=y+dy[k]+kind*m;
			if(yy>m*2)yy-=m*2;
			if(yy<=0)yy+=m*2;
			if(!num[xx][yy])continue;
			if(!kind){
				cho[get(num[xx][yy])]=jabby;
			}
			else
			{
				if(cho[get(num[xx][yy])]==jabby)return 0;
			}
		}
	}
	return 1;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	rep(i,1,2*q)fa[i]=i;
	rep(i,1,q){
		int x,y;read(x);read(y);
		if(!ck(x,y))continue;
		num[x][y]=i;
		num[x][y+m]=i+q;
		rep(k,1,8){
			int xx=x+dx[k];
			int yy=y+dy[k];
			if(yy<=0)yy+=m*2;
			if(yy>m*2)yy-=m*2;
			if(num[xx][yy])
			fa[get(num[xx][yy])]=get(i);
		}
		rep(k,1,8){
			int xx=x+dx[k];
			int yy=y+m+dy[k];
			if(yy<=0)yy+=m*2;
			if(yy>m*2)yy-=m*2;
			if(num[xx][yy])
			fa[get(num[xx][yy])]=get(i+q);
		}
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}