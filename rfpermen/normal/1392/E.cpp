#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<pll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
//#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

ll n,x[30][30],a,b,z,q,bit,ls,nw;

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,2,50){
    	nw = 1ll<<i-2;
    	a = 1, b = i;
    	while(a<=25&&b){
    		if(b<=25)x[a][b] = nw;
    		++a, --b;
    		if(a&1)nw>>=1;
    		else nw<<=1;
		}
	}
	rep(i,1,n){
		rep(j,1,n){
			cout<<x[i][j];
			if(j!=n)cout<<' ';
			else cout<<endl;
		}
	}
	cin>>q;
	while(q--){
		cin>>z;
		a = 1, b = 1, bit = -1;
		while(1){
			z-= x[a][b];
			cout<<a<<' '<<b<<endl;
			if(a==n&&b==n)break;
			else if(a==n)++b;
			else if(b==n)++a;
			else {
				if(a%2){
					if(z&(1ll<<bit+1))++b, ++bit;
					else {
						if(z&(1ll<<bit+2))++a;
						else {
							++a;
			z-= x[a][b];
							cout<<a<<' '<<b<<endl;
							++a;
						}
						bit+=2;
					}
				}
				else {
					//di posisi ini gak mungkin pergi ke bawah dulu
					if(z&(1ll<<bit+1))++b;
					else {
						++b;
			z-= x[a][b];
						cout<<a<<' '<<b<<endl;
						++a;
					}
					++bit;
				}
			}
		}
	}
    return 0;
}