// Wanna Hack? GL...

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

pii p[maxn];
bool a[maxn];
vector<int>v;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    for(int i=0;i<n;i++){
	cin>>p[i].F;
	p[i].S=i;
    }
    sort(p,p+n,greater<pii>());
    ll sm=0;
    for(int i=0;i<k*m;i++){
	a[p[i].S]=1;
	sm+=p[i].F;
    }
    int cnt=0;
    for(int i=0;i<n;i++){
	cnt+=a[i];
	if(cnt==m) v.PB(i+1),cnt=0;
    }
    v.pop_back();
    cout<<sm<<"\n";
    for(int x:v){
	cout<<x<<" ";
    }
    return cout<<endl,0;
}