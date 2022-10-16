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
const int MAX = 2e6+5;
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

string s;
int d,c,k,nw,tmp,cnt;
bool st;

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
//	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>s;
	s+= 'a';
	for(char i:s){
		if(i>='a' && i<='z'){
			if(!st)d+= nw;
			else {
				if(cnt==2)d+= tmp, c+= nw;
				else if(cnt==3)d+= tmp*1000 + nw;
				else return 1;
			}
			nw = tmp = cnt = st = 0;
		}
		else if(i=='.'){
			tmp = tmp*1000 + nw;
			st = 1;
			nw = cnt = 0;
		}
		else {
			if(st)++cnt;
			nw = nw*10 + i-'0';
		}
	}
	d+= c/100, c%= 100;
	s = "";
	cnt = 0;
	if(!d)s = "0";
	while(d){
		s+= d%10 + '0';
		++cnt;
		d/= 10;
		if(d && cnt==3)cnt = 0, s+= '.';
	}
	reverse(all(s));
	cout<<s;
	if(c){
		cout<<".";
		if(c>=10)cout<<c;
		else cout<<"0"<<c;
	}
	cout<<endl;
	return 0;
}