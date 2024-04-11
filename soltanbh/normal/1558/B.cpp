#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
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

const int N=4e6+99;

int n,x,mod,sum,dp[N],d[N];
vector<int> v[N];

int main(){
   f(i,1,N){
      if(d[i]==0) d[i]=i;
      for(int j=2*i;j<N;j+=i)
         if(d[j]==0)
            d[j]=i;
   }
	cin>>n>>mod;
	dp[1]=1;
	sum=1;
   f(i,2,n+1){
      Add(dp[i],2ll*dp[i-1]%mod+1);
      if(i==2) Add(dp[i],mod-1);
      for(int j=i*2;j<=n;j+=i){
         Add(dp[j],dp[i]);
         Add(dp[j],mod-dp[i-1]);
      }
      Add(sum,dp[i]);
      //cout<<dp[i]<<endl;
	}
	cout<<dp[n];
}