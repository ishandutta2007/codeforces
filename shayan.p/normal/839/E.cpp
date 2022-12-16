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

const int maxn=45,MXMSK=(1<<20)+10;

ll adj[maxn],_and[MXMSK];
int dp[MXMSK];
bool is0[MXMSK],is1[MXMSK];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    bool x;cin>>x;
	    if(x) adj[i]^=(1ll<<j);
	}
    }
    int SZ=((n+1)/2);
    is0[0]=is1[0]=1;
    _and[0]=(1<<SZ)-1;
    for(int msk=1;msk<(1<<SZ);msk++){
	ll M=msk & -msk,id=__builtin_ctz(M),other=msk^M,pop=__builtin_popcount(msk);
	is0[msk]= is0[other] && (adj[id]&other)==other;
        is1[msk]= is1[other] && (adj[id+SZ]&(other<<SZ))==(other<<SZ);
	dp[msk]=(is0[msk]?pop:0);
	_and[msk]=_and[other] & adj[id+SZ];
	for(int i=0;i<SZ;i++)
	    if(bit(msk,i))
		dp[msk]=max(dp[msk],dp[msk^(1<<i)]);
    }
    int ans=0;
    for(int msk=0;msk<(1<<SZ);msk++){
	if(is1[msk])
	    ans=max(ans,__builtin_popcount(msk)+dp[_and[msk]]);
    }
    double ANS=k*k*(1-1.0/ans) /2;
    cout<<setprecision(10)<<fixed<<ANS<<endl;
    return 0;
}