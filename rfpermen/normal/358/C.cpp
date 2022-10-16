#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define mp make_pair
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
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,x[MAX],cnt;
priority_queue<pii, vector<pii>, greater<pii> > pq;
bool ins[MAX];
string p[3] = {"popStack","popQueue","popFront"}, ps[4] = {"pushStack","pushQueue","pushFront","pushBack"};
 
int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    rep(i,1,n){
    	if(x[i]){
    		pq.push({x[i],i});
    		if(pq.size()==4)pq.pop();
		}
		else while(!pq.empty())ins[pq.top().se] = 1, pq.pop();
	}
	rep(i,1,n){
		if(ins[i])cout<<ps[cnt]<<endl, cnt++;
		else if(x[i])cout<<ps[3]<<endl;
		else {
			cout<<cnt;
			rep(j,0,cnt-1)cout<<' '<<p[j];
			cout<<endl;
			cnt = 0;
		}
	}
	return 0;
}