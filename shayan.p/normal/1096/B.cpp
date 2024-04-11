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

const int maxn=4e5+10,mod=1e9+7;
const ll inf=1e18;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    int pt1=1,pt2=n-2;
    while(s[pt1]==s[pt1-1])
	pt1++;
    while(s[pt2]==s[pt2+1])
	pt2--;
    ll ans=0;
    if(s[0]==s[n-1])
	ans=1ll*(pt1+1)*(n-pt2);
    else
	ans=(pt1+1)+(n-pt2)-1;
    cout<<ans%998244353<<endl;
}