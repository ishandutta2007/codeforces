// Can U hack it?

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

const int maxn=1010,MAX=1e4+10,mod=1e9+7;

ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}

vector<ll>dv;
int dp[MAX],bf[maxn][MAX];
ll a[maxn],A[maxn],sm[MAX];

int main(){
    int n;scanf("%d",&n);
    ll k;scanf("%lld",&k);
    for(ll i=1;(i*i)<=k;i++){
	if(k%i==0)
	    dv.PB(i);
    }
    for(int i=sz(dv)-1;i>=0;i--){
	if(dv[i]*dv[i]==k)continue;
	dv.PB(k/dv[i]);
    }
    for(int i=0;i<n;i++){
	scanf("%lld",&A[i]);
	a[i]=gcd(A[i],k);
    }
    if(a[0]>1){
	int id=lower_bound(dv.begin(),dv.end(),a[0])-dv.begin();
	dp[id]=1;
	sm[id]=A[0];
	bf[0][id]=-1;
    }
    for(int i=1;i<n;i++){
	if(a[i]==1) continue;
	for(int j=sz(dv)-1;j>=0;j--){
	    if(j>0 && dp[j]==0)continue;
	    ll num=a[i]*gcd(k/a[i],dv[j]);
	    int id=lower_bound(dv.begin(),dv.end(),num)-dv.begin();
	    if(dp[id]==0 || dp[id]>(dp[j]+1) || (dp[id]==(dp[j]+1) && sm[id]>(sm[j]+A[i]))){
		dp[id]=dp[j]+1;
		bf[i][id]=(j==0?-1:j);
		sm[id]=sm[j]+A[i];
	    }
	}
    }
    if(dp[sz(dv)-1]==0){
	int ansid=0;
	for(int i=0;i<n;i++)
	    if(A[ansid]>A[i])
		ansid=i;
	if(k==1) printf("1\n%d\n",ansid+1);
	else printf("-1\n");
	return 0;
    }
    printf("%d\n",dp[sz(dv)-1]);
    int tmp=sz(dv)-1;
    for(int i=n-1;tmp>0 && i>=0;i--)
	if(bf[i][tmp]!=0)
	    tmp=bf[i][tmp],printf("%d ",i+1);
    printf("\n");
    return 0;
}