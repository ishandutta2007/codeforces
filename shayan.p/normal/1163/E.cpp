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

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

int a[maxn];
bool mark[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    
    int ans=0;
    vector<int>vans;
    
    for(int bs=1;bs<20;bs++){
	vector<int>vec;
	vector<int>inn;
	memset(mark,0,sizeof mark);
	inn.PB(0); mark[0]=1;
	
	for(int i=0;i<n;i++){
	    if(a[i]<(1<<bs) && mark[a[i]]==0){
		for(int j=sz(inn)-1;j>=0;j--)
		    mark[inn[j] ^ a[i]]=1,inn.PB(inn[j] ^ a[i]);
		int SZ=sz(vec);
		vec.PB(a[i]);
		for(int i=SZ-1;i>=0;i--)
		    vec.PB(vec[i]);
	    }
	}
	if((1<<bs)-1 == sz(vec)) vans=vec,ans=bs;
    }
    int nw=0;
    cout<<ans<<endl<<0<<" ";
    for(int x:vans){
	nw^=x;
	cout<<nw<<" ";
    }
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.