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
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,-1,0,1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int tc,n,m,x,y,z,dp[5005][3],tmp,sz,pos;
map<int,int> vis;
ll a[MAX],res,ans;

int f(int nw,int st){
	if(nw<=0)return 0;
	if(dp[nw][st]!=-1)return dp[nw][st];
	set<int> s;
	if(st==0)s.insert(f(nw-x,0)), s.insert(f(nw-y,1)), s.insert(f(nw-z,2));
	else if(st==1)s.insert(f(nw-x,0)), s.insert(f(nw-z,2));
	else s.insert(f(nw-x,0)), s.insert(f(nw-y,1));
	rep(i,0,2)if(!s.count(i))return dp[nw][st] = i;
	return dp[nw][st] = 3;
}

int main(){
//	cout<<fixed<<setprecision(2);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>n>>x>>y>>z;
    	memset(dp,-1,sizeof dp);
    	vis.clear();
    	rep(i,1,5000){
    		if(i>4){
    			tmp = 0;
    			rep(j,i-4,i)tmp = tmp*4 + f(j,0);
    			rep(j,i-4,i)tmp = tmp*4 + f(j,1);
    			rep(j,i-4,i)tmp = tmp*4 + f(j,2);
    			if(vis.count(tmp)){
    				sz = i - vis[tmp];
    				pos = i;
    				break;
				}
				vis[tmp] = i;
			}
		}
//		db(sz);
//		rep(i,pos,70)cout<<f(i,0)<<' '; cout<<endl;
//		cout<<pos<<' '<<sz<<endl;
		ans = res = 0;
		rep(i,1,n){
			cin>>a[i];
			if(a[i]>pos)a[i] = (a[i]-pos)%sz, a[i]+= pos;
			res^= f(a[i],0);
		}
//		cout<<"________________________\n";
//		rep(i,1,n)cout<<f(a[i],0)<<' '; cout<<endl;
//		rep(i,1,n)cout<<a[i]<<' '; cout<<endl;
//		cout<<"________________________\n";
//		db(f(2,2));
		rep(i,1,n){
			res^= f(a[i],0);
			//x
			if((res^f(a[i]-x,0))==0)++ans;//, cout<<i<<'x'<<endl;
			//y
			if((res^f(a[i]-y,1))==0)++ans;//, cout<<i<<'y'<<endl;
			//z
			if((res^f(a[i]-z,2))==0)++ans;//, cout<<i<<'z'<<endl;
			res^= f(a[i],0);
		}
		cout<<ans<<endl;
	}
//	int mx = 0;
//	rep(a,1,5)rep(b,1,5)rep(c,1,5){
//		x = a, y = b, z = c;
//    	memset(dp,-1,sizeof dp);
//    	vis.clear();
//    	pos = 0;
//    	rep(i,1,5000){
//    		f(i,0);
//    		if(i>4){
//    			tmp = 0;
//    			rep(j,i-4,i)tmp = tmp*4 + dp[j][0];
//    			if(vis.count(tmp)){
//    				sz = i - vis[tmp];
//    				pos = i;
//    				break;
//				}
//				vis[tmp] = i;
//			}
//		}
//		rep(i,0,pos)cout<<f(i,0)<<' '; cout<<endl;
//		cout<<pos<<' '<<sz<<endl;
//		mx = max(mx,pos);
//	}
//	db(mx);
    return 0;
}