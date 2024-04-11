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
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=300005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int n,m,now,ans[N];
vi g[N],f[N];
bool vis[N],cli[N];
void dfs(int x){
	if(x==n+1) return;
	int si=0;
	for(int y:g[x])
		if(vis[y]) si++;
	if(si==now) vis[x]=1,now++;
	dfs(x+1);
}
bool check(vi a,vi b){
	if(a.size()!=b.size()) return 0;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(int i=0;i<a.size();i++)
		if(a[i]!=b[i]) return 0;
	return 1;
}
void color(vi a,int s){
	for(int i:a) vis[i]=1,ans[i]=s;
}
bool check(vi a,int num){
	for(int i:a) cli[i]=1;
	for(int i:a){
		int si=0;
		for(int j:g[i]){
			if(cli[j]) si++;
			else if(vis[j]&&abs(num-ans[j])>1)return 0;
		}
		if(si<a.size()-1) return 0; 
	}
	for(int i:a) cli[i]=0;
	return 1;
}
void print(vi a){for(int i:a) printf("%d ",i);puts("");}
void make(vi st,int num,int to){
	while(1){
		num+=to;vi t(0);
		for(int i:st)
			for(int j:g[i])
				if(!vis[j]) t.pb(j);
		if(!t.size()) return ;
		vi tmp(0);
		sort(t.begin(),t.end());
		for(int i=0;i<t.size();i++){
			int r=i;
			while(r<t.size()&&t[i]==t[r]) r++;
			if(r-i!=st.size()){puts("NO");exit(0);}
			i=r-1;tmp.pb(t[i]);
		}
		t=tmp;
		if(!check(t,num)){puts("NO");exit(0);}
		color(t,num);st=t;
	}
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y);g[y].pb(x);
	}
	vis[1]=1;now=1;
	dfs(2);
	if(now==n){
		puts("YES");
		for(int i=1;i<=n;i++) printf("1 ");
		puts("");
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(vis[i]){
			for(int y:g[i])
				if(!vis[y]) f[i].pb(y);
		}
	vi L(0),R(0),lef(0),rig(0);
	L=f[1];
	for(int i=2;i<=n;i++)
		if(vis[i]){if(!check(L,f[i])){R=f[i];break;}}
	bool isok=1;
	for(int i=1;i<=n;i++)
		if(vis[i]){
			if(!check(L,f[i])&&!check(R,f[i])){puts("NO");return 0;}
			else if(check(L,f[i])) lef.pb(i); else rig.pb(i);
		}
	color(lef,0);color(rig,1);
	make(lef,0,-1);make(rig,1,1);
	int mn=0;
	for(int i=1;i<=n;i++) gmin(mn,ans[i]);
	puts("YES");
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]+1-mn);puts("");
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}