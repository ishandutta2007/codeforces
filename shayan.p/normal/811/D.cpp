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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll maxn=110;

char r,l,u,d;
ll x,y;
char s[maxn][maxn];
stack<pll>st;
ll dx[5],dy[5];
ll n,m;
bool mark[maxn][maxn];
bool dfs(ll a,ll b){
	mark[a][b]=1;
	if(s[a-1][b-1]=='F'){
		st.push(MP(a,b));
		return 1;
	}
	REP(i,4){
		ll A=a+dx[i],B=b+dy[i];
		if(1<=A&&A<=n&&1<=B&&B<=m&&s[A-1][B-1]!='*'&&!mark[A][B]){
			if(dfs(A,B)==1){
				st.push(MP(A,B));
				return 1;
			}
		}
	}
	return 0;
}

char direction(pll a,pll b){
	REP(i,4){
		if(a.F+dx[i]==b.F&&a.S+dy[i]==b.S){
			if(i==0)return r;
			if(i==1)return u;
			if(i==2)return l;
			if(i==3)return d;
		}
	}
}
void Move(char ch){
	cout<<ch<<endl;
	cin>>x>>y;
	if(s[x-1][y-1]=='F')
	exit(0);
}
int main(){
	r='R';l='L';u='U';d='D';
	dx[0]=0;dx[1]=-1;dx[2]=0;dx[3]=1;
	dy[0]=1;dy[1]=0;dy[2]=-1;dy[3]=0;
	cin>>n>>m;
	REP(i,n)
		cin>>s[i];
	if(s[0][0]=='F')
		exit(0);
	if(n==1){
		Move('R');
		if(x==1&&y==1)
			swap(l,r);
		while(true)
			Move(r);
	}
	if(m==1){
		Move('D');
		if(x==1&&y==1)
			swap(u,d);
		while(true)
			Move(d);
	}
	if(s[1][0]!='*'){
		Move('D');
		if(x==1&&y==1)
			swap(u,d);
		else
			Move('U');
		while(s[x-1][1]=='*')
			Move(d);
		Move('R');
		if(y==1)
			swap(r,l);
	}
	else{
		Move('R');
		if(x==1&&y==1){
			swap(l,r);
		}
		else{
			Move('L');
		}
		while(s[1][y-1]=='*')
			Move(r);
		Move('D');
		if(x==1)
			swap(d,u);
	}
	dfs(x,y);
	while(sz(st)){
		if(MP(x,y)==st.top()){
			st.pop();
			continue;
		}
		Move(direction(MP(x,y),st.top()));
		st.pop();
	}
}