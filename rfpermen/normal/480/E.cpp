#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define For(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
#define rip(i,n,N,V) for(int i=(n);i<=(N);i+=V)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
//#define le left
//#define ri right
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define ou3(x,y,z) cout << ">> " << (x) << " " << (y) << " " << (z) << endl
#define mems(x,y) memset(&x,y,sizeof x)
#define memsv(x,y) memset(&x[0], y, sizeof(x[0]) * x.size())
#define popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
#define ari(x) array<int,x>
#define arll(x) array<ll,x>
#define ard(x) array<double,x>
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e3+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}
 
#define lcx (idx<<1)
#define rcx ((idx<<1)|1)
#define lcy (idy<<1)
#define rcy ((idy<<1)|1)
int n,m,q,a,b,x[MAX][MAX],tree[1<<12][1<<12],lz[1<<12][1<<12],ans,A[MAX],B[MAX],mn=1;
char c[MAX][MAX];
 
void build(int idx,int lex,int rix,int idy,int ley,int riy){
//	cout<<"<> "<<idx<<" "<<lex<<' '<<rix<<" "<<idy<<" "<<ley<<" "<<riy<<endl;
	lz[idx][idy] = MOD;
	if(lex==rix && ley==riy){
		tree[idx][idy] = x[lex][ley];
		return;
	}
	if(lex==rix){
		int miy = ley+riy>>1;
		build(idx,lex,rix,lcy,ley,miy), build(idx,lex,rix,rcy,miy+1,riy);
		tree[idx][idy] = max(tree[idx][lcy],tree[idx][rcy]);
	}
	else if(ley==riy){
		int mix = lex+rix>>1;
		build(lcx,lex,mix,idy,ley,riy), build(rcx,mix+1,rix,idy,ley,riy);
		tree[idx][idy] = max(tree[lcx][idy],tree[rcx][idy]);
	}
	else {
		int mix = lex+rix>>1;
		int miy = ley+riy>>1;
		build(lcx,lex,mix,lcy,ley,miy), build(rcx,mix+1,rix,lcy,ley,miy);
		build(lcx,lex,mix,rcy,miy+1,riy), build(rcx,mix+1,rix,rcy,miy+1,riy);
		tree[idx][idy] = max(max(tree[lcx][lcy],tree[lcx][rcy]),max(tree[rcx][lcy],tree[rcx][rcy]));
	}
	return;
}
 
void f(int idx,int lex,int rix,int idy,int ley,int riy){
	tree[idx][idy] = min(tree[idx][idy],lz[idx][idy]);
	if(lex!=rix){
		if(ley!=riy){
			lz[lcx][lcy] = min(lz[lcx][lcy],lz[idx][idy]);
			lz[lcx][rcy] = min(lz[lcx][rcy],lz[idx][idy]);
			lz[rcx][lcy] = min(lz[rcx][lcy],lz[idx][idy]);
			lz[rcx][rcy] = min(lz[rcx][rcy],lz[idx][idy]);
		}
		else {
			lz[lcx][idy] = min(lz[lcx][idy],lz[idx][idy]);
			lz[rcx][idy] = min(lz[rcx][idy],lz[idx][idy]);
		}
	}
	else {
		if(ley!=riy){
			lz[idx][lcy] = min(lz[idx][lcy],lz[idx][idy]);
			lz[idx][rcy] = min(lz[idx][rcy],lz[idx][idy]);
		}	
	}
	lz[idx][idy] = MOD;
	return;
}
 
int ax,bx,ay,by;
void upd(int idx,int lex,int rix,int idy,int ley,int riy){
	if(lz[idx][idy]!=MOD)f(idx,lex,rix,idy,ley,riy);
	if(lex>bx || rix<ax || ley>by || riy<ay)return;
	if(lex>=ax && rix<=bx && ley>=ay && riy<=by){
		int val = max(a-rix,b-riy);
		if(tree[idx][idy]<=val)return;
		int val2 = min(ans,max(a-lex,b-ley));
		if(val2<mn){
			lz[idx][idy] = 0;
			f(idx,lex,rix,idy,ley,riy);
			return;
		}
		if(val2==val){
			lz[idx][idy] = val;
			f(idx,lex,rix,idy,ley,riy);
			return;
		}
	}
	if(lex==rix){
		int miy = ley+riy>>1;
		upd(idx,lex,rix,lcy,ley,miy), upd(idx,lex,rix,rcy,miy+1,riy);
		tree[idx][idy] = max(tree[idx][lcy],tree[idx][rcy]);
	}
	else if(ley==riy){
		int mix = lex+rix>>1;
		upd(lcx,lex,mix,idy,ley,riy), upd(rcx,mix+1,rix,idy,ley,riy);
		tree[idx][idy] = max(tree[lcx][idy],tree[rcx][idy]);
	}
	else {
		int mix = lex+rix>>1;
		int miy = ley+riy>>1;
		upd(lcx,lex,mix,lcy,ley,miy), upd(rcx,mix+1,rix,lcy,ley,miy);
		upd(lcx,lex,mix,rcy,miy+1,riy), upd(rcx,mix+1,rix,rcy,miy+1,riy);
		tree[idx][idy] = max(max(tree[lcx][lcy],tree[lcx][rcy]),max(tree[rcx][lcy],tree[rcx][rcy]));
	}
	return;
}

int jaw[MAX];
 
int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    rep(i,1,n)rep(j,1,m)cin>>c[i][j];
    rep(i,1,q){
    	cin>>A[i]>>B[i];
    	c[A[i]][B[i]] = 'X';
	}
	int K = 200, bt, tmp;
	for(int i = (q-1)/K*K+1; i>=1; i-= K){
		bt = min(i+K-1,q);
		rap(j,bt,i+1)c[A[j]][B[j]] = '.';
		rap(i,n,1)rap(j,m,1)if(c[i][j]=='.'){
	    	x[i][j] = min(x[i+1][j+1],min(x[i+1][j],x[i][j+1]))+1;
		}
		build(1,1,n,1,1,m);
		tmp = ans = tree[1][1];
		jaw[i] = ans;
		rep(j,i+1,bt){
			a = A[j], b = B[j];
			ax = ay = 1;
			bx = a, by = b;
			upd(1,1,n,1,1,m);
			jaw[j] = ans = tree[1][1];
		}
		c[A[i]][B[i]] = '.';
		mn = tmp;
	}
	rep(i,1,q)cout<<jaw[i]<<endl;
	return 0;
}