#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=20;

int n,t,cnt,mark[20];
string a,b;
vector<int> g[N];

void dfs(int x){
	mark[x]=1;
	f(i,0,g[x].size())
		if(!mark[g[x][i]])
			dfs(g[x][i]);
}
void solve(){
	cnt=0;
	f(i,0,N) g[i].clear();
	f(i,0,n){
		if(a[i]>b[i]){ cout<<-1<<endl; return ; }
		if(a[i]<b[i]) g[a[i]-'a'].pb(b[i]-'a'),g[b[i]-'a'].pb(a[i]-'a');
	}
	f(i,0,N) mark[i]=0;
	f(i,0,N)
		if(!mark[i])
			dfs(i),cnt++;
	cout<<N-cnt<<endl;
}

int main(){
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		solve();
	}
}