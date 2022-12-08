#include<bits/stdc++.h>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls k<<1
#define rs k<<1|1
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define nowtime cerr<<"time:"<<(ll)clock()*1000/CLOCKS_PER_SEC<<endl
#define fore(i,x,y) for(int i=head[(x)];i!=(y);i=p[i].Next)
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define REP(i,x,y) for(int i=(x);i<(y);i++)
#define PER(i,x,y) for(int i=(x);i>(y);i--)
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

const int N=400005;
int n,m,u[N],v[N],s,t,ds,dt;
bool vis[N][2],use[N],go[N][2];
vector<pii> ans;
vi b[N];
int Next[N];
inline int find(int x){
	if(Next[x]!=x) Next[x]=find(Next[x]);
	return Next[x];
}
inline void connect(int k,int y){
	use[k]=1;
	if(y) dt--; else ds--;
	for(int i=0;i<b[k].size();i++)
		if(go[b[k][i]][y]){ans.pb(mp(b[k][i],y?t:s));return ;}
	
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&u[i],&v[i]);
	scanf("%d%d%d%d",&s,&t,&ds,&dt);
	for(int i=1;i<=n;i++) Next[i]=i;
	for(int i=1;i<=m;i++){
		if(u[i]==s||u[i]==t) continue;
		if(v[i]==s||v[i]==t) continue;
		if(find(u[i])==find(v[i])) continue;
		ans.pb(mp(u[i],v[i]));
		Next[find(u[i])]=find(v[i]);
	}
	bool isok=0,con=0;
	int si=0;
	for(int i=1;i<=m;i++){
		if(u[i]==s||v[i]==s){
			if(u[i]==t||v[i]==t){isok=1;continue;}
			int k=u[i];
			if(k==s) k=v[i];
			vis[find(k)][0]=1;
			go[k][0]=1;
			continue;
		}
		else if(u[i]==t||v[i]==t){
			int k=u[i];
			if(k==t) k=v[i];
			vis[find(k)][1]=1;
			go[k][1]=1;
		}
	}
	for(int i=1;i<=n;i++)
		b[find(i)].pb(i);
	for(int i=1;i<=n;i++){
		int k=find(i);
		if(use[k]||k==s||k==t) continue;
		if(vis[k][0]&&vis[k][1]) si++;
		else if(vis[k][0]) connect(k,0); else if(vis[k][1]) connect(k,1);
		else{puts("No");return 0;}
	}
	if(!si){
		if(!isok){puts("No");return 0;}
		if(!ds||!dt){puts("No");return 0;}
		puts("Yes");
		printf("%d %d\n",s,t);
		for(int i=0;i<ans.size();i++)
			printf("%d %d\n",ans[i].FF,ans[i].SS);
		return 0;
	}
	if(!ds||!dt){puts("No");return 0;}
	for(int i=1;i<=n;i++){
		int k=find(i);
		if(use[k]||k==s||k==t) continue;
		if(!con){
			connect(k,0);connect(k,1);
			con=1;
		}
		else if(ds)connect(k,0);
		else if(dt)connect(k,1);
		else{puts("No");return 0;}
	}
	puts("Yes");
	for(int i=0;i<n-1;i++) printf("%d %d\n",ans[i].FF,ans[i].SS);
	return 0;
}