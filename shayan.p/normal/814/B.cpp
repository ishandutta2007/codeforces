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
const ll maxn=1010;

ll p[2][maxn];
ll a[maxn];
ll num[maxn];
ll c1,c2;

int main(){
	ll n;cin>>n;
	REP(i,n){
		cin>>a[i];
		if(++num[a[i]]==2){
			c1=a[i];
		}
	}
	FOR(i,1,n){
		if(num[i]==0){
			c2=i;
		}
	}
	ll seen=0;
	REP(i,n){
		if(a[i]!=c1){
			p[0][i]=a[i];
			p[1][i]=a[i];
		}
		else if(a[i]==c1){
			if(seen==0){
				p[0][i]=c1;
				p[1][i]=c2;
				seen++;
			}
			else{
				p[0][i]=c2;
				p[1][i]=c1;
			}
		}
	}
	REP(i,n){
		cin>>a[i];
	}
	ll ch;
	ch=0;
	REP(i,n){
		if(p[0][i]!=a[i]){
			ch++;
		}
	}
	if(ch==1){
		REP(i,n){
			cout<<p[0][i]<<" ";
		}
		return 0;
	}
	REP(i,n){
		cout<<p[1][i]<<" ";
	}
	return 0;
}