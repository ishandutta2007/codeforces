#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 100000
#define Mod 1000000007
#define ll long long
struct Node{
	ll gc,tmp;
	friend bool operator <(Node p,Node q){
		return p.gc<q.gc;
	}
};
bool cmp(Node a,Node b) {
	return a.gc < b.gc;
}
vector<Node> G[Maxn+5];
vector<Node> A;
int n;
ll val[Maxn+5],ans=0;
int hd[Maxn+5],to[Maxn<<1|5],nex[Maxn<<1|5],edges;
template<typename Elem>
void read(Elem &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
void add(int u,int v){
	nex[++edges]=hd[u];
	hd[u]=edges;
	to[edges]=v;
}
ll gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
void dfs(int u,int fa){
	if(fa!=0){
		A.clear();
		for(int j=0;j<(int)G[fa].size();j++){
			A.push_back(G[fa][j]);
		}
		for(int i=0;i<(int)A.size();i++){
			A[i].gc=gcd(A[i].gc,val[u]);
		}
	}
	A.push_back((Node){val[u],1});
	sort(A.begin(),A.end());
	ll sum;
	for(int i=0,j;i<(int)A.size();i=j+1){
		j=i;
		while(j<(int)A.size()&&A[i].gc==A[j].gc){
			j++;
		}
		j--;
		sum=0;
		for(int k=i;k<=j;k++){
			sum+=A[k].tmp;
		}
		G[u].push_back((Node){A[i].gc,sum});
	}
	sort(G[u].begin(),G[u].end());
	for(int i=0;i<(int)G[u].size();i++){
		ans+=G[u][i].gc*G[u][i].tmp%Mod;
		ans%=Mod;
	}
	for(int i=hd[u];i;i=nex[i]){
		if(to[i]==fa){
			continue;
		}
		dfs(to[i],u);
	}
}
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(val[i]);
	}
	int a,b;
	for(int i=1;i<n;i++){
		read(a),read(b);
		add(a,b);
		add(b,a);
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}