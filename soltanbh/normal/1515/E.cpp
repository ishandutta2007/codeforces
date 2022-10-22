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

const int N=405;

int n,mod,ans,dp[N][N],g[N],C[N][N];

int main(){
	cin>>n>>mod;
	f(i,0,N){
        C[0][i]=1;
        f(j,1,i+1){
            C[j][i]=(C[j][i-1]+C[j-1][i-1])%mod;
        }
    }
	f(i,1,n+1)
	    f(j,1,i+1)
	        Add(g[i],C[j-1][i-1]);
	f(i,1,n+1){
	    f(j,1,i+1){
	        for(int k=1;k<=j && 1<i-k;k++){
	            Add(dp[i][j],1ll*dp[i-k-1][j-k]*g[k]%mod*C[k][j]%mod);
	        }
	        if(i==j)
	            dp[i][j]=g[j];
	        if(i==n){
	            Add(ans,dp[i][j]);
	        }
	        //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
	    }
	}
	cout<<ans;
}