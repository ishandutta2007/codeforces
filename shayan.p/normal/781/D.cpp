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
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=510;
const ll mod=1e9+7;
const ll MAXLG=61;
const ll Big=1e18+1;

bitset<maxn> dp[MAXLG][2][maxn],is1,is2,vert[maxn];
ll n,m;

void mul(bitset<maxn>*a,bitset<maxn>*b,bitset<maxn>*c){
	REP(i,n)
		REP(j,n)
			vert[i][j]=c[j][i];
	REP(i,n)
		REP(j,n)
			a[i][j]=((b[i]&vert[j])!=0);
}

bool check(ll num){
	is1.reset();
	is1[0]=1;
	ll bef=0;
	REPD(i,MAXLG){
		if(bit(num,i)){
			is2.reset();
			REP(a,n){
				REP(b,n){
					if(is1[a]&&dp[i][bef%2][a][b])
						is2[b]=1;
				}
			}
			REP(a,n)
				is1[a]=is2[a];
			bef++;
		}
	}
	REP(i,n)
		if(is1[i])
			return 1;
	return 0;
}

int main(){
	cin>>n>>m;
	REP(i,m){
		ll a,b,t;cin>>a>>b>>t;
		a--;b--;
		dp[0][t][a][b]=1;
	}
	FOR(lg,1,MAXLG-1){
		REP(t,2){
			mul(dp[lg][t],dp[lg-1][t],dp[lg-1][1-t]);
		}
	}
	ll l=0,r=Big,ans=0;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	if(ans==Big)
		cout<<-1;
	else
		cout<<ans;
}