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

const int maxn=3e5+10,mod=1e9+7;
const ll inf=1e18;

pll p[maxn];
priority_queue<ll>pq;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;--n;
    cin>>p[0].F>>p[0].S;
    ll t=p[0].F;
    int r=0,ans=0;
    for(int i=0;i<n;i++){
	cin>>p[i].F>>p[i].S;
    }
    sort(p,p+n,greater<pll>());
    while(r<n && p[r].F>t) pq.push(p[r].F-p[r].S-1),r++;
    ans=sz(pq);
    while(sz(pq) && pq.top()+t>=0){
	t+=pq.top();
	pq.pop();
	while(r<n && p[r].F>t) pq.push(p[r].F-p[r].S-1),r++;
	ans=min(ans,sz(pq));
    }
    return cout<<ans+1<<endl,0;
}