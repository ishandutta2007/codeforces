// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

using namespace std;
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll mod=1e9+7;
const ll maxn=1010;

ll depth[2*maxn];
bool mark[2*maxn];
set<ll>s;
vector<ll>v;
int main(){
	ll n,k;scanf("%d%d",&n,&k);
	REP(i,k){
		ll x;scanf("%d",&x);
		x-=n;
		s.insert(x);
	}
	for(set<ll>::iterator it=s.begin();it!=s.end();it++)
		v.PB(*it);
	queue<ll>q;
	q.push(0);
	while(sz(q)){
		ll t=q.front();
		q.pop();
		REP(i,sz(v)){
			if(-1000<=t+v[i]&&t+v[i]<=1000&&!mark[t+v[i]+1000]){
				mark[t+v[i]+1000]=1;
				depth[t+v[i]+1000]=depth[t+1000]+1;
				q.push(t+v[i]);
				if(t+v[i]==0){
					cout<<depth[1000];
					return 0;
				}
			}
		}
	}
	cout<<-1;
}