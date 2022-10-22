#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())
const int mod=998244353;

string s;
int n;
const int N=2020;
vector<pair<int,int>>g[N];
void add(int a,int b,int t){
	g[a].emplace_back(b,t);
	g[b].emplace_back(a,t);
}
void ad(int&x,int y){
	 if((x+=y)>=mod)x-=mod;
}
int col[N];
int lena;
bool bad;
void dfs(int u,int c=0){
	if(col[u]==c)return;
	if(col[u]!=-1){
		bad=true;
		return ;
	}
	col[u]=c;
	for(auto&[x,y]:g[u]){
		dfs(x,c^y);
	}
}
vector<pair<int,int>>v;
int solve(){
	fill(col,col+2*n,-1);
	bad=false;
	int ansich=1;
	for(auto&[x,y]:v)
		dfs(x,y);
	for(int i=0;i<n+lena;++i)
		if(col[i]==-1){
			ad(ansich,ansich),dfs(i);
		}
//	cerr<<ansich<<'\n';
	if(bad)return 0;
	return ansich;

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	n=s.size();
	int ans=0;
	for(lena=1;lena<n;++lena){
		for(int i=0;i<n+lena;++i)g[i].clear();
		for(int i=0;i<lena-i-1;++i){
			add(i,lena-i-1,0);
		}
		v.clear();
		v.emplace_back(lena-1,1);
		for(int i=0;i<n-i-1;++i)
			add(lena+i,lena+(n-i-1),0);
		for(int i=0;i<n;++i){
			if(i<lena&&s[i]!='?')
				add(i,lena+i,s[i]-'0');
			if(i>=lena&&s[i]!='?')
				v.emplace_back(lena+i,s[i]-'0');
		}
		ad(ans,solve());
	}
	cout<<ans<<'\n';
	return 0;
}