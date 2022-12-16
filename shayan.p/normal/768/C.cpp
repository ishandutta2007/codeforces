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

const ll maxn=1035;

#pragma GCC Optimize("Ofast")

ll a[2][maxn];

int main(){
	ll n,k,x;cin>>n>>k>>x;
	REP(i,n){
		ll num;cin>>num;
		a[0][num]++;
	}
	ll o=1,O=0;
	REP(i,k){
		o=(i%2),O=((i+1)%2);
		bool par=0;
		
		memset(a[O],0,sizeof a[O]);
//		REP(j,1024)
//			a[O][j]=0;
			
		REP(j,1024){
			ll num=a[o][j],t_fix,t_ch;
			if(num%2){
				if(par==0){
					t_ch=(num/2)+(num%2);
					t_fix=(num/2);
				}
				else{
					t_fix=(num/2)+(num%2);
					t_ch=(num/2);
				}
				par=!par;
			}
			else{
				t_ch=t_fix=num/2;
			}
			a[O][j]+=t_fix;
			a[O][j^x]+=t_ch;
		}
	}
	ll Min,Max;
	REP(i,1024){
		if(a[O][i]>0){
			Min=i;
			break;
		}
	}
	REPD(i,1024){
		if(a[O][i]>0){
			Max=i;
			break;
		}
	}
	cout<<Max<<" "<<Min;
}