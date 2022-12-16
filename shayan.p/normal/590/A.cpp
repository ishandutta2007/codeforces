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

const int maxn=5e5+10,inf=1e9;

int a[maxn],mx;
vector<int>vec;
string ans;

void print(int n,bool x){
    for(int i=0;i<n;i++)
	ans+='0'+x,ans+=' ';
}

void solve(int n,bool x){
    mx=max(mx,(n+1)/2);
    if(n&1) print(n,x);
    else print(n/2,x),print(n/2,1-x);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    int bef=a[0],cnt=0;
    for(int i=0;i<n;i++){
	if(bef!=a[i]){
	    vec.PB(cnt);
	    cnt=0,bef=a[i];
	}
	if(bef==a[i]) cnt++;
    }
    vec.PB(cnt);
    bef=0;
    print(vec[0],a[0]);
    for(int i=1;i<sz(vec);i++){
	if(vec[i]>1 || i==sz(vec)-1){
	    solve(i-bef-1,bef & 1? 1-a[0] : a[0]);
	    print(vec[i],i & 1 ? 1-a[0] : a[0]);
	    bef=i;
	}
    }
    return cout<<mx<<endl<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.