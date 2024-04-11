#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=2000000+19;
const int oo=(1<<30)-1;

struct edge{
	int x,y,l,r;
} e[N];

Vi T[N][2][2],T2[N][2];
int dis[N],Q[N];
int x,y,l,r,n,m,ans,f,w;

struct node{
	int i,d;
	bool operator < (const node &B) const{
		return d>B.d;
	}
};priority_queue<node> H;

int cal(int i,int b){
	return i+b*m;
}
bool cmp(int i,int j){
	return e[i].l>e[j].l;
}
void gao(int i){
	T[e[i].x][e[i].l&1][0].pb(cal(i,e[i].l&1));
	if (e[i].l+1<e[i].r) T[e[i].x][e[i].l&1^1][1].pb(cal(i,e[i].l&1^1));
	T2[e[i].x][0].pb(i);
	T2[e[i].x][1].pb(i+m);
}
void Push(int i,int d){
//	assert(chk(i,d));
	if (dis[i]==oo) dis[i]=d,Q[++f]=i;
}
void bfs(){
	For(i,0,m) dis[i]=dis[i+m]=oo;
	For(i,0,m) if (e[i].x==1&&e[i].l==0) Q[++f]=i,dis[i]=0;
	while (f>w||!H.empty()){
		while (f==w&&!H.empty()){
			Push(H.top().i,H.top().d);
			H.pop();
		}
		if (f==w) break;
		w++;
		int i=Q[w]%m,j=Q[w]/m,d=dis[Q[w]];
//		assert(d%2==j);
		while (!H.empty()&&H.top().d==d){
//			assert(chk(H.top().i,H.top().d));
			Push(H.top().i,H.top().d);
			H.pop();
		}
		Vi &tmp=T[e[i].y][j^1][0];
		while (!tmp.empty()&&e[tmp.back()].l<=d+1) tmp.pop_back();
		while (!tmp.empty()&&e[tmp.back()].l-1<e[i].r){
			H.push((node){tmp.back(),e[tmp.back()].l});
			/*
			if (!chk(tmp.back(),e[tmp.back()].l)){
				assert(0);
			}
			*/
			tmp.pop_back();
		}
		Vi &tmp2=T[e[i].y][j^1][1];
		while (!tmp2.empty()&&e[tmp2.back()].l<=d+1) tmp2.pop_back();
		while (!tmp2.empty()&&e[tmp2.back()].l<e[i].r){
			H.push((node){tmp2.back(),e[tmp2.back()].l+1});
			/*
			if (!chk(tmp2.back(),e[tmp2.back()].l+1)){
				assert(0);
			}
			*/
			tmp2.pop_back();
		}
		Vi &tmp3=T2[e[i].y][j^1];
		while (!tmp3.empty()){
			if (e[tmp3.back()].l>d+1) break;
			if (e[tmp3.back()].r>d+1){
			/*
				if (!chk(tmp3.back(),d+1)){
					assert(0);
				}
			*/
				Push(tmp3.back(),d+1);
			}
			tmp3.pop_back();
		}
	}
	ans=oo;
//	For(i,0,m) printf("%d ",dis[i]);
	For(i,0,2*m) if (e[i].y==n) ans=min(ans,dis[i]+1);
}

int main(){
	n=IN(),m=IN();
	if (n==1){
		puts("0");
		return 0;
	}
	assert(n>=1&&n<=500000);
	assert(m>=0&&m<=500000);
	m*=2;
	For(i,0,m/2){
		x=IN(),y=IN(),l=IN(),r=IN();
		assert(x!=y&&x>=1&&x<=n&&y>=1&&y<=n);
		assert(l<r);
		assert(l>=0);
		assert(r<=int(1e9));
		e[2*i]=e[2*i+m]=(edge){x,y,l,r};
		e[2*i+1]=e[2*i+m+1]=(edge){y,x,l,r};
		gao(2*i);
		gao(2*i+1);
	}
	For(i,1,n+1) For(j,0,2){
		For(k,0,2){
			sort(T[i][j][k].begin(),T[i][j][k].end(),cmp);
//			for (int u:T[i][j][k]) assert(j==0&&u<m||j==1&&u>=m);
		}
		sort(T2[i][j].begin(),T2[i][j].end(),cmp);
//		for (int u:T2[i][j]) assert(j==0&&u<m||j==1&&u>=m);
	}
	bfs();
	printf("%d\n",ans==oo?-1:ans);
}