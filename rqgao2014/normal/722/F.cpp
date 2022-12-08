#include<bits/stdc++.h>
#define fore(i,x,y) for(int i=head[(x)];i!=(y);i=p[i].next)
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define REP(i,x,y) for(int i=(x);i<(y);i++)
#define PER(i,x,y) for(int i=(x);i>(y);i--)
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls k<<1
#define rs k<<1|1
using namespace std;

const int N=100005;
int n,m;
struct node{
	int p,x,y;
};
vector<node> g[N];
vector<int> f[45];
struct array{
	int a[45],mx,mx2;
	int get(int x){
		if(mx==a[x]) return mx2;return mx;
	}void change(int x,int y){
		mx2=get(x);mx=y;
		a[x]=y;
	}
}last[45];

inline int solve(int x){
	int m=g[x].size(),ans=0;
	if(!m) return 0;
	REP(i,0,m){
		int l=i,r=i;
		while(r<m-1&&g[x][r+1].p==g[x][r].p+1) r++;
//		printf("%d %d:\n",l,r);
		int pre=l-1;
		rep(j,l,r){
			int k=g[x][j].x,y=g[x][j].y;
			REP(t,0,f[k].size()){
				int p=f[k][t],e=y%p;
				pre=max(pre,last[p].get(e));
				last[p].change(e,j);
			}
			ans=max(ans,j-pre);
//			printf("%d %d\n",j,pre);
		}
		rep(j,l,r){
			int k=g[x][j].x,y=g[x][j].y;
			REP(t,0,f[k].size()){
				int p=f[k][t];
				last[p].change(y%p,-1);
			}
		}
		i=r;
	}
	return ans;
}

int main(){
	rep(i,1,40){
		bool isok=0;
		rep(j,2,i){
			if(i%j!=0) continue;
			int t=i;
			while(t%j==0) t/=j;
			if(t==1) isok=1;
//			printf("%d %d\n",i,t);
			break;
		}
		if(!isok&&i!=1) continue;
		for(int j=i;j<=40;j+=i) f[j].pb(i);
	}
/*	rep(i,1,40){
		REP(j,0,f[i].size()) printf("%d ",f[i][j]);
		puts("");
	}*/
//	debuge;
	scanf("%d%d",&n,&m);
	memset(last,-1,sizeof(last));
	rep(i,1,n){
		int k;scanf("%d",&k);
		for(int j=0;j<k;j++){
			int x;scanf("%d",&x);
			g[x].pb((node){i,k,j});
		}
	}
	rep(i,1,m)
		printf("%d\n",solve(i));
	return 0;
}