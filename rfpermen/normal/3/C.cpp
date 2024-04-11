#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 5e4+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int o,X,a,b;
char x[4][4];

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,1,3)rep(j,1,3){
    	cin>>x[i][j];
    	if(x[i][j]=='0')++o;
    	else if(x[i][j]=='X')++X;
	}
	rep(i,1,3){
		if(x[i][1]==x[i][2]&&x[i][2]==x[i][3]){
			if(x[i][1]=='0')++a;
			else if(x[i][1]=='X')++b;
		}
		if(x[1][i]==x[2][i]&&x[2][i]==x[3][i]){
			if(x[1][i]=='0')++a;
			else if(x[1][i]=='X')++b;
		}
	}
	if(x[1][1]==x[2][2]&&x[2][2]==x[3][3]){
		if(x[1][1]=='0')++a;
		else if(x[1][1]=='X')++b;
	}
	if(x[1][3]==x[2][2]&&x[2][2]==x[3][1]){
		if(x[1][3]=='0')++a;
		else if(x[1][3]=='X')++b;
	}
	
	if(o>X||X>o+1||(a&&b)||(a&&X==o+1)||(b&&X==o))cout<<"illegal";
	else if(b)cout<<"the first player won";
	else if(a)cout<<"the second player won";
	else if(o+X==9)cout<<"draw";
	else if(o==X)cout<<"first";
	else cout<<"second";
    return 0;
}