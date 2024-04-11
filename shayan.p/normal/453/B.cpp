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

const int maxn=110,CNTP=16,MAX=59,inf=1e9;

int dp[maxn][(1<<CNTP)+10],pr[maxn][(1<<CNTP)+10],ans[maxn],a[maxn];
int MASK[maxn],C;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    for(int i=2;i<MAX;i++){
	if(MASK[i]==0){
	    for(int j=i;j<MAX;j+=i)
		MASK[j]|=(1<<C);
	    C++;
	}
    }
    int n;cin>>n;
    for(int i=1;i<=n;i++){
	cin>>a[i];
    }
    for(int i=1;i<=n;i++){
	for(int j=0;j<(1<<C);j++){
	    dp[i][j]=inf;
	    for(int k=1;k<MAX;k++){
		if((MASK[k] & j)==MASK[k] && dp[i][j]>(dp[i-1][j^MASK[k]]+abs(k-a[i]))){
		    dp[i][j]=dp[i-1][j^MASK[k]]+abs(k-a[i]);
		    pr[i][j]=k;
		}
	    }
	}
    }
    int tmp=(1<<C)-1;
    for(int i=n;i>0;i--){
	ans[i]=pr[i][tmp];
	tmp^=MASK[pr[i][tmp]];
    }
    for(int i=1;i<=n;i++){
	cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;		   
}