 #include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
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
const int MAX = 1e3+5;
const ll MAX2 = 11;
const int MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,dp[MAX][MAX],a,b,y,x[MAX][MAX][2],aa,bb;
bool ad;
string s,t;
int f(int r,int c,bool z){
	if(r==n&&c==n)return dp[r][c] = x[r][c][z];
	if(dp[r][c]!=-1)return dp[r][c];
	if(r==n)return dp[r][c] = f(r,c+1,z)+x[r][c][z];
	if(c==n)return dp[r][c] = f(r+1,c,z)+x[r][c][z];
	return dp[r][c] = min(f(r+1,c,z),f(r,c+1,z))+x[r][c][z];
}
void bt(int r,int c,string &st,int z){
	if(r==n&&c==n)return;
	if(r==n||dp[r][c]==dp[r][c+1]+x[r][c][z])st.pb('R'), bt(r,c+1,st,z);
	else st.pb('D'), bt(r+1,c,st,z);
}

int main(){
//	cout<<fixed<<setprecision(5);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)rep(j,1,n){
    	cin>>y;
    	if(!y){
    		ad = true;
    		aa = i, bb = j;
    		continue;
		}
    	while(y%2==0)x[i][j][0]++, y/=2;
    	while(y%5==0)x[i][j][1]++, y/=5;
	}
	memset(dp,-1,sizeof dp);
	a = f(1,1,0);
	bt(1,1,s,0);
	memset(dp,-1,sizeof dp);
	b = f(1,1,1);
	bt(1,1,t,1);
	if(a>1&&b>1&&ad){
		cout<<"1\n";
		rep(i,2,aa)cout<<'D';
		rep(i,2,bb)cout<<'R';
		rep(i,aa+1,n)cout<<'D';
		rep(i,bb+1,n)cout<<'R';
		
	}
	else {
		cout<<min(a,b)<<endl;
		if(a<b)cout<<s;
		else cout<<t;
	}
	return 0;
}