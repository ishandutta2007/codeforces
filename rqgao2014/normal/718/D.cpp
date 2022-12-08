#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
using namespace std;

const int N=100005,M=100005,m1=998244353,m2=1e9+9,base=1e6+3;
inline void gmin(int &x,int y){if(x>y) x=y;}
inline void gmax(int &x,int y){if(x<y) x=y;}

struct node{int to,next;}p[N<<2];
int n,tot,head[N],du[N];
set<ull> s;
ull dp[N<<2];
bool vis[N<<2];
void add(int x,int y){
	p[++tot]=(node){y,head[x]};head[x]=tot;
	p[++tot]=(node){x,head[y]};head[y]=tot;
}
ull f1(ull x){
	return x*x*x*109457+x*201712589+103751981;
}
ull dfs(int x,int f){
	if(vis[f]&&f) return dp[f];
	vis[f]=1;
	ull &ans=dp[f];ans=1;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if((i^f)==1) continue;
		ans*=dfs(y,i);
	}
	ull t=f1(du[x]);
	ans-=t;
	ans^=du[x]*du[x];
	return ans;
}

int main(){
	scanf("%d",&n);tot=1;
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);du[x]++;du[y]++;
	}
	for(int i=1;i<=n;i++) if(du[i]<4) s.insert(dfs(i,0));
	printf("%d\n",(int)s.size());
	return 0;
}