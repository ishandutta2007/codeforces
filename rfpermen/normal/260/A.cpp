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

int a,b,n,tmp,nx;
string s;
pair<int,string> vis[MAX];
int cur;
queue<int> q;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>n;
    tmp = a;
    while(tmp)s+=tmp%10+'0', tmp/=10;
    reverse(s.begin(),s.end());
    a%=b;
    q.push(a);
	rep(i,0,b)vis[i].fi = -1;
	vis[a] = {n,s};
	while(!q.empty()){
		cur = q.front(); q.pop();
		if(!cur){cout<<vis[cur].se; while(vis[cur].fi--)cout<<'0'; return 0;}
		if(vis[cur].fi==0)continue;
		rep(i,0,9){
			nx = (cur*10+i)%b;
			if(nx)continue;
			if(vis[nx].fi!=-1)continue;
			s = vis[cur].se;
			s+= ('0'+i);
			vis[nx] = {vis[cur].fi-1,s};
			q.push(nx);
		}
	}
	cout<<-1;
	return 0;
}