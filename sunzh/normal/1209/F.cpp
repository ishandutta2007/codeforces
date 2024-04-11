#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,m;
int dis[2000010];
const int mod=1e9+7;
vector<int>vec[2000010][11];
queue<vector<int> >Q; 
int cnt;
void bfs(){
	vector<int>emp;emp.pb(1);
	Q.push(emp);
	dis[1]=0;
	while(!Q.empty()){
		vector<int>u=Q.front();Q.pop();
		for(int i=0;i<10;++i){
			vector<int>T;
			for(int j:u){
				for(int v:vec[j][i]) if(dis[v]<0) {dis[v]=(1ll*dis[j]*10%mod+i)%mod;T.pb(v);}
			}
			if(!T.empty()) Q.push(T);
		}
	}
}
int main(){
	memset(dis,-1,sizeof(dis));
	n=read(),m=read();
	cnt=n;
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		int t=i,tmp=v;
		while(t>=10){
			vec[++cnt][t%10].pb(v);
			v=cnt;
			t/=10;
		}
		vec[u][t%10].pb(v);
		t=i;
		while(t>=10){
			vec[++cnt][t%10].pb(u);
			u=cnt;t/=10;
		}
		vec[tmp][t%10].pb(u);
	}
	bfs();
	for(int i=2;i<=n;++i) printf("%d\n",dis[i]);
	return 0;
	/*RE.jpg*/
}