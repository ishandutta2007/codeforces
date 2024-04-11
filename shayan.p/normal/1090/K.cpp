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

const int maxn=1e5+10,mod=1e9+9,P1=101,P2=37;
const ll inf=1e18;

map<pair<int,pii>,vector<int> >mp;
vector<int>ans[maxn];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
	string a,b;cin>>a>>b;
	int A=0,B=0,msk=0;
	for(int i=0;i<sz(b);i++)
	    msk|=(1<<(b[i]-'a'));
	while(sz(a) && bit(msk,a.back()-'a'))
	    a.pop_back();
	for(int i=0;i<sz(a);i++)
	    A=(1ll*A*P1+a[i]-'a'+1)%mod;
	for(int i=0;i<sz(a);i++)
	    B=(1ll*B*P2+a[i]-'a'+1)%mod;
	mp[{msk,{A,B}}].PB(i);
    }
    cout<<sz(mp)<<"\n";
    for(auto it:mp){
	cout<<sz(it.S)<<" ";
	for(int i=0;i<sz(it.S);i++)
	    cout<<it.S[i]+1<<" ";
	cout<<"\n";
    }
    return 0;
}