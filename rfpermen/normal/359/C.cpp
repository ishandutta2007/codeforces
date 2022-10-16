#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<int,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,m,mx,mn,z,cnt,x[MAX],ret,ttl;
priority_queue<ll ,vector<ll>, greater<ll> > pq;

ll pw(ll x,ll y){
	ret = 1;
	while(y){
		if(y&1)ret = (ret*x)%MOD;
		x = (x*x)%MOD;
		y>>=1;
	}
	return ret;
}

int main(){
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if(m==1)return cout<<1,0;
    rep(i,1,n)cin>>x[i], ttl+=x[i];
    rep(i,1,n){
    	z = ttl-x[i];
    	pq.push(z);
	}
	mn = ttl;
	while(!pq.empty()){
		if(mx!=pq.top()){
			if(cnt)mn = min(mn,mx);
			mx = pq.top(), cnt = 1;
		}
		else cnt++;
		pq.pop();
		if(cnt==m)pq.push(mx+1), cnt = 0;
	}
	mn = min(mn,mx);
	cout<<pw(m,mn)<<endl;
    return 0;
}