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
#define rsort(x) sort(x), reverse(x)
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
//#define endl '\n'
const int MAX = 3e5+5;
const ll MOD = 998244353;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 100;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}

#ifdef LOCAL
const int LIM = 40;

const int xa = 823482;
const int xb = 923999;
const int ya = 2;
const int yb = 999999999;

int qcnt = 0;

int dist(int a, int mn, int mx)
{
    if(a < mn)
    {
        return mn - a;
    }
    if(a > mx)
    {
        return a - mx;
    }
    return 0;
}

int query(int x, int y)
{
    assert(++qcnt <= LIM);
    return dist(x, xa, xb) + dist(y, ya, yb);
}
#else
int query(int x, int y)
{
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}
#endif

int le,ri,mid,ori,a,res;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
//	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int x1,x2,y1,y2;
	ori = query(1,1);
	le = 2, ri = 999999999;
	while(le<=ri){
		mid = le+ri>>1;
		a = query(1,mid);
		if(a==ori-mid+1)res = mid, le = mid+1;
		else ri = mid-1;
	}
	y1 = res;
	x1 = ori+2-y1;
	x2 = 1000000000 - (query(1000000000,1)-y1+1);
	y2 = 1000000000 - (query(1,1000000000)-x1+1);
	cout<<"! "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	return 0;
}