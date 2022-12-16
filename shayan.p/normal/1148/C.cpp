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

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

vector<pii>ans;
int a[maxn],pos[maxn],n;

void Swap(int i,int j){
    if(i==j) return;
    ans.PB({i,j});
    pos[a[i]]=j;
    pos[a[j]]=i;
    swap(a[i],a[j]);
}

void f(int x){
    if(pos[x]<=(n/2)) Swap(pos[x],n);
    else Swap(1,pos[x]),Swap(1,n);
    if(x<=(n/2)) { Swap(x,n); return; }
    Swap(1,n); Swap(1,x);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
	cin>>a[i],pos[a[i]]=i;
    }
    int mid=n/2;
    for(int i=max(mid,2);i<n;i++){
	f(i);
    }
    for(int i=min(mid-1,n-1);i>1;i--){
	f(i);
    }
    if(a[1]!=1) Swap(1,n);
    cout<<sz(ans)<<"\n";
    for(pii p:ans)
	cout<<p.F<<" "<<p.S<<"\n";
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.