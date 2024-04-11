#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
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
//#define endl "\n"
const int MAX = 1e6+5;
const ll MAX2 = 11;
const int MOD = 1000000000 + 7;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,a[65],le,ri,mid,cnt,mx,z,k;
ll x;
bool vis[MAX],st;
vector<int> v;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    srand(time(0));
    cin>>n;
	le = 0, ri = 1e9;
	while(le<=ri){
		mid = le+ri>>1;
		cout<<"> "<<mid<<endl;
		cnt++;
		cin>>st;
		if(st)le = mid+1;
		else ri = mid-1, mx = mid;
	}
	k = min(60-cnt,n);
	rep(i,1,k){
		while(1){
			x = (rand()*rand())%(n+1);
			if(x<1)continue;
			if(!vis[x])break;
		}
		vis[x] = 1;
		cout<<"? "<<x<<endl;
		cin>>x;
		v.pb(x);
	}
	z = mx-v[0];
	for(auto i:v)z = __gcd(z,mx-i);
	cout<<"! "<<mx-z*(n-1)<<' '<<z<<endl;
	return 0;
}