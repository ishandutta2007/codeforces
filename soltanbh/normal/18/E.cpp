#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=505;

int n,m,t,ans=N*N,u,v,dp[N][26][26];
pair<int,int> par[N][26][26];
string s[N];

int calc(int col,int x,int y){
	int res=0;
	f(i,0,m){
		if(i%2==0) res+=(s[col][i]!=char(x+'a'));
		else res+=(s[col][i]!=char(y+'a'));
	}
	return res;
}
int main(){
	cin>>n>>m;
	f(i,1,n+1)
		cin>>s[i];
	f(i,1,n+1){
		f(j,0,26)
			f(k,0,26){
				dp[i][j][k]=N*N;
				if(j!=k){
					f(a1,0,26)
						f(a2,0,26)
							if(a1!=a2 && a1!=j && a2!=k && dp[i-1][a1][a2]<dp[i][j][k])
								dp[i][j][k]=dp[i-1][a1][a2],par[i][j][k]=mp(a1,a2);
					dp[i][j][k]+=calc(i,j,k);
				}
			}
	}
	f(i,0,26)
		f(j,0,26)
			if(dp[n][i][j]<ans){
				ans=dp[n][i][j];
				u=i,v=j;
			}
	f_(i,n,1){
		pair<int,int> io=par[i][u][v];
		f(j,0,m){
			if(j%2==0) s[i][j]=char(u+'a');
			else s[i][j]=char(v+'a');
		}
		u=io.F,v=io.S;	
	}
	cout<<ans<<endl;
	f(i,1,n+1){
		f(j,0,m)
			cout<<s[i][j];
		cout<<endl;
	}
}