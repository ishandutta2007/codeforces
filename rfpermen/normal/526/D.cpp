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
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

ll n,x[MAX],hs[MAX],k,sz,rem,z,nx,key,cek;
char c;
bool st;
inline void exe(int i){
	st = 0;
	while(i/(nx+1)==k&&!st){
		nx++;
		key = x[nx];
		st = 1;
		for(int j = nx*2; j<=i; j+=nx){
			if((x[j]-((x[j-nx]*hs[nx])%MOD)+MOD)%MOD!=key){
				st = 0;
				break;
			}
		}
		cek = i%nx;
		if(cek==0)cek = nx;
		if(x[cek]!=(x[i]-((x[i-cek]*hs[cek])%MOD)+MOD)%MOD)st = 0;
	}
	cout<<st;
	return;
}

int main(){
//	cout<<fixed<<setprecision(5);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	z = 91;
	cin>>n>>k;
	hs[0] = 1;
	rep(i,1,n){
		cin>>c;
		x[i] = (x[i-1]*z+c-'_')%MOD;
		hs[i] = (hs[i-1]*z)%MOD;
		if(i<k){
			cout<<0;
			continue;
		}
		if(st){
			if((i+nx-1)/nx!=k+1)exe(i);
			else {
				cek = i%nx;
				if(cek==0)cek = nx;
				if(x[cek]==(x[i]-((x[i-cek]*hs[cek])%MOD)+MOD)%MOD)cout<<st;
				else exe(i);
			}
		}
		else exe(i);
	}
	cout<<endl;
	return 0;
}