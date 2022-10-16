#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define For(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vll vector<pll>
#define vvl vector<vector<ll>>
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<pii,int>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

struct trie{
	int nx[2],cnt;
}tr[MAX*30];
int q,id,ty,x,y,ans,nw;
bool st,z;

void ins(int x){
	nw = 0;
	rap(i,27,0){
		st = (x>>i)&1;
		if(!tr[nw].nx[st])tr[nw].nx[st] = ++id;
		nw = tr[nw].nx[st];
		++tr[nw].cnt;
	}
	return;
}
void del(int x){
	nw = 0;
	rap(i,27,0){
		st = (x>>i)&1;
		if(!tr[nw].nx[st])exit(1);
		nw = tr[nw].nx[st];
		--tr[nw].cnt;
	}
	return;
}
int que(int x,int y){
	nw = 0;
	int ret = 0;
	rap(i,27,0){
		z = (y>>i)&1;
		st = (x>>i)&1;
		if(z){
			ret+= tr[tr[nw].nx[st]].cnt;
			if(!tr[nw].nx[st^1])break;
			nw = tr[nw].nx[st^1];
		}
		else {
			if(!tr[nw].nx[st])break;
			nw = tr[nw].nx[st];
		}
	}
	return ret;
}

int main(){
//	cout<<fixed<<setprecision(5);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>q;
	while(q--){
		cin>>ty>>x;
		if(ty==1)ins(x);
		else if(ty==2)del(x);
		else {
			cin>>y;
			cout<<que(x,y)<<endl;
		}
	}
	return 0;
}