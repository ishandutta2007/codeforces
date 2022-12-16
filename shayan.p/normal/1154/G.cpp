// Faster!

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

const int maxn=1e7+10;

int p[maxn][2];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
	int x;cin>>x;
	if(p[x][0]==0) p[x][0]=i;
	else p[x][1]=i;
    }
    ll ans=1e18;
    int ansa,ansb;
    for(int i=1;i<maxn;i++){
	int A=-1,B=-1,aid,bid;
	for(int j=i;j<maxn;j+=i){
	    for(int k=0;k<2 && p[j][k]!=0;k++){
		if(A==-1) A=j,aid=p[j][k];
		else if(B==-1) B=j,bid=p[j][k];
		else if(A>j) B=A,bid=aid,A=j,aid=p[j][k];
		else if(B>j) B=j,bid=p[j][k];
	    }
	}
	if(A!=-1 && B!=-1 && ans>(1ll*A*B /i)){
	    ans=1ll*A*B /i;
	    ansa=aid,ansb=bid;
	}
    }
    if(ansa>ansb) swap(ansa,ansb);
    return cout<<ansa<<" "<<ansb<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.