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
//#define ff fi.fi
//#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e3+5;
const ll MAX2 = 1e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 285;

int n,m,dp[MAX][MAX][2],pr[MAX][MAX],pc[MAX][MAX],mem[MAX][MAX][2],vr[MAX],vc[MAX];
char x[MAX][MAX];

inline void ins(int &r,int &c,bool &mv,int &val){
	if(!mv){
		mem[r][c][0] = mem[r+1][c][0]+val;
		if(mem[r][c][0]>MOD)mem[r][c][0]-=MOD;
		else if(mem[r][c][0]<0)mem[r][c][0]+=MOD;
	}
	else {
		mem[r][c][1] = mem[r][c+1][1]+val;
		if(mem[r][c][1]>MOD)mem[r][c][1]-=MOD;
		else if(mem[r][c][1]<0)mem[r][c][1]+=MOD;
	}
	return;
}

int f(int r,int c,bool mv){
	if(r>n||c>m)return 0;
	if(dp[r][c][mv]!=-1)return dp[r][c][mv];
	int a,b;
	if(mv)a = pr[r][c], b = pc[r][c] - (x[r][c]=='R');
	else a = pr[r][c] - (x[r][c]=='R'), b = pc[r][c];
	if(a+r>n||b+c>m)return dp[r][c][mv] = 0, ins(r,c,mv,dp[r][c][mv]), dp[r][c][mv];
	int ret,nx;
	if(r==n)ret = (b==0);
	else if(c==m)ret = (a==0);
	else if(mv){
		nx = c+1;
		while(vr[nx]>r)--vr[nx], f(vr[nx],nx,0);
		ret = mem[r][nx][0] - mem[n-a+1][nx][0];
	}
	else {
		nx = r+1;
		while(vc[nx]>c)--vc[nx], f(nx,vc[nx],1);
		ret = mem[nx][c][1] - mem[nx][m-b+1][1];
	}
	return dp[r][c][mv] = ret, ins(r,c,mv,dp[r][c][mv]), dp[r][c][mv];
}

int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if(n==1&&m==1)return cout<<"1\n",0;
    rep(i,1,n)rep(j,1,m)cin>>x[i][j];
    rap(i,n,1)rap(j,m,1){
    	pr[i][j] = pr[i+1][j], pc[i][j] = pc[i][j+1];
    	if(x[i][j]=='R')++pr[i][j], ++pc[i][j];
	}
	rep(i,1,n)vc[i] = m+1;
	rep(i,1,m)vr[i] = n+1;
	memset(dp,-1,sizeof dp);
	cout<<(MOD+MOD+f(2,1,1)+f(1,2,0))%MOD<<endl;
    return 0;
}