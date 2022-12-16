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

const int maxn=1e4+10;
const int p0=911382323;
const int p1=972663749;

#pragma GCC Optimize("Ofast")
#pragma GCC Optimize("O3")

stack<int>s[maxn][2];
bool ans[maxn];
int dp[maxn][2];
int cnt;

bool is_zero(int ind){
	return ((dp[ind][0]%p0==0)&&(dp[ind][1]%p1==0));
}

void zero(int ind){
	dp[ind][0]=dp[ind][1]=0;
}

void add(int ind1,int ind2){
	dp[ind1][0]=(dp[ind1][0]+dp[ind2][0])%p0;
	dp[ind1][1]=(dp[ind1][1]+dp[ind2][1])%p1;
}

void sub(int ind1,int ind2){
	dp[ind1][0]=(dp[ind1][0]-dp[ind2][0]+p0)%p0;
	dp[ind1][1]=(dp[ind1][1]-dp[ind2][1]+p1)%p1;
}

int main(){
	int n,q;cin>>n>>q;
	REP(i,q){
		int l,r,x;cin>>l>>r>>x;
		s[l][0].push(x);
		s[r+1][1].push(x);
	}
	
	dp[0][0]=dp[0][1]=1;
	FOR(i,1,n){
		while(sz(s[i][1])){
			int x=s[i][1].top();
			s[i][1].pop();
			FOR(j,1,n){
				if(j>=x)
					sub(j,j-x);
			}
		}
		while(sz(s[i][0])){
			int x=s[i][0].top();
			s[i][0].pop();
			FORD(j,n,1){
				if(j>=x&&!is_zero(j-x)){
					cnt+=(ans[j]==0);
					ans[j]=1;
					add(j,j-x);
				}
			}
		}
	}
	
	cout<<cnt<<endl;
	FOR(i,1,n){
		if(ans[i])
			cout<<i<<" ";
	}
}