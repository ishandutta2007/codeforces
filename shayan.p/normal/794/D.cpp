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
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll maxn=3e5+10;
const ll Mid=1e6;

vector<ll>v[maxn];
ll mark[maxn];

map<ll,ll>mp;//number of vertices having number x
map<ll,ll>emp;//number of vertices between numbers x ans x+1

void go_for(vector<ll>&vec,ll plus){
	if(vec.empty())
		return;
	vector<ll>vec2;vec2.clear();
	REP(i,sz(vec)){
		ll num=0;
		ll x=vec[i];
		REP(j,sz(v[x])){
			ll y=v[x][j];
			if(mark[y]==0){//aft unseen
				mark[y]=mark[x]+plus;
				mp[mark[y]]++;
				vec2.PB(y);
			}
			else if(mark[y]==mark[x]+plus){//aft seen
			}
			else if(mark[y]==mark[x]){//now
				num++;
			}
			else if(mark[y]==mark[x]-plus){//bef
			}
			else{
				cout<<"NO";
				exit(0);
			}
		}
		if(num+1!=sz(vec)){
			cout<<"NO";
			exit(0);
		}
	}
	go_for(vec2,plus);
}
void neighbor(ll u,set<ll>&tmp){
	tmp.insert(u);
	REP(i,sz(v[u])){
		tmp.insert(v[u][i]);
	}
}
int main(){
	ll n,m;cin>>n>>m;
	REP(i,m){
		ll a,b;cin>>a>>b;
		v[a].PB(b);
		v[b].PB(a);
	}
	set<ll>s1,s2,s3,tmp;
	vector<ll>two,three;
	neighbor(1,s1);
	mark[1]=Mid;
	mp[Mid]++;
	REP(i,sz(v[1])){
		ll y=v[1][i];
		tmp.clear();
		neighbor(y,tmp);
		if(tmp==s1){
			mark[y]=Mid;
		}
		else if(s2.empty()){
			s2=tmp;
			mark[y]=Mid+1;
			two.PB(y);
		}
		else if(s2==tmp){
			mark[y]=Mid+1;
			two.PB(y);
		}
		else if(s3.empty()){
			s3=tmp;
			mark[y]=Mid-1;
			three.PB(y);
		}
		else if(s3==tmp){
			mark[y]=Mid-1;
			three.PB(y);
		}
		else{
			cout<<"NO";
			return 0;
		}
		mp[mark[y]]++;
	}
	go_for(two,1);
	go_for(three,-1);
	//finall check
	FOR(i,1,n){
		REP(j,sz(v[i])){
			ll y=v[i][j];//an edge between i and y
			if(abs(mark[i]-mark[y])>1){
				cout<<"NO";
				return 0;
			}
			if(mark[y]-mark[i]==1){
				emp[mark[i]]++;
			}
		}
	}
	for(map<ll,ll>::iterator it=mp.begin();it!=(--mp.end());it++){
		ll num=it->F;
		if((mp[num]*mp[num+1])!=emp[num]){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES\n";
	FOR(i,1,n){
		cout<<mark[i]<<" ";
	}
}