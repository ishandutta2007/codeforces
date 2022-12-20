// Phoenix

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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

priority_queue<int,vector<int>,greater<int> >pq;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    ll ans=0;
    while(n--){
	int x;cin>>x;
	pq.push(x);
	pq.push(x);
	ans+=x-pq.top();
	pq.pop();
    }
    return cout<<ans<<endl,0;
}