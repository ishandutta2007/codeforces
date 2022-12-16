// High above the clouds there is a rainbow...

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

const int maxn=1010,mod=1e9+7;
const ll inf=1e18;

int a[maxn],b[maxn],cnt;
pii p[maxn];

int pa[maxn],posa[maxn],pb[maxn],posb[maxn];

void Swap(int *arr,int *arrp,int i,int j){
    arrp[arr[i]]=j;
    arrp[arr[j]]=i;
    swap(arr[i],arr[j]);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
	int x;cin>>x; a[x]=i;
	pa[i]=pb[i]=posa[i]=posb[i]=i;
    }
    for(int i=1;i<=n;i++){
	int x;cin>>x; b[x]=i;
    }
    for(int i=1;i<=n;i++){
	p[i]={posa[a[i]], posb[b[i]] };
	Swap(pa,posa,i,posa[a[i]]);
	Swap(pb,posb,i,posb[b[i]]);
	cnt+= p[i].F!=i || p[i].S!=i;
    }
    cout<<cnt<<"\n";
    for(int i=1;i<=n;i++){
	if(p[i].F!=i || p[i].S!=i)
	    cout<<p[i].F<<" "<<i<<" "<<i<<" "<<p[i].S<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.