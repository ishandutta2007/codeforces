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
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 15e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
 
int n,k,s[MAX],q[MAX],p[MAX],nx[MAX];
bool st;
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n)cin>>q[i], p[i] = i;
    st = 1;
    rep(i,1,n){
    	cin>>s[i];
    	if(s[i]!=i)st = 0;
	}
	if(st)return cout<<"NO\n",0;
	//ini cek kalo maju
	rep(j,1,k){
		rep(i,1,n)nx[i] = p[q[i]];
		st = 1;
		rep(i,1,n){
			p[i] = nx[i];
			if(s[i]!=p[i])st = 0;
		}
		if(st){
			if(j==k)return cout<<"YES\n",0;
			if(j%2==k%2){
				if(j==1){
					rep(i,1,n)p[i] = i;
					rep(i,1,n)nx[q[i]] = p[i];
					st = 1;
					rep(i,1,n){
						p[i] = nx[i];
						if(s[i]!=p[i])st = 0;
					}
					if(st)return cout<<"NO\n",0;
				}
				return cout<<"YES\n",0;
			}
			break;
		}
	}
	//cek kalo mundur
	rep(i,1,n)p[i] = i;
	rep(j,1,k){
		rep(i,1,n)nx[q[i]] = p[i];
		st = 1;
		rep(i,1,n){
			p[i] = nx[i];
			if(s[i]!=p[i])st = 0;
		}
		if(st){
			if(j%2==k%2)return cout<<"YES\n",0;
			break;
		}
	}
	cout<<"NO\n";
    return 0;
}