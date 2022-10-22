#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y)
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x)
#define gett(x) scanf("%d",&x)
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e6+99;
 
int n,t,mv,mark[N],deg[N];
vector<int> g[N];
set<int> s;

void dfs(int x){
	mark[x]=1;
	f(i,0,g[x].size()){
		if(mark[g[x][i]]==1)
			mv=1;
		if(!mark[g[x][i]])
			dfs(g[x][i]);
	}
	mark[x]=2;
}
void del(int u){
	s.erase(u);
	f(i,0,g[u].size())
		if(--deg[g[u][i]]==0){
			s.insert(g[u][i]);
		}
}

int main(){
	cin>>t;
	while(t--){
		int ans=0;
		mv=0;
		s.clear();
		cin>>n;
		f(i,0,n+1) g[i].clear(),mark[i]=0,deg[i]=0;
		f(i,1,n+1){
			int k;
			cin>>k;
			if(k==0){ s.insert(i);}
			deg[i]=k;
			f(j,0,k){
				int x;
				cin>>x;
				g[x].pb(i);
			}
		}
		f(i,1,n+1)
			if(!mark[i])
				dfs(i);
		if(mv) cout<<-1<<endl;
		else{
			int last=0;
			ans=1;
			while(s.size()){
				if(*s.rbegin()>last){
					last=*s.upper_bound(last);
					del(last);
				}
				else{
					ans++;
					last=*s.begin();
					del(last);
				}
			}
			cout<<ans<<endl;
		}
	}
}