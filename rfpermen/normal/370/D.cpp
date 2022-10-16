#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e3+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,m,le,ri,mid,ans,z[MAX][MAX],R[MAX][MAX],C[MAX][MAX],a,b,cnt,x[MAX][MAX];
char c;
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)rep(j,1,m){
    	cin>>c;
    	R[i][j] = R[i-1][j];
    	C[i][j] = C[i][j-1];
    	z[i][j] = z[i-1][j] + z[i][j-1] - z[i-1][j-1];
    	if(c=='w')++z[i][j], ++cnt, ++R[i][j], ++C[i][j], x[i][j] = 1;
	}
	if(cnt==1){
		rep(i,1,n){
			rep(j,1,m)cout<<(x[i][j] ? 'w' : '.');
			cout<<endl;
		}
		return 0;
	}
//	rep(i,1,n){
//		rep(j,1,m)cout<<z[i][j]; cout<<endl;
//	}
	ans = MOD;
	rep(i,1,n)rep(j,1,m){
		le = 1, ri = min(i,j)-1;
		mid = ri;
//		if(i==4&&j==6)db(z[i][j] - z[i-mid-1][j] - z[i][j-mid-1] + z[i-mid+1][j-mid+1]);
		while(le<=ri){
			mid = le+ri>>1;
			if(z[i][j] - z[i-mid-1][j] - z[i][j-mid-1] + z[i-mid-1][j-mid-1]==cnt){
				if(C[i][j] - C[i][j-mid-1] + C[i-mid][j] - C[i-mid][j-mid-1]
					+ R[i-1][j] - R[i-mid][j] + R[i-1][j-mid] - R[i-mid][j-mid] == cnt){
						if(ans>mid)ans = mid, a = i, b = j;
					}
				ri = mid-1;
			}
			else le = mid+1;
		}
	}
	if(ans==MOD)return cout<<"-1\n",0;
//	db(ans);
	rep(i,a-ans,a){
		if(!x[i][b])x[i][b] = 2;
		if(!x[i][b-ans])x[i][b-ans] = 2;
	}
	rep(i,b-ans,b){
		if(!x[a][i])x[a][i] = 2;
		if(!x[a-ans][i])x[a-ans][i] = 2;
	}
	rep(i,1,n){
		rep(j,1,m){
			if(!x[i][j])cout<<'.';
			else if(x[i][j]&1)cout<<'w';
			else cout<<'+';
		}
		cout<<endl;
	}
    return 0;
}