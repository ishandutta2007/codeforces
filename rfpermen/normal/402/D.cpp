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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
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
const int MAX = 5e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int n,m,x[MAX],y,z,hit,res,mx;
set<int> bad;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	rep(i,1,n)cin>>x[i];
	while(m--)cin>>z, bad.insert(z);
	rep(coba,1,n){
		mx = 0;
		hit = 0;
		z = 0;
		rep(i,1,n){
			res = __gcd(z,x[i]);
			if(res==1)break;
			if(z!=res){
				z = res, hit = 0;
				for(int j = 2; j*j<=z; j++){
					if(z%j)continue;
					if(bad.count(j))while(z%j==0)z/=j, --hit;
					else while(z%j==0)z/=j, ++hit;
				}
				if(z!=1){
					if(bad.count(z))--hit;
					else ++hit;
				}
				z = res;
			}
			if(hit<0)mx = i, y = z;
		}
		if(!mx)break;
		rep(i,1,mx)x[i]/=y;
	}
	hit = 0;
	rep(i,1,n){
		z = x[i];
		for(int j = 2; j*j<=z; j++){
			if(z%j)continue;
			if(bad.count(j))while(z%j==0)z/=j, --hit;
			else while(z%j==0)z/=j, ++hit;
		}
		if(z!=1){
			if(bad.count(z))--hit;
			else ++hit;
		}
	}
	cout<<hit<<endl;
    return 0;
}