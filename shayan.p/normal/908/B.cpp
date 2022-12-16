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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll maxn=100;

ll p[4];
ll dx[4],dy[4];
string s[maxn];
ll x,y;
ll n,m;
bool move(char ch){
	x+=dx[p[ch-'0']];
	y+=dy[p[ch-'0']];
	if(0<=x&&x<n&&0<=y&&y<m&&s[x][y]!='#')return 1;
	return 0;
}

int main(){
	dx[0]=0;dx[1]=1;dx[2]=0;dx[3]=-1;
	dy[0]=1;dy[1]=0;dy[2]=-1;dy[3]=0;
	cin>>n>>m;
	ll Xs,Ys,Xe,Ye;
	REP(i,n){
		cin>>s[i];
		REP(j,m){
			if(s[i][j]=='S'){
				Xs=i;
				Ys=j;
			}
			if(s[i][j]=='E'){
				Xe=i;
				Ye=j;
			}
		}
	}
	ll ans=0;
	string op;cin>>op;
	p[0]=0;p[1]=1;p[2]=2;p[3]=3;
	do{
		bool yes=1;
		x=Xs;
		y=Ys;
		REP(i,sz(op)){
			if(x==Xe&&y==Ye)
				break;
			if(!move(op[i])){
				yes=0;
				break;
			}
		}
		if(yes&&x==Xe&&y==Ye){
			ans++;
		}
	}while(next_permutation(p,p+4));
	cout<<ans;
}