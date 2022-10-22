#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<bitset>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n;
typedef bitset<165> node;
struct cmp{
	const bool operator ()(node a,node b)const{
		node c=a^b;int p=c._Find_first();
		if(p==c.size()) return 0;else return a[p]<b[p];
	}
};
map<node,int,cmp>Map;
int cnt;
node p[40010];
int new_node(node a){
	if(Map.count(a)) return Map[a];
	else{
		p[++cnt]=a;Map[a]=cnt;return cnt;
	}
}
int go[40010][11];
int dis[40010];
int dp[40010][19];
void getstate(){
	node s;s.reset();s[0]=1;
	queue<int>Q;Q.push(new_node(s));
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		if(dis[u]>=18) break ;
		for(int i=1;i<10;++i){
			node t=(p[u]|(p[u]<<i));
			if(Map.count(t)) continue ;
			else {
				int v=new_node(t);dis[v]=dis[u]+1;
				Q.push(v);
			}
		}
	}
	for(int i=1;i<=cnt&&dis[i]<18;++i){
		// cerr<<i<<"\n";
		for(int j=0;j<=9;++j) go[i][j]=new_node(p[i]|(p[i]<<j));
	}
}
int ans[50010];
struct qry{
	int l,r,id;
};
vector<qry>vec[11];
int getv(int x){
	node u=p[x];
	int lst=u._Find_first();
	while(1){
		int i=u._Find_next(lst);
		if(i==u.size()) break ;lst=i;
	}
	int t=u._Find_first();
	if(t>(lst>>1)){
		return lst;
	}
	while(1){
		int i=u._Find_next(t);
		if(i>(lst>>1)) break ;
		t=i;
	}
	return lst-2*t;
}
void getdp(int k){
	for(int i=1;i<=cnt;++i){
		memset(dp[i],0,sizeof(dp[i]));
		dp[i][0]=(getv(i)<=k);
	}
	for(int j=1;j<=18;++j){
		for(int i=cnt;i>=1;--i){
			for(int x=0;x<=9;++x){
				(dp[i][j]+=dp[go[i][x]][j-1]);
			}
		}
	}
}
int query(int x){
	int p=1;
	vector<int>v;
	while(x){
		v.pb(x%10);x/=10;
	}
	int ret=0;
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size();++i){
		for(int j=0;j<v[i];++j){
			ret+=dp[go[p][j]][v.size()-i-1];
		}p=go[p][v[i]];
	}
	return ret+dp[p][0];
}
signed main(){
	n=read();
	getstate();
	for(int i=1;i<=n;++i){
		int l=read(),r=read(),k=read();
		vec[k].pb(qry{l,r,i});
	}
	// cerr<<cnt<<"\n";
	for(int i=0;i<10;++i){
		getdp(i);
		for(qry j:vec[i]){
			ans[j.id]=query(j.r)-query(j.l-1);
		}
	}
	for(int i=1;i<=n;++i) printf("%lld\n",ans[i]);
}