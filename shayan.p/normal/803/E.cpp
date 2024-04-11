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

const ll maxn=1e3+10;

bool dp[maxn][2*maxn];
ll k,n;

inline ll hf(ll num){
	return num+k;
}

int main(){
	cin>>n>>k;
	string s;cin>>s;
	dp[0][hf(0)]=1;
	FOR(i,1,n){
		if(s[i-1]=='?')
			FOR(j,(-k+1),(k-1))
				dp[i][hf(j)]=(dp[i-1][hf(j)]|dp[i-1][hf(j-1)]|dp[i-1][hf(j+1)]);
		if(s[i-1]=='W')
			FOR(j,(-k+1),(k-1))
				dp[i][hf(j)]=dp[i-1][hf(j-1)];
		if(s[i-1]=='L')
			FOR(j,(-k+1),(k-1))
				dp[i][hf(j)]=dp[i-1][hf(j+1)];
		if(s[i-1]=='D')
			FOR(j,(-k+1),(k-1))
				dp[i][hf(j)]=dp[i-1][hf(j)];
	}
	bool pos_end_pos,pos_end_neg;
	if(s[n-1]=='?')
		pos_end_pos=(dp[n-1][hf(k)]|dp[n-1][hf(k-1)]|dp[n-1][hf(k+1)]);
	if(s[n-1]=='W')
		pos_end_pos=dp[n-1][hf(k-1)];
	if(s[n-1]=='L')
		pos_end_pos=dp[n-1][hf(k+1)];
	if(s[n-1]=='D')
		pos_end_pos=dp[n-1][hf(k)];
	
	
	if(s[n-1]=='?')
		pos_end_neg=(dp[n-1][hf(-k)]|dp[n-1][hf(-k-1)]|dp[n-1][hf(-k+1)]);
	if(s[n-1]=='W')
		pos_end_neg=dp[n-1][hf(-k-1)];
	if(s[n-1]=='L')
		pos_end_neg=dp[n-1][hf(-k+1)];
	if(s[n-1]=='D')
		pos_end_neg=dp[n-1][hf(-k)];
	
	ll score;
	if(!pos_end_pos&&!pos_end_neg){
		cout<<"NO";
		return 0;
	}
	if(pos_end_pos)
		score=k;
	else
		score=-k;
		
	////////////////////////end of the preprocess
	FORD(i,n,1){
		if(s[i-1]=='?'){//at least one is possible
			if(dp[i-1][hf(score)])s[i-1]='D';
			if(dp[i-1][hf(score-1)])s[i-1]='W';
			if(dp[i-1][hf(score+1)])s[i-1]='L';
		}//we want it to go to other if s after finishing here
		if(s[i-1]=='W'){
			score--;
		}
		if(s[i-1]=='L'){
			score++;
		}
		if(s[i-1]=='D'){
		}
	}
	
	REP(i,n){
		cout<<s[i];
	}
}