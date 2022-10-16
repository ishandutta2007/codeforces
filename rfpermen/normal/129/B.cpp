#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e2+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,m,deg[MAX],ans,x,y,upd[MAX];
vector<int> v[MAX];
bool st;

int main(){
	cout<<fixed<<setprecision(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    while(m--){
    	cin>>x>>y;
    	deg[x]++;
    	deg[y]++;
    	v[x].pb(y);
    	v[y].pb(x);
	}
	st = 1;
	while(st){
		st = 0;
		ans++;
		rep(i,1,n)upd[i] = deg[i];
		rep(i,1,n){
			if(deg[i]==1){
				st = 1;
				upd[i]--;
				for(auto j:v[i])upd[j]--;
			}
		}
		rep(i,1,n)deg[i] = upd[i];
	}
	cout<<ans-1<<endl;
    return 0;
}