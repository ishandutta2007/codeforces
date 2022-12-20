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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int b,n;cin>>b>>n;
    int ans=0;
    for(int i=0;i<n;i++){
	int x;cin>>x;
	if(i==n-1)
	    ans+=x&1;
	else
	    ans+=b&x&1;
    }
    return cout<<(ans&1?"odd":"even")<<endl,0;
}