#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll n,x,a,b,le,ri,bal,res;
char c;
bool st;

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    n/=2;
    rep(i,1,n){
    	cin>>c;
    	if(c=='?')++a;
    	else x+=c-'0';
	}
    rep(i,1,n){
    	cin>>c;
    	if(c=='?')++b;
    	else x-=c-'0';
	}
	while(a+b){
		le = x-b*9, ri = x+a*9;
		if(le>0||ri<0)return cout<<"Monocarp",0;
		if(!st){
			if(-le>=ri){
				if(a)--a;
				else --b, x-=9; 
			}
			else {
				if(a)--a, x+=9;
				else --b;
			}
		}
		else {
			if(a){
				--a;
				bal = 1e9;
				rep(i,0,9){
					le = x+i-b*9, ri = x+i+a*9;
					if(le>0||ri<0)continue;
					if(bal>abs(ri+le))bal = abs(ri+le), res = i;
				}
				x+=res;
			}
			else {
				--b;
				bal = 1e9;
				rep(i,0,9){
					le = x-i-b*9, ri = x-i+a*9;
					if(le>0||ri<0)continue;
					if(bal>abs(ri+le))bal = abs(ri+le), res = i;
				}
				x-=res;
			}
		}
		st^=1;
	}
	if(x)cout<<"Monocarp";
	else cout<<"Bicarp";
	return 0;
}