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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
int n,a,b,mx[MAX],len[MAX],ans;
vector<int> v[MAX],tmp[MAX];

inline bool cmp1(int A,int B){
	return A>B;
}
inline bool cmp2(pii A,pii B){
	if(A.fi==B.fi)return A.se>B.se;
	return A.fi>B.fi;
}

void tf(int nw,int par){
	for(auto i:v[nw]){
		if(i==par)continue;
		tmp[nw].pb(i);
		tf(i,nw);
	}
	return;
}

void dfs(int nw){
	if(v[nw].empty())return;
	if(v[nw].size()==1){
		for(auto i:v[nw]){
			dfs(i);
			len[nw] = len[i]+1;
			mx[nw] = max(mx[i],len[i]+1);
		}
	}
	else {
		vector<int> z;
		z.clear();
		for(auto i:v[nw]){
			dfs(i);
			len[nw] = max(len[nw],len[i]+1);
			z.pb(len[i]+1);
			mx[nw] = max(mx[nw],mx[i]);
		}
		mx[nw] = max(mx[nw],len[nw]);
		sort(all(z),cmp1);
		mx[nw] = max(mx[nw],z[0]+z[1]);
	}
	return;
}

void f(int nw,int mxi,int leni){
//	cout<<nw<<' '<<mxi<<' '<<leni<<endl;
	ans = max(ans,mx[nw]*mxi);
	if(v[nw].empty())return;
	if(v[nw].size()==1){
		for(auto i:v[nw]){
			f(i,max(mxi,leni),leni+1);
		}
	}
	else {
		int lenx,mxnx;
		vector<pii> z,mxx;
		z.clear();
		mxx.clear();
		for(auto i:v[nw]){
			z.pb({len[i]+1,i});
			mxx.pb({mx[i],i});
		}
		sort(all(z),cmp2);
		sort(all(mxx),cmp2);
//		if(nw==2){
//			db(leni);
//			for(auto i:z)cout<<">>>>    "<<i.fi<<' '<<i.se<<endl;
//		}
		
		if(v[nw].size()==2){
			for(auto i:v[nw]){
				if(z[0].se==i)lenx = max(leni+1,z[1].fi+1);
				else lenx = max(leni+1,z[0].fi+1);
				if(mxx[0].se==i)mxnx = max(max(mxi,mxx[1].fi),leni+len[mxx[1].se]+1);
				else mxnx = max(max(mxi,mxx[0].fi),leni+len[mxx[0].se]+1);
				f(i,max(mxnx,lenx-1),lenx);
			}
		}
		else {
			for(auto i:v[nw]){
				if(z[0].se==i)lenx = max(leni+1,z[1].fi+1);
				else lenx = max(leni+1,z[0].fi+1);
				if(mxx[0].se==i)mxnx = max(mxi,mxx[1].fi);
				else mxnx = max(mxi,mxx[0].fi);
				
				if(z[0].se==i)mxnx = max(mxnx,max(leni,z[2].fi)+z[1].fi);
				else {
					if(z[1].se==i)mxnx = max(mxnx,max(leni,z[2].fi)+z[0].fi);
					else mxnx = max(mxnx,max(leni,z[1].fi)+z[0].fi);
				}
				f(i,max(mxnx,lenx-1),lenx);
			}
		}
	}
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,2,n){
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
	}
	tf(1,0);
	rep(i,1,n)v[i] = tmp[i];
	dfs(1);
	f(1,0,0);
	cout<<ans<<endl;
	return 0;
}