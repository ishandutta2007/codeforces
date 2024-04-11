// Phoenix

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=153,mod=51123987;

int dp[3][maxn][maxn][maxn],tmp[maxn][maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    for(int i=0;i<n;i++){
	memset(tmp,0,sizeof tmp);
	tmp[0][0][0]=1;
	for(int A=s[i]=='a';A<=n;A++){
	    for(int B=s[i]=='b';A+B<=n;B++){
		for(int C=s[i]=='c';A+B+C<=n;C++){
		    if(s[i]=='a') tmp[A][B][C]=(tmp[A-1][B][C]+dp[1][A-1][B][C]+dp[2][A-1][B][C])%mod;
		    if(s[i]=='b') tmp[A][B][C]=(tmp[A][B-1][C]+dp[0][A][B-1][C]+dp[2][A][B-1][C])%mod;
		    if(s[i]=='c') tmp[A][B][C]=(tmp[A][B][C-1]+dp[0][A][B][C-1]+dp[1][A][B][C-1])%mod;
		}
	    }
	}
	for(int A=s[i]=='a';A<=n;A++){
	    for(int B=s[i]=='b';A+B<=n;B++){
		for(int C=s[i]=='c';A+B+C<=n;C++){
		    dp[s[i]-'a'][A][B][C]=tmp[A][B][C];
		}
	    }
	}
    }
    int ans=0;
    for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
	    for(int k=0;k<=n;k++)
		if(abs(i-j)<=1 && abs(j-k)<=1 && abs(k-i)<=1 && i+j+k==n)
		    ans=(ans+dp[0][i][j][k]+dp[1][i][j][k]+dp[2][i][j][k])%mod;
    cout<<ans<<endl;
    return 0;
}