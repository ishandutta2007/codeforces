#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

ll tc,x,y,w,a,s,d,wse,ad;
string mv;
bool ss,aa,dd,ww;
 
int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("outrput.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>mv;
    	x = y = w = a = s = d = 0;
    	ww = ss = aa = dd = 0;
    	for(auto i:mv){
    		if(i=='W'){
    			++y;
    			if(y>w){
    				w = y;
    				ww = 1, ss = 0;
				}
				else if(y==w)ww = 1;
			}
			else if(i=='S'){
				--y;
    			if(y<s){
    				s = y;
    				ss = 1, ww = 0;
				}
				else if(y==s)ss = 1;
			}
			else if(i=='D'){
				++x;
    			if(x>d){
    				d = x;
    				dd = 1, aa = 0;
				}
				else if(x==d)dd = 1;
			}
			else if(i=='A'){
				--x;
    			if(x<a){
    				a = x;
    				aa = 1, dd = 0;
				}
				else if(x==a)aa = 1;
			}
			else return 1;
		}
		wse = w-s+1;
		ad = d-a+1;
//		cout<<ww<<' '<<ss<<endl;
//		cout<<wse<<endl;
		if(wse<ad){
			if(ww&&ss){
				if(!(aa&&dd)&&ad>2)ad--;
			}
			else if(wse>2)wse--;
			else if(!(aa&&dd)&&ad>2)ad--;
		}
		else {
			if(aa&&dd){
				if(!(ww&&ss)&&wse>2)wse--;
			}
			else if(ad>2)ad--;
			else if(!(ww&&ss)&&wse>2)wse--;
		}
		cout<<wse*ad<<endl;
	}
	return 0;
}