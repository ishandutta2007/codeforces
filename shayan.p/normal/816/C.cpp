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
const ll maxn=110;

ll a[maxn][maxn];
ll c[maxn];
ll r[maxn];
ll n,m;

bool check(){
	REP(i,n){
		REP(j,m){
			if(r[i]+c[j]!=a[i][j])
				return 0;
		}
	}
	return 1;
}

struct Answer{
	ll R[maxn],C[maxn],ans;
	Answer(){
		ans=inf;
	}
	void over(ll num){
		REP(i,n)
			R[i]=r[i];
		REP(i,m)
			C[i]=c[i];
		ans=num;
	}
	void print(){
		cout<<ans<<endl;
		REP(i,n){
			REP(j,R[i]){
				cout<<"row "<<i+1<<endl;
			}
		}
		REP(i,m){
			REP(j,C[i]){
				cout<<"col "<<i+1<<endl;
			}
		}
	}
};Answer Ans;
int main(){
	cin>>n>>m;
	REP(i,n){
		REP(j,m){
			cin>>a[i][j];
		}
	}
	FOR(i,0,a[0][0]){
		ll num=0;
		bool yes=1;
		if(yes){
			REP(j,m){
				c[j]=a[0][j]-i;
				num+=c[j];
				if(c[j]<0){
					yes=0;
					break;
			 	}
			}
		}
		if(yes){
			REP(j,n){
				r[j]=a[j][0]-(a[0][0]-i);
				num+=r[j];
				if(r[j]<0){
					yes=0;
					break;
				}
			}
		}
		if(yes){
			if(num<Ans.ans&&check()){
				Ans.over(num);
			}
		}
	}
	if(Ans.ans==inf){
		cout<<-1;
		return 0;
	}
	Ans.print();
}