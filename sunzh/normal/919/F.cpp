#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
struct node{
	int a[8],b[8];
	long long hsh;
	bool operator <(const node &y)const{
		return hsh<y.hsh;
	}
};
map<node,int>Map;
int cnt;
node s[500010];
int SG[500010];
bool f;
int a[8],b[8];
vector<int>vec[500010],rev[500010];
long long qp(long long x,int k){
	long long res=1;
	while(k){ if(k&1) res=res*x; x=x*x; k>>=1;}
	return res;
}
long long HAS(node st){
	long long hsh=0;
	for(int i=0;i<8;++i) hsh+=st.a[i]*qp(8,i)+st.b[i]*qp(8,i+8);
	return hsh;
}
void check(){
	node st;
	for(int i=0;i<8;++i) st.a[i]=a[i],st.b[i]=b[i];
	st.hsh=HAS(st);
	if(!Map.count(st)) Map[st]=++cnt,s[cnt]=st;
}
void dfs(int x,int mx){
	// printf("x:%d,mx:%d\n",x,mx);
	if(x==16){
		check();return ;
	}
	if(x<8){
		for(int i=mx;i<=4;++i){
			a[x]=i;dfs(x+1,i);
		}
	}
	else{
		if(x==8) mx=0;
		for(int i=mx;i<=4;++i){
			b[x-8]=i;dfs(x+1,i);
		}
	}
}
int out[500010];
void prework(){
	dfs(0,0);
	queue<int>Q;
	for(int i=1;i<=cnt;++i){
		if(s[i].a[7]==0) SG[i]=1,Q.push(i);
		else if(s[i].b[7]==0) SG[i]=0,Q.push(i);
		else{
			for(int p1=7;p1>=0;--p1) if(s[i].a[p1]){
				for(int p2=7;p2>=0;--p2) if(s[i].b[p2]){
					node nw=s[i];
					nw.a[p1]=(nw.a[p1]+nw.b[p2])%5;
					sort(nw.a,nw.a+8);
					swap(nw.a,nw.b);
					nw.hsh=HAS(nw);
					vec[i].pb(Map[nw]);rev[Map[nw]].pb(i);++out[i];
				}
			}
		}
	}
	// printf("holyshit\n");
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		for(int v:rev[u]) if(SG[v]==-1){
			if(SG[u]==0){
				SG[v]=1;Q.push(v);
			}
			else {
				--out[v];
				if(!out[v]) SG[v]=0,Q.push(v);
			}
		}
	}
}
int main(){
	memset(SG,-1,sizeof(SG));
	T=read();
	prework();
	while(T--){
		f=read();
		for(int i=0;i<8;++i) a[i]=read();
		for(int i=0;i<8;++i) b[i]=read();
		sort(a,a+8);sort(b,b+8);
		if(f) swap(a,b);
		node st;for(int i=0;i<8;++i) st.a[i]=a[i],st.b[i]=b[i];st.hsh=HAS(st);
		int t=SG[Map[st]];
		if(t==-1) printf("Deal\n");
		else if(t>0) printf(f?"Bob\n":"Alice\n");
		else printf(f?"Alice\n":"Bob\n");
	}
}