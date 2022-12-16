// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

priority_queue<ll,vector<ll>,greater<ll> >pq;
pair<pll,ll>p[maxn];
ll ans[maxn];
ll n,k;
ll NUM;

void add(ll num){
	if(k==0)return;
	if(sz(pq)<k){
		pq.push(num);
		NUM+=num;
	}
	else{
		if(pq.top()<num){
			NUM-=pq.top();
			NUM+=num;
			pq.pop();
			pq.push(num);
		}
	}
}

int main(){
	cin>>n>>k;
	REP(i,n)
		cin>>p[i].F.F;
	REP(i,n)
		cin>>p[i].F.S;
	REP(i,n)
		p[i].S=i;
	sort(p,p+n);
	REP(i,n){
		ans[p[i].S]=NUM+p[i].F.S;
		add(p[i].F.S);
	}
	REP(i,n)
		cout<<ans[i]<<" ";
}