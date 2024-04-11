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
typedef int ll;

const ll maxn=1e5+10;
const ll SQ=350;

ll Ans[maxn][SQ];
ll a[maxn];

int main(){
	ll n;cin>>n;
	FOR(i,1,n)
		cin>>a[i];
	
	FORD(i,n,1){
		FOR(j,1,SQ){
			if(i+a[i]+j>n)
				Ans[i][j]=1;
			else
				Ans[i][j]=1+Ans[i+a[i]+j][j];
		}
	}
	
	ll q;cin>>q;
	REP(i,q){
		ll p,k;cin>>p>>k;
		if(k>SQ){
			ll num=0;
			while(p<=n){
				num++;
				p+=a[p]+k;
			}
			cout<<num<<endl;
		}
		else{
			cout<<Ans[p][k]<<endl;
		}
	}
}