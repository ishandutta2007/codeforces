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
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

pll lst[30];
ll dp=1;

int main(){
    ll n,k;cin>>n>>k;
    string s;cin>>s;

    REP(i,sz(s)){
	ll bf=dp;
	dp=(2*dp-lst[s[i]-'a'].S+mod)%mod;
	lst[s[i]-'a'].S=bf;
	lst[s[i]-'a'].F=i+1;
    }
    sort(lst,lst+k);

    REP(i,n){
	ll bf=dp;
	dp=(2*dp-lst[i%k].S+mod)%mod;
	lst[i%k].S=bf;
    }

    cout<<dp;
}