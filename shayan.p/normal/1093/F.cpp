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

const int maxn=1e5+10,maxk=105,mod=998244353;

int a[maxn],sp[20][maxn],dp[maxn][maxk];

struct fenwick{
    int sm[maxn];
    void add(int ind,int x){
	while(ind<maxn)
	    sm[ind]=(sm[ind]+x)%mod,ind+=(ind & -ind);
    }
    int ask(int ind){
	int ans=0;
	while(ind>0)
	    ans=(ans+sm[ind])%mod,ind-=(ind & -ind);
	return ans;
    }
    int ask(int l,int r){
	if(l>r) return 0;
	return (ask(r)-ask(l-1)+mod)%mod;
    }
};fenwick fn[maxk];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n,k,ln;cin>>n>>k>>ln;
    --ln;
    for(int i=1;i<=n;i++){
	cin>>a[i];
	sp[0][i]=a[i];
    }
    for(int i=1;i<20;i++){
	for(int j=1;j<=n;j++){
	    int A=sp[i-1][j],B=sp[i-1][min(j+(1<<(i-1)),n)];
	    if(A==-2 || B==-2) sp[i][j]=-2;
	    else if(A!=-1 && B!=-1 && A!=B) sp[i][j]=-2;
	    else if(A==-1 && B==-1) sp[i][j]=-1;
	    else if(A==-1) sp[i][j]=B;
	    else sp[i][j]=A;
	}
    }
    fn[k+1].add(n+1,1);
    for(int i=n;i>=1;i--){
	int pos1=i,col=-1;
	for(int j=19;j>=0;j--){
	    if(pos1+(1<<j)<=n+1 && sp[j][pos1]!=-2 && (sp[j][pos1]==-1 || col==-1 || sp[j][pos1]==col)){
		if(col==-1) col=sp[j][pos1];
		pos1+=(1<<j);
	    }
	}
	int pos2=i;
	for(int j=19;j>=0;j--){
	    if(pos2+(1<<j)<=n+1 && sp[j][pos2]==-1)
		pos2+=(1<<j);
	}
	if(col!=-1){
	    for(int j=1;j<=k;j++){
		if(j!=col){
		    dp[i][j]=(fn[k+1].ask(i+1,min(i+ln,pos2))-fn[j].ask(i+1,min(i+ln,pos2))) %mod;
		}
	    }
	    dp[i][col]=(fn[k+1].ask(i+1,min(i+ln,pos1))-fn[col].ask(i+1,min(i+ln,pos1))) %mod;
	}
	else{
	    for(int j=1;j<=k;j++){
		dp[i][j]=(fn[k+1].ask(i+1,min(i+ln,pos2))-fn[j].ask(i+1,min(i+ln,pos2)))%mod;
	    }
	}
	for(int j=1;j<=k;j++){
	    dp[i][k+1]=(dp[i][k+1]+dp[i][j])%mod;
	    fn[j].add(i,dp[i][j]);
	}
	fn[k+1].add(i,dp[i][k+1]);
    }
    cout<<(dp[1][k+1]+mod)%mod<<endl;
    return 0;
}