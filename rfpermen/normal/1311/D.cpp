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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
 
int tc,n,a,b,c,ans,tmp,x,y,z,ak,o;
piii opt;

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>a>>b>>c;
    	ans = MAX;
    	rep(i,1,15000){
    		tmp = MAX;
    		ak = sqrt(i);
    		x = 1;
    		rep(j,1,ak)if(i%j==0){
    			o = abs(a-j);
    			if(tmp>o)tmp = o, x = j;
    			o = abs(a-i/j);
    			if(tmp>o)tmp = o, x = i/j;
			}
			y = i;
			if(abs(c/i*i-c)<abs(c/i*i+i-c))z = c/i*i;
			else z = c/i*i+i;
			
			tmp+= abs(b-y)+abs(c-z);
			if(ans>tmp)ans = tmp, opt = {x,{y,z}};
		}
		cout<<ans<<endl;
		cout<<opt.fi<<' '<<opt.sf<<' '<<opt.ss<<endl;
	}
    return 0;
}