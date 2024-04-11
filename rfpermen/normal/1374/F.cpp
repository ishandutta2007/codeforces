#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
 
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pll>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 200;

int tc,n,x[MAX],cnt,mx,mn,id;
vector<int> ans;
map<int,int> m;

inline void tf(int id){
	if(id>n-2)return;
	ans.pb(id);
	rep(i,0,1)rep(j,i+1,2)if(x[id+i]>x[id+j])--cnt;
	swap(x[id+1],x[id+2]), swap(x[id],x[id+1]);
	rep(i,0,1)rep(j,i+1,2)if(x[id+i]>x[id+j])++cnt;
	return;
}

inline bool cek(){
	rap(i,n,3){
		if((x[i-2]==x[i-1] && x[i-1]!=x[i])){
			tf(i-2);
			tf(i-2);
			return true;
		}
	}
	rap(i,n,3){
		if((x[i-2]==x[i] && x[i-1]!=x[i])){
			tf(i-2);
			return true;
		}
	}
	return false;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    rep(ntc,1,tc){
    	cin>>n;
    	mx = cnt = 0, m.clear();
    	rep(i,1,n)cin>>x[i], m[x[i]]++;
    	for(auto i:m)mx = max(mx,i.se);
    	rep(i,1,n)rep(j,i+1,n)if(x[i]>x[j])++cnt;
    	
    	if(cnt%2 && mx==1){cout<<"-1\n"; continue;}
    	ans.clear();
    	while(cnt){
    		rep(i,1,n){if(cnt&1){
    				if(cek())break;
				}
    			mn = MOD;
    			rep(j,i,n)if(x[j]<mn)mn = x[j], id = j;
//    			cout<<">> "<<i<<' '<<id<<endl;
    			while(id!=i){
    				if(id-i>1)tf(id-2), id-=2;
    				else tf(id-1), tf(id-1), --id;
				}
				
			}
//			cout<<">> "; rep(i,1,n)cout<<x[i]<<' '; cout<<endl;
//			break;
//			db(ntc);
//			db(cnt);
		}
//		cout<<">> "; rep(i,1,n)cout<<x[i]<<' '; cout<<endl;
		cout<<ans.size()<<endl;
		for(auto i:ans)cout<<i<<' '; cout<<endl;
	}
	return 0;
}