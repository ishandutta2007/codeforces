#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;
typedef pair<ll,int> pli;

ll IN(){
	int c,f;ll x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int top=32000000;
const int N=1e5+19;
const int M=2000000;
const ll oo=1ll<<60;

struct Edge{
	int y;
	ll z;
	int nxt;
} E[M];

bool vis[top+19];
int pri[top/10];
int ans[N],las[N];
int q,cnt;
ll dis[N];
ll x,y;
map<ll,vector<pli> > V;

struct node{
	int x;
	ll d;
	bool operator < (const node &B) const{
		return d>B.d;
	}
};priority_queue<node> Q;

void Add_Edge(int x,int y,ll z){
	E[cnt]=(Edge){y,z,las[x]};las[x]=cnt++;
}
void Init(){
	For(i,2,top+1){
		if (!vis[i]) pri[++*pri]=i;
		for (int j=1;j<=*pri&&pri[j]*i<=top;j++){
			vis[pri[j]*i]=1;
			if (i%pri[j]==0) break;
		}
	}
}
void exgcd(int a,int b,int &x,int &y){
	if (!b){
		x=1,y=0;return;
	}
	exgcd(b,a%b,x,y);
	int tmp=x;x=y;y=tmp-a/b*y;
}
int calc(ll c,int a,int b){
	int x,y;
	exgcd(b%a,a,x,y);
	x=(1ll*x*(c%a)%a+a)%a;
	return 1ll*x*b<=c;
}
void Dijkstra(int s){
	dis[s]=0;
	Q.push((node){s,0});
	while (!Q.empty()){
		int x=Q.top().x;
		ll d=Q.top().d;
		Q.pop();
		if (d!=dis[x]) continue;
		for (int i=las[x],y;~i;i=E[i].nxt)
			if (dis[x]+E[i].z<dis[y=E[i].y]){
				dis[y]=dis[x]+E[i].z;
				Q.push((node){y,dis[y]});
			}
	}
}
void work(ll k,vector<pli> V){
	if (k==1) return;
	vector<ll> P;
	for (int i=1;i<=*pri&&1ll*pri[i]*pri[i]<=k;i++)
		if (k%pri[i]==0){
			P.pb(pri[i]);
			while (k%pri[i]==0) k/=pri[i];
		}
	if (k>1) P.pb(k);
	if (P.size()==1){
		for (pli T:V){
			ans[T.se]=(T.fi%P[0]==0);
		}
	} lf (P.size()==2){
		for (pli T:V){
			ans[T.se]=calc(T.fi,P[0],P[1]);
		}
	} else{
		memset(las,-1,sizeof(las));
		cnt=0;
		For(w,0,P[0]){
			dis[w]=oo;
			For(i,1,P.size()){
				Add_Edge(w,(w+P[i])%P[0],P[i]);
			}
		}
		Dijkstra(0);
		for (pli T:V){
			ans[T.se]=(T.fi>=dis[T.fi%P[0]]);
		}
	}
}

int main(){
	Init();
	q=IN();
	For(i,1,q+1){
		x=IN(),y=IN();
		V[y].pb(mp(x,i));
	}
	for (auto T:V){
		work(T.fi,T.se);
	}
	For(i,1,q+1){
		puts(ans[i]?"YES":"NO");
	}
}