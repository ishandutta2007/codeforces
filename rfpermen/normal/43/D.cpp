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
const int MAX = 1e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,m;
bool st;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if(n==1 && m!=2){
    	cout<<"1\n1 "<<m<<" 1 1\n";
    	rep(i,1,m)cout<<"1 "<<i<<endl;
    	cout<<"1 1\n";
    	return 0;
	}
	if(m==1 && n!=2){
		cout<<"1\n"<<n<<" 1 1 1\n";
    	rep(i,1,n)cout<<i<<" 1"<<endl;
    	cout<<"1 1\n";
    	return 0;
	}
	if(m%2==0)swap(n,m), st = 1;
	if(n&1){
		cout<<"1\n"<<n<<' '<<m<<" 1 1\n";
		rep(i,1,n){
			if(i&1){
				rep(j,1,m)cout<<i<<' '<<j<<endl;
			}
			else {
				rap(j,m,1)cout<<i<<' '<<j<<endl;
			}
		}
		cout<<"1 1\n";
		return 0;
	}
	cout<<"0\n1 1\n";
	rep(i,1,n){
		if(i&1){
			rep(j,2,m){
				if(!st)cout<<i<<' '<<j<<endl;
				else cout<<j<<' '<<i<<endl;
			}
		}
		else {
			rap(j,m,2){
				if(!st)cout<<i<<' '<<j<<endl;
				else cout<<j<<' '<<i<<endl;
			}
		}
	}
	rap(i,n,1){
		if(!st)cout<<i<<' '<<1<<endl;
		else cout<<1<<' '<<i<<endl;
	}
    return 0;
}