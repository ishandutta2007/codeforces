#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

ll n,m,k,x[MAX],dv,ans,tmp;
bool st[MAX];
priority_queue<pll> pq;
priority_queue<pll, vector<pll>, greater<pll> > q;

inline void solve(){
	
    rep(i,1,m-1){
    	if(x[i]>0)tmp+=x[i];
    	else {
    		if(k){
    			pq.push({x[i],i});
    			st[i] = 1;
    			tmp-=x[i];
    			while(pq.size()>k+dv){
    				if(!st[pq.top().se])pq.pop(), --dv;
    				else st[pq.top().se] = 0, tmp+=pq.top().fi*2, q.push(pq.top()), pq.pop();
				}
			}
			else tmp+=x[i];
		}
	}
	rep(i,m,n){
    	if(x[i]>0)tmp+=x[i];
    	else {
    		if(k){
    			pq.push({x[i],i});
    			st[i] = 1;
    			tmp-=x[i];
    			while(pq.size()>k+dv){
    				if(!st[pq.top().se])pq.pop(), --dv;
    				else st[pq.top().se] = 0, tmp+=pq.top().fi*2, q.push(pq.top()), pq.pop();
				}
			}
			else tmp+=x[i];
		}
		ans = max(ans,tmp);
		if(!st[i-m+1])tmp-=x[i-m+1];
		else {
			tmp+=x[i-m+1], st[i-m+1] = 0, ++dv;
			while(!q.empty()){
				if(q.top().se<=i-m)q.pop();
				else {
					st[q.top().se] = 1;
					pq.push(q.top());
					tmp-=q.top().fi*2;
					q.pop();
					break;
				}
			}
		}
	}
}

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("class_treasurer.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)cin>>x[i];
    cin>>k;
    solve();
	memset(st,0,sizeof st);
	while(!pq.empty())pq.pop();
	while(!q.empty())q.pop();
	tmp = dv = 0;
	rep(i,1,n)x[i]*=-1;
	solve();
	cout<<ans<<endl;
	return 0;
}