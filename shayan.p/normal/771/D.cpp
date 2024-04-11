// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=80;

ll dp[maxn][maxn][maxn][3];
ll a[maxn],b[maxn];
ll cnt[3];

int main(){
    REP(i,maxn){
	REP(j,maxn){
	    REP(k,maxn){
		REP(w,3){
		    dp[i][j][k][w]=inf;
		}
	    }
	}
    }
    dp[0][0][0][2]=0;
    ll n;cin>>n;
    string s;cin>>s;
    FOR(i,1,n){
	if(s[i-1]=='V')
	    a[i]=0;
	else if(s[i-1]=='K')
	    a[i]=1;
	else
	    a[i]=2;
	b[i]=(++cnt[a[i]]);
    }
    FOR(i,1,n){
	FOR(v,0,cnt[0]){
	    FOR(k,0,cnt[1]){
		ll x=i-v-k,c;
		if(x<0||x>cnt[2])continue;
		if(x!=0){
		    c=0;
		    FOR(w,1,n){
			if(a[w]==2&&b[w]==x)break;
			c+=(a[w]==0&&b[w]>v)||(a[w]==1&&b[w]>k);
		    }
		    dp[i][v][k][2]=min(dp[i-1][v][k][0],min(dp[i-1][v][k][1],dp[i-1][v][k][2]))+c;
		}
		if(k!=0){
		    c=0;
		    FOR(w,1,n){
			if(a[w]==1&&b[w]==k)break;
			c+=(a[w]==0&&b[w]>v)||(a[w]==2&&b[w]>x);
		    }
		    dp[i][v][k][1]=min(dp[i-1][v][k-1][1],dp[i-1][v][k-1][2])+c;
		}
		if(v!=0){
		    c=0;
		    FOR(w,1,n){
			if(a[w]==0&&b[w]==v)break;
			c+=(a[w]==1&&b[w]>k)||(a[w]==2&&b[w]>x);
		    }
		    dp[i][v][k][0]=min(dp[i-1][v-1][k][0],min(dp[i-1][v-1][k][1],dp[i-1][v-1][k][2]))+c;
		}
	    }
	}
    }

    ll ans=min(dp[n][cnt[0]][cnt[1]][0],min(dp[n][cnt[0]][cnt[1]][1],dp[n][cnt[0]][cnt[1]][2]));
    cout<<ans;
}