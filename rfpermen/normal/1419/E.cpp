#include<bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 3e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int tc,tmp,n,res,k,cnt,hl;
bool pr[MAX];
vector<pii> fc;
vector<int> p,ans,x[20];

void bf(int nw,int z){
	if(nw==k){
		if(z==1)return;
		asd(i,0,k)if(z%fc[i].fi==0){
			x[i].pb(z);
			break;
		}
		return;
	}
	rep(i,0,fc[nw].se)bf(nw+1,z), z*= fc[nw].fi;
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	rep(i,2,177){
		if(pr[i])continue;
		for(int j = i*i; j<=31622; j+=i)pr[j] = i;
	}
	rep(i,2,31622)if(!pr[i])p.pb(i);
	
	cin>>tc;
	rep(ntc,1,tc){
		cin>>n; tmp = n;
		fc.clear();
		for(int i:p){
			if(i*i>n)break;
			if(n%i==0){
				cnt = 0;
				while(n%i==0)n/= i, ++cnt;
				fc.pb({i,cnt});
			}
		}
		if(n!=1)fc.pb({n,1});
		k = fc.size();
		asd(i,0,k)x[i].clear();
		bf(0,1);
		n = tmp;
		ans.clear();
		ans.pb(n);
		fc.pb({MOD,0});
		
		asd(i,0,k){
			hl = 0;
			for(int j:x[i]){
				if(j==n)continue;
				if(hl || j%fc[i+1].fi!=0)ans.pb(j);
				else hl = j;
			}
			if(hl)ans.pb(hl);
		}
		for(int i:ans)cout<<i<<' '; cout<<endl;
		res = 0;
		k = ans.size();
		asd(i,0,k)if(__gcd(ans[i],ans[(i+1)%k])==1)++res;
		cout<<res<<endl;
	}
	return 0;
}