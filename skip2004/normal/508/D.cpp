#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;
const int N = 200200;

int n;
struct edge{
	int to,nxt;
}e[N<<1];
int h[N],num,tot;
int in[N],out[N];
std::map<int,int>mp;
int ip[N];
inline int pr(int a,int b){return a<<8|b;};
inline int nd(int a,int b){a=pr(a,b);return mp.count(a)?mp[a]:mp[a]=++tot;}
inline void link(int x,int y){e[++num]={y,h[x]},h[x]=num,++out[x],++in[y];}
void no(){ puts("NO");exit(0); }
std::vector<int>ans;
inline void dfs(int s){
	for(int&i=h[s];i;){
		int to=e[i].to;i=e[i].nxt;dfs(to);
	}
	ans.push_back(s);
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	rep(i, 1, n) {
		char a,b,c;
		cin >> a >> b >> c;
		link(nd(a,b),nd(b,c));
	}
	int s=0,t=0;
	rep(i,1,tot){
		if(in[i]!=out[i]){
			if(out[i]==in[i]+1){
				if(s)no();else s=i;
			} else {
				if(in[i]!=out[i]+1)no();
				if(t)no();else t=i;
			}
		}
	}
	if(!s)s=1;
	for(auto x:mp)ip[x.second]=x.first;
	dfs(s);
	if(ans.size()!=n+1)no();
	cout<<"YES\n";
	reverse(ans.begin(),ans.end());
	cout.put(ip[ans[0]]>>8);
	cout.put(ip[ans[0]]&255);
	for(int i=1;i<(int)ans.size();++i)cout.put(ip[ans[i]]&255);
}