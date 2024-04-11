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
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=2e3+10;

#pragma GCC Optimize("Ofast")

ll a[maxn];
ll cnt[maxn][3];
ll sub[maxn][maxn][3];
ll pre[maxn][maxn][3];
ll buf[maxn][maxn][3];

int main(){
	ll n;cin>>n;
	FOR(i,1,n){
		cin>>a[i];
		cnt[i][1]=cnt[i-1][1]+(a[i]==1);
		cnt[i][2]=cnt[i-1][2]+(a[i]==2);
	}
	FOR(i,1,n){
		pre[i][i][1]=1;
		pre[i][i][2]=1;
		FOR(j,i+1,n){
			FOR(k,1,2){
				pre[i][j][k]=max(pre[i][j-1][k]+(a[j]==k),cnt[j][3-k]-cnt[i-1][3-k]);
			}
		}
	}
	FORD(j,n,1){
		sub[j][j][1]=1;
		sub[j][j][2]=1;
		FORD(i,j-1,1){
			FOR(k,1,2){
				sub[i][j][k]=max(sub[i+1][j][k]+(a[i]==k),cnt[j][3-k]-cnt[i-1][3-k]);
			}
		}
	}
	FORD(i,n,1){
		buf[i][i][1]=1;
		buf[i][i][2]=1;
		FOR(j,i+1,n){
			FOR(k,1,2){
				ll A=buf[i][j-1][k]+(a[j]==k);
				ll B=buf[i+1][j][k]+(a[i]==k);
				ll C=cnt[j][3-k]-cnt[i-1][3-k];
				buf[i][j][k]=max(A,max(B,C));
			}
		}
	}
	
	ll ans=pre[1][n][2];
	FOR(i,1,n){
		ll num1=max(buf[1][i][1],buf[i+1][n][2]);
		ll num2=sub[1][i][1]+pre[i+1][n][2];
		ans=max(ans,max(num1,num2));
	}
	cout<<ans;
}