// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define FORK(i,a,b,c) for(int i=int(a);i<=b;i+=c)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

inline void Add(vector<ll>&v,ll num){
    if(num==0)return;
    if(v.empty() || v.back()!=num)
	v.PB(num);
}

void Unique(vector<ll>&v){
    vector<ll>vec;
    for(ll x:v)
	Add(vec,x);
    v=vec;
}

inline void Double(vector<ll>&v,ll num){
    REP(i,sz(v)){
	v[i]*=2;
    }
    if(num!=0)
	v.PB(num);
}

void print(vector<ll>&v){
    for(ll x:v){
	cout<<x<<" ";
    }
    cout<<endl;
}
vector<ll> solve(vector<ll>v){
    vector<ll>v1,v2;
    v1.clear();
    v2.clear();
    if(v.empty())return v1;
    if(sz(v)==1 && v[0]==1){
	v1.PB(1);
	return v1;
    }
    if(sz(v)==1 && v[0]==-1){
	v1.PB(-1);
	return v1;
    }
    bool is=0;
    for(ll x:v){
	if(x%2){
	    is=1;
	    Add(v1,(x+1)/2);
	    Add(v2,(x-1)/2);
	}
	else{
	    Add(v1,x/2);
	    Add(v2,x/2);
	}
    }
    if(!is){
	v1=solve(v1);
	Double(v1,0);
	return v1;
    }
    v1=solve(v1);
    v2=solve(v2);
    if(sz(v1)<sz(v2)){
	Double(v1,-1);
	return v1;
    }
    else{
	Double(v2,1);
	return v2;
    }
}

int main(){
    vector<ll>v,ans;
    ll n;cin>>n;
    REP(i,n){
	ll x;cin>>x;
	v.PB(x);
    }
    sort(all(v));
    Unique(v);
    ans=solve(v);
    cout<<sz(ans)<<endl;
    for(ll x:ans){
	cout<<x<<" ";
    }
}