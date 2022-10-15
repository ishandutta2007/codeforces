#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sz(a)((int)(a).size())
#define sqr(x) ((x)*(x))
struct init{init(){cin.tie(0);iostream::sync_with_stdio(0);cout<<fixed<<setprecision(10);cerr<<fixed<<setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());const int D=4,dx[]={+1,0,-1,0},dy[]={0,+1,0,-1};

const int N=60;
int b[N];
struct kek{
	int x;char c;int y;
};
vector<kek> ans;
void add(int x){
	forn(i,N){
		if(x>>i&1){
			if(b[i]==-1){
				b[i]=x;
				break;		
			}else{
				ans.push_back({x,'^',b[i]});
				x^=b[i];
			}
		}
	}
}
pair<bool,vector<int>> get(int x){
	vector<int> res;
	forn(i,N){
		if(x>>i&1){
			if(b[i]==-1){
				return {0,res};
			}
			res.pb(b[i]);
			x^=b[i];
		}
	}
	return {1,res};
}

int32_t main(){
	int x;
	cin>>x;
	// for(int x=909091;x<1000000;x+=2){
		ans.clear();
		forn(i,N)b[i]=-1;
		add(x);
		int c=0;
		vector<int> pws={x};
		for(int p=x;p<=1e18;p*=2){
			ans.push_back(kek{p,'+',p});
			pws.pb(p+p);
		}
		int mx=sz(pws);
		for(int i=2;!get(1).f;++i){
			if(!get(x*i).f){
				vector<int> bits;
				forn(j,mx){
					if(i>>j&1){
						bits.pb(j);
					}
				}
				int s=pws[bits[0]];
				for(int j=1;j<sz(bits);++j){
					ans.push_back(kek{s,'+',pws[bits[j]]});
					s+=pws[bits[j]];
				}
				dbg(x*i);
				add(x*i);
				c++;
			}
			// cout<<x<<" + "<<x*i<<'\n';
		}
		dbg(x,c);
		auto qwe=get(1);
		auto v=qwe.s;
		int xo=v[0];
		for(int i=1;i<sz(v);++i){
			ans.push_back(kek{v[i],'^',xo});
			// cout<<v[i]<<" ^ "<<xo<<'\n';
			xo^=v[i];
		}
		assert(sz(ans)<100000);
		cout<<sz(ans)<<'\n';
		for(auto i:ans)cout<<i.x<<' '<<i.c<<' '<<i.y<<'\n';
	// }
    return 0;
}