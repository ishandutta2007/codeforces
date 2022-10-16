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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);


int n,x,y,k;
bool pr[2005];
map<string,int> m;
string a,b,res[2005];
vector<int> v[2005];
vector<pair<string,string> > ans;

void dfs(int i){
	y = i;
	for(auto j:v[i])dfs(j);
	return;
}

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    while(n--){
    	cin>>a>>b;
    	if(!m.count(a))m[a]=++k,res[k] = a;
    	if(!m.count(b))m[b]=++k,res[k] = b;
    	x = m[a], y = m[b];
    	pr[y] = 1;
		v[x].pb(y);
	}
	rep(i,1,k){
		if(!pr[i]){
			dfs(i);
			ans.pb({res[i],res[y]});
		}
	}
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i.fi<<" "<<i.se<<endl;
    return 0;
}