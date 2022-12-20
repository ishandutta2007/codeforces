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

const int maxn=1e4;
const ll Max=10004205361450475;

map<pair<ll,int>,ll>mp;
ll Num[5];

ll f(ll l,int num){
    if(mp.count({l,num})) return mp[{l,num}];
    if(num==0) return mp[{l,num}]=l;
    if(l>=maxn) return mp[{l,num}]=l+Num[num];
    ll ans=l-1;
    for(int i=0;i<=l;i++){
	ans=f(ans+1,num-1);
	if(ans>=Max){ans=Max;break;}
    }
    return mp[{l,num}]=ans;
}

pll Ask(vector<ll>&vec,ll l,ll r){
    if(vec.empty()) return {-1,-1};
    cout<<sz(vec)<<" ";
    for(ll x:vec)
	cout<<x<<" ";
    cout<<endl;
    int num;cin>>num;
    if(num<0) exit(0);
    if(num==0) return {l,vec[0]};
    if(num==sz(vec)) return {vec.back()+1,r};
    return {vec[num-1]+1,vec[num]};
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    Num[0]=0;
    for(int i=1;i<5;i++)
	Num[i]=1ll*(maxn+1)*(Num[i-1]+1)-1;
    ll l=1,r=Max;//[)
    for(int CNT=5;CNT>0;CNT--){
	vector<ll>vec;vec.clear();
	ll now=l-1;
	for(int i=0;i<=min(l,ll(maxn));i++)
	    vec.PB(now=f(now+1,CNT-1));
	while(vec.back()>=r) vec.pop_back();
	pll p=Ask(vec,l,r);
	l=p.F,r=p.S;
    }
    return 0;
}