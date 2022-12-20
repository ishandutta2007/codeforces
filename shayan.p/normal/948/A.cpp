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
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll maxn=510;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

string s[maxn];
ll dx[4],dy[4];
ll n,m;

void place(ll x,ll y){
	if(x>=n||x<0||y<0||y>=m)
		return;
	if(s[x][y]=='W'){
		cout<<"No";
		exit(0);
	}
	if(s[x][y]=='.')
		s[x][y]='D';
}

int main(){
	dx[0]=1;dx[1]=0;dx[2]=-1;dx[3]=0;
	dy[0]=0;dy[1]=1;dy[2]=0;dy[3]=-1;
	cin>>n>>m;
	REP(i,n)
		cin>>s[i];
	
	REP(i,n)
		REP(j,m)
			if(s[i][j]=='S')
				REP(k,4)
					place(i+dx[k],j+dy[k]);
	cout<<"Yes\n";
	REP(i,n)
		cout<<s[i]<<endl;
}