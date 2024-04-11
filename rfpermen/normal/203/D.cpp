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
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

double a,b,m,vx,vy,vz,tim,tmp,ans;

int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>m;
    cin>>vx>>vy>>vz;
    tim = -m/vy;
    ans = a/2.0;
    if(vx)while(1){
    	if(vx<0){
    		if(-ans/vx+tmp>=tim){ans+=vx*(tim-tmp); break;}
			else tmp+=-ans/vx, ans = 0.0, vx = -vx;
		}
		else {
			if((a-ans)/vx+tmp>=tim){ans+=vx*(tim-tmp); break;}
			else tmp+=(a-ans)/vx, ans = a, vx = -vx;
		}
	}
	cout<<ans<<' ';
	ans = tmp = 0.0;
	if(vz)while(1){
    	if(vz<0){
    		if(-ans/vz+tmp>=tim){ans+=vz*(tim-tmp); break;}
			else tmp+=-ans/vz, ans = 0.0, vz = -vz;
		}
		else {
			if((b-ans)/vz+tmp>=tim){ans+=vz*(tim-tmp); break;}
			else tmp+=(b-ans)/vz, ans = b, vz = -vz;
		}
	}
	cout<<ans<<endl;
    return 0;
}