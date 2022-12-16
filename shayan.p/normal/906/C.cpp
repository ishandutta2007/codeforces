// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;

typedef unsigned short uns;
typedef unsigned int uni;

const uns maxn=24;
bool adj[maxn][maxn];
uni msk;
uns vis;
bool mark[maxn];
uns n,m;
uns ans;
uni ans_msk;

void dfs(uns u){
	mark[u]=1;vis++;
	if(!bit(msk,u))
		return;
	REP(i,n){
		if(adj[u][i])
			if(!mark[i])
				dfs(i);	
	}
}

void print(){
	cout<<ans<<endl;
	REP(i,n)
		if(bit(ans_msk,i))
			cout<<i+1<<" ";
}

int main(){
	cin>>n>>m;
	REP(i,m){
		uns a,b;cin>>a>>b;
		a--;b--;
		adj[a][b]=adj[b][a]=1;
	}
	if(m==((n*(n-1))/2)){
		print();
		return 0;
	}
	ans=200;
	FOR(i,1,(1<<n)-1){
		uni cop=i;
		uns cnt=0,lst,tot=0;
		while(cop>0){
			if(cop%2)
				lst=tot;
			tot++;
			cnt+=(cop%2);
			cop/=2;
		}
		
		if(cnt>=ans)
			continue;
			
		memset(mark,0,sizeof mark);
		msk=i;vis=0;
		dfs(lst);
		if(vis==n){
			ans=cnt;
			ans_msk=i;
		}
	}
	print();
}