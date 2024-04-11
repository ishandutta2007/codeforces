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

const int maxn=2e5+10,mod=1e9+7;
const ll inf=1e18;

int N,n;
int ans[4*maxn],ansl[4*maxn],ansr[4*maxn],pl[4*maxn],pr[4*maxn],sm[4*maxn],tot[4*maxn];
int arr[maxn];

void Merge(int id){
    pl[id]=max(pl[2*id],-sm[2*id]+pl[2*id+1]);
    pr[id]=max(pr[2*id+1],sm[2*id+1]+pr[2*id]);
    tot[id]=max(sm[2*id]+tot[2*id+1], tot[2*id]-sm[2*id+1]);
    ansl[id]=max(ansl[2*id], max( tot[2*id]+pl[2*id+1], sm[2*id]+ansl[2*id+1]) );
    ansr[id]=max(ansr[2*id+1], max( tot[2*id+1]+pr[2*id], -sm[2*id+1]+ansr[2*id]) ); 
    sm[id]=sm[2*id]+sm[2*id+1];
    ans[id]=max(ans[2*id],ans[2*id+1]);
    ans[id]=max(ans[id], pr[2*id]+ansl[2*id+1]);
    ans[id]=max(ans[id], ansr[2*id]+pl[2*id+1]);
}
void change(int pos,int x,int l=0,int r=N,int id=1){
    if(r-l==1){
	ans[id]=ansl[id]=ansr[id]=tot[id]=abs(x);
	pl[id]=-x, pr[id]=x;
	sm[id]=x;
	return;
    }
    int mid=(l+r)>>1;
    if(pos<mid) change(pos,x,l,mid,2*id);
    else        change(pos,x,mid,r,2*id+1);
    Merge(id);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q;cin>>n>>q;
    N=2*(n-1);
    string s;cin>>s;
    for(int i=0;i<N;i++){
	arr[i]=(s[i]=='('?-1:1);
	change(i,arr[i]);
    }
    cout<<ans[1]<<"\n";
    while(q--){
	int a,b;cin>>a>>b; --a,--b;
	swap(arr[a],arr[b]);
	change(a,arr[a]);
	change(b,arr[b]);
	cout<<ans[1]<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.