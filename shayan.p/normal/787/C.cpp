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
typedef long double ld;
typedef pair<ll,ll> pll;

const ll mod=1e9+7;
const ll maxn=7e3+10;

int rick[maxn],morty[maxn];// win loose
bool sr[maxn],sm[maxn];
int wdr[maxn],wdm[maxn],ldr[maxn],ldm[maxn];
int main(){
	ll n;cin>>n;
	ll k1,k2;
	cin>>k1;
	REP(i,k1){
		ll x;cin>>x;
		sr[x]=1;
	}
	cin>>k2;
	REP(i,k2){
		ll x;cin>>x;
		sm[x]=1;
	}
		
	rick[0]=1;
	morty[0]=1;// loose
	FOR(i,1,n-1){
		ldr[i]+=sr[n-i];
		ldm[i]+=sm[n-i];
	}
	
	REP(q,2*n+10){// for being sure+1
		if(q%2){//loose check
			FOR(i,1,n-1){
				if(morty[i]==0){
					if(wdm[i]==k2){
						morty[i]=1;// loose
						FOR(j,1,n-1)
							ldr[j]+=sr[(((i-j)%n)+n)%n];
					}
				}
				if(rick[i]==0){
					if(wdr[i]==k1){
						rick[i]=1;// loose
						FOR(j,1,n-1)
							ldm[j]+=sm[(((i-j)%n)+n)%n];
					}
				}
			}
		}
		else{// win check
			FOR(i,1,n-1){
				if(morty[i]==0){
					if(ldm[i]){
						morty[i]=2;// win
						FOR(j,1,n-1)
							wdr[j]+=sr[(((i-j)%n)+n)%n];
					}
				}
				if(rick[i]==0){
					if(ldr[i]){
						rick[i]=2;// win
						FOR(j,1,n-1){
							wdm[j]+=sm[(((i-j)%n)+n)%n];
						}
					}
				}
			}
		}
	}
		
	FOR(i,1,n-1){
		if(rick[i]==0){
			cout<<"Loop ";
		}
		if(rick[i]==1){
			cout<<"Lose ";
		}
		if(rick[i]==2){
			cout<<"Win ";
		}
	}
	cout<<endl;
	FOR(i,1,n-1){
		if(morty[i]==0){
			cout<<"Loop ";
		}
		if(morty[i]==1){
			cout<<"Lose ";
		}
		if(morty[i]==2){
			cout<<"Win ";
		}
	}
}