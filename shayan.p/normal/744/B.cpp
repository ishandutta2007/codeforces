// new day,new strength,new thougts

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
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1010;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll a[maxn][10][2],n;
vector<ll>v;

void ask(ll x,ll y){
	if(sz(v)==0)return;
	cout<<sz(v)<<endl;
	REP(i,sz(v))
		cout<<v[i]<<" ";
	cout<<endl;
	FOR(i,1,n)
		cin>>a[i][x][y];
}

int main(){
	REP(i,maxn){
		REP(j,10){
			REP(k,2){
				a[i][j][k]=inf;
			}
		}
	}
	
			
	cin>>n;
	REP(i,10){
		REP(j,2){
			v.clear();
			FOR(k,1,n){
				if(bit(k,i)==j)
					v.PB(k);
			}
			ask(i,j);
		}
	}
	cout<<-1<<endl;
	FOR(i,1,n){
		ll num=inf;
		REP(j,10)
			num=min(num,a[i][j][!bit(i,j)]);
		cout<<num<<" ";
	}
}