#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
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
#define pii pair<int,int> 
#define pll pair<int,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,r,a,b,sx,sy,ex,ey,st,en,k,vis[MAX],cur,nx;
map<pii,int> m;
queue<int> q;
vector<int> v[MAX];

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>sx>>sy>>ex>>ey;
    cin>>n;
    while(n--){
    	cin>>r>>a>>b;
    	rep(i,a,b)if(!m.count({r,i}))m[{r,i}] = ++k;
	}
	if(!m.count({sx,sy}) || !m.count({ex,ey}))return cout<<-1,0;
	st = m[{sx,sy}], en = m[{ex,ey}];
	for(auto i:m)rep(j,0,7)if(m.count({i.ff+nr[j],i.fs+nc[j]}))v[i.se].pb(m[{i.ff+nr[j],i.fs+nc[j]}]);
	q.push(st);
	memset(vis,-1,sizeof vis);
	vis[st] = 0;
	while(!q.empty()){
		cur = q.front(); q.pop();
		if(cur==en)return cout<<vis[cur],0;
		for(auto i:v[cur]){
			if(vis[i]!=-1)continue;
//			cout<<i<<" "<<cur<<endl;
			vis[i] = vis[cur]+1;
			q.push(i);
		}
	}
	cout<<-1;
	return 0;
}