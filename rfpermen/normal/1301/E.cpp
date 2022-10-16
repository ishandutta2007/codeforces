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
const int MAX = 502;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int n,m,q,z[MAX][MAX],x[MAX][MAX][252],pf[MAX][MAX][5],hs[128],mn,le,ri,mid,ans;
char c;

inline bool cek(int x1,int x2,int y1,int y2,int o){
	return pf[x2][y2][o] - pf[x2][y1-1][o] - pf[x1-1][y2][o] + pf[x1-1][y1-1][o] == (x2-x1+1)*(y2-y1+1);
}

inline bool cek2(int x1,int x2,int y1,int y2,int o){
	if(x2<x1||y2<y1||x1<1||y1<1)return 0;
	return x[x2][y2][o] - x[x2][y1-1][o] - x[x1-1][y2][o] + x[x1-1][y1-1][o] != 0;
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    hs['R'] = 0, hs['G'] = 1, hs['Y'] = 2, hs['B'] = 3;
    int x1,x2,y1,y2,o;
    cin>>n>>m>>q;
    rep(i,1,n)rep(j,1,m){
    	cin>>c;
    	rep(k,0,3)pf[i][j][k] = pf[i-1][j][k] + pf[i][j-1][k] - pf[i-1][j-1][k];
    	z[i][j] = hs[c];
    	++pf[i][j][hs[c]];
	}
	rep(i,2,n)rep(j,2,m){
		if(	z[i-1][j-1]==0&&z[i-1][j]==1 &&
			z[i  ][j-1]==2&&z[i  ][j]==3){
				mn = min(min(i,j)-2,min(n-i,m-j));
				rep(k,0,mn){
					if(	!cek(i-1-k,i-1,j-1-k,j-1,0)||
						!cek(i-1-k,i-1,j,j+k,1)||
						!cek(i,i+k,j-1-k,j-1,2)||
						!cek(i,i+k,j,j+k,3)
						)break;
					x[i-1-k][j-1-k][k+1] = 1;
				}
			}
	}
	rep(i,1,n)rep(j,1,m)rep(k,1,250){
		x[i][j][k]+= x[i-1][j][k] + x[i][j-1][k] - x[i-1][j-1][k];
	}
	while(q--){
		cin>>x1>>y1>>x2>>y2;
		ans = 0, le = 1, ri = 250;
		while(le<=ri){
			mid = le+ri>>1;
			if(cek2(x1,x2-mid-mid+1,y1,y2-mid-mid+1,mid))ans = mid, le = mid+1;
			else ri = mid-1;
		}
		cout<<((ans*ans)<<2)<<endl;
	}
    return 0;
}