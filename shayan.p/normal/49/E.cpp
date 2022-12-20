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

const int inf=1e9;
const int maxn=60;

#pragma GCC Optimize("Ofast")

bool cn[2][maxn][maxn][30];
int dp[maxn][maxn];
set< pair<int,pair<int,int> > >st;
bool is[30][30][30];

bool equal(int a1,int a2,int b1,int b2){
	REP(i,26)
		if(cn[0][a1][a2][i]&&cn[1][b1][b2][i])
			return 1;
	return 0;
}

void FILL(string &s,int id){
	REP(i,sz(s))
		cn[id][i][i][s[i]-'a']=1;
	FOR(j,1,sz(s)-1){
		FORD(i,j-1,0){
			FOR(p,i+1,j){
				REP(q,26){
					REP(q1,26){
						REP(q2,26){
							cn[id][i][j][q]|=(cn[id][i][p-1][q1]&&cn[id][p][j][q2]&&is[q][q1][q2]);
						}
					}
				}
			}
		}
	}
}

int main(){
	string s1,s2;cin>>s1>>s2;
	int n;cin>>n;
	REP(i,n){
		string s;cin>>s;
		is[s[0]-'a'][s[3]-'a'][s[4]-'a']=1;
	}
	FILL(s1,0);
	FILL(s2,1);
	REP(i,sz(s1)){
		REP(j,sz(s2)){
			dp[i][j]=inf;
			if(equal(0,i,0,j))
				dp[i][j]=1;
			FOR(pi,1,i){
				FOR(pj,1,j){
					if(equal(pi,i,pj,j))
						dp[i][j]=min(dp[i][j],1+dp[pi-1][pj-1]);
				}
			}
		}
	}
	cout<<(dp[sz(s1)-1][sz(s2)-1]==inf?-1:dp[sz(s1)-1][sz(s2)-1]);
}