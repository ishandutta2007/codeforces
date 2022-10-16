#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e4+5;
const ll MAX2 = 11;
const ll MOD = 1000000000;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
int tc,n,nw;

void f(int of,int st){
	if(st==4){
		cout<<2+of<<' '<<4+of<<' '<<1+of<<' '<<3+of<<' ';
	}
	else if(st==5){
		cout<<1+of<<' '<<3+of<<' '<<5+of<<' '<<2+of<<' '<<4+of<<' ';
	}
	else if(st==6){
		cout<<1+of<<' '<<4+of<<' '<<2+of<<' '<<6+of<<' '<<3+of<<' '<<5+of<<' ';
	}
}

int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>n;
    	if(n<4)cout<<"-1\n";
    	else if(n==7)cout<<"5 1 3 6 2 4 7\n";
    	else {
    		nw = 0;
    		while(n){
    			if(n==11){
    				n-=11;
    				f(nw,5);
    				f(nw+5,6);
				}
				else if(n==5)n-=5, f(nw,5);
				else if(n==6)n-=6, f(nw,6);
				else {
					n-=4;
					f(nw,4);
					nw+=4;
				}
			}
			cout<<endl;
		}
	}
    
	return 0;
}