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

priority_queue<int> pq;
int a[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    string s;cin>>s;
    ll ans=0;
    pq.push(a[0]);
    for(int i=1;i<n;i++){
	if(s[i]!=s[i-1]){
	    for(int j=0;j<k;j++){
		if(pq.empty()) break;
		ans+=pq.top();
		pq.pop();
	    }
	    while(!pq.empty()) pq.pop();
	}
	pq.push(a[i]);
    }
    for(int j=0;j<k;j++){
	if(pq.empty()) break;
	ans+=pq.top();
	pq.pop();
    }
    return cout<<ans<<endl,0;
}