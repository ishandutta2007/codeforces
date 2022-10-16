#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define asd(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
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
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e7+5;
const ll MOD = 1000000009;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}
inline void read(int &x){
	char c=getchar();x=0;
	while(c<48||c>57)c=getchar();
	while(c>=48&&c<=57)x=x*10+(c&15),c=getchar();
	return;
}

int n,a,dv[MAX],cnt[MAX],nx[MAX],hit[MAX],mx;
ll x[MAX],ans,gs,tmp,c,res,ret;
 
inline ll f(ll a,ll b){
	if(a<=b)return a*b;
	tmp = a, c = 0;
	while(tmp)tmp/= b, ++c;
	gs = a*(b-1)/b + c/2;
	ret = tmp = gs;
	while(tmp>=b)tmp/= b, ret+= tmp;
	if(ret>=a){
		while(1){
			--gs;
			ret = tmp = gs;
			while(tmp>=b)tmp/= b, ret+= tmp;
			if(ret<a)break;
		}
		res = gs+1;
	}
	else {
		while(1){
			++gs;
			ret = tmp = gs;
			while(tmp>=b)tmp/= b, ret+= tmp;
			if(ret>=a)break;
		}
		res = gs;
	}
	return res*b;
}
 
int main(){
//	cout<<fixed<<setprecision(9);
// freopen("output.txt", "r", stdin);
// freopen("output.txt","w",stdout);
//	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for(int i = 2; i<MAX; ++i)if(!dv[i]){
		for(int j = i; j<MAX; j+=i)dv[j] = i;
	}
	read(n);
	rep(i,1,n){
		read(a);
		mx = max(mx,a);
		++cnt[a];
	}
	n-= cnt[1];
	rep(i,2,mx){
		a = i/dv[i];
		if(dv[i]!=dv[a])nx[i] = a, hit[i] = 1;
		else nx[i] = nx[a], hit[i] = hit[a]+1;
		a = i;
		while(a!=1){
			x[dv[a]]+= hit[a]*n;
			a = nx[a];
		}
		n-= cnt[i];
	}
	ans = 1;
	rep(i,2,mx)if(x[i])ans = max(ans,f(x[i],i));
	printf("%lld",ans);
	return 0;
}