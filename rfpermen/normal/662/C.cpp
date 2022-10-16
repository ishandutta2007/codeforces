#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
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
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<pll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 2505;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e15;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,m,x[MAX],y,id,a,b,cnt[MAX*20][22],ans,res,pre[25];
bool st[MAX*20];
vector<int> lvl[25],v[MAX*20];
char c;

void f(int z,int le,int ri,int par){
	if(!z){
		cnt[par][st[par]] = ri-le+1;
//		cout<<">> "<<le<<' '<<ri<<endl;
//		db(st[par]);
//		db(cnt[par][st[par]]);
		return;
	}
	int mid, res = ri+1;
	a = le, b = ri, y = 1<<z;
	while(a<=b){
		mid = a+b>>1;
		if(x[mid]&y)res = mid, b = mid-1;
		else a = mid+1;
	}
//	cout<<z<<' '<<le<<' '<<ri<<" -> "<<res<<endl;
	if(res!=le)lvl[z].pb(++id), v[par].pb(id), f(z-1,le,res-1,id);
	if(res<=ri)st[++id] = 1, lvl[z].pb(id), v[par].pb(id), f(z-1,res,ri,id);
	return;
}

void bf(int z,bool q){
	if(z>n){
		if(q)return;
		res = 0;
		for(int i:v[0]){
//			db(i);
			
//			cout<<i<<" = ";
			rep(j,0,n){
//				cout<<cnt[i][j]<<' ';
				res+= cnt[i][j]*pre[j];
			}
//			cout<<endl;
		}
		ans = min(ans,res);
		return;
	}
	if(z==1){
		if(q)for(int i:lvl[z])cnt[i][0]^=cnt[i][1]^=cnt[i][0]^=cnt[i][1];
//		cout<<">> "<<z<<' '<<q<<endl;
//		for(int i:lvl[z]){
//			cout<<i<<" = ";
//			rep(j,0,1)cout<<cnt[i][j]<<' '; cout<<endl;
//		}
//		cout<<"_________\n";
	}
	else {
		for(int i:lvl[z]){
			rep(j,0,z)cnt[i][j] = 0;
			if(q^st[i]){
				for(int k:v[i]){
					for(int j = 0; j<z; ++j)cnt[i][j+1]+= cnt[k][j];
				}
			}
			else {
				for(int k:v[i]){
					for(int j = 0; j<z; ++j)cnt[i][j]+= cnt[k][j];
				}
			}
		}
	}
	bf(z+1,0);
	bf(z+1,1);
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,0,n)pre[i] = min(i,n-i);
    rep(i,1,n){
    	y = 1<<i;
    	rep(j,1,m){
    		cin>>c;
    		if(c=='1')x[j]|= y;
		}
	}
//	rep(i,1,m)cout<<x[i]<<' '; cout<<endl;
	sort(x+1,x+1+m);
	f(n,1,m,0);
//	rep(i,1,n){
//		cout<<"lvl-"<<i<<" = ";
//		for(int j:lvl[i])cout<<j<<' '; cout<<endl;
//	}
//	rep(i,1,n){
//		for(int j:lvl[i]){
//			cout<<j<<" = ";
//			for(int k:v[j])cout<<k<<" ";cout<<endl;
//		}
//	}
	ans = MOD;
	bf(0,0);
	cout<<ans<<endl;
//	db(id);
	return 0;
}