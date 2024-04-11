// Jump, and you will find out how to unfold your wings as you fall.

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

const int maxn=2e5+10,inf=1e9,lim=2e5+10;

int n,a[maxn],up[maxn],dn[maxn];
pii nxtup[maxn],nxtdn[maxn];
bool ans[maxn];

void tell(bool b){
    cout<<"YES\n";
    for(int i=0;i<n;i++)
	cout<<(ans[i]^b)<<" ";
    cout<<endl,exit(0);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    up[n-1]=-inf,dn[n-1]=inf;
    nxtup[n-1]=nxtdn[n-1]={n,n};
    for(int i=n-2;i>=0;i--){
	up[i]=inf,dn[i]=-inf;
	if(a[i]<dn[i+1]){
	    up[i]=a[i+1],nxtup[i]={nxtdn[i+1].S,i+1};
	}
	if(a[i]>up[i+1]){
	    dn[i]=a[i+1],nxtdn[i]={nxtup[i+1].S,i+1};
	}
	if(a[i]<a[i+1]){
	    if(up[i]>up[i+1])
		up[i]=up[i+1],nxtup[i]={i+1,nxtup[i+1].S};
	}
	if(a[i]>a[i+1]){
	    if(dn[i]<dn[i+1])
		dn[i]=dn[i+1],nxtdn[i]={i+1,nxtdn[i+1].S};
	}
    }
    if(up[0]!= inf){
	int tmp=0;
	while(tmp<n)
	    ans[tmp]=1,tmp=nxtup[tmp].F;
	tell(1);
    }
    if(dn[0]!=-inf){
	int tmp=0;
	while(tmp<n)
	    ans[tmp]=1,tmp=nxtdn[tmp].F;
	tell(0);
    }
    return cout<<"NO\n",0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.