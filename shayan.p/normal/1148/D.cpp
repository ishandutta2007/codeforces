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

vector<pair<pii,int> >v1,v2;
int n;

bool cmp(pair<pii,int>a,pair<pii,int>b){
    return a.F.S>b.F.S;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
	int a,b;cin>>a>>b;
	if(a<b) v1.PB({{a,b},i+1});
	else v2.PB({{b,a},i+1});
    }
    if(sz(v1)>sz(v2)){
	sort(v1.begin(),v1.end(),cmp);
	cout<<sz(v1)<<"\n";
	for(auto x:v1)
	    cout<<x.S<<" ";
	return cout<<endl,0;
    }
    sort(v2.begin(),v2.end(),cmp);
    reverse(v2.begin(),v2.end());
    cout<<sz(v2)<<"\n";
    for(auto x:v2)
	cout<<x.S<<" ";
    return cout<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.