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

const int N=55;
int a[N],b[N];

int32_t main(){

    int t;
    cin>>t;
    while(t--){
    	int n,k;
    	cin>>n>>k;
    	string s;
    	cin>>s;
    	int ans=0,pw=0;
    	int f=-1;
    	forn(i,n){
    		if(s[i]=='W'){
    			f=i;
    			break;
    		}
    	}
    	forn(i,n){
    		if(s[i]=='W'){
    			ans+=pw+1;
    			pw=1;
    		}else{
    			pw=0;
    		}
    	}
    	if(!k){
    		cout<<ans<<'\n';
    	}else if(f==-1){
    		cout<<k*2-1<<'\n';
    	}else{
    		vector<int> v;
    		int c=0;
    		for(int i=f;i<n;++i){
    			if(s[i]=='L'){
    				c++;
    			}else{
    				if(c)v.pb(c);
    				c=0;
    			}
    		}
    		int l=c;
    		sort(v.begin(), v.end());
    		reverse(v.begin(), v.end());
    		while(k&&!v.empty()){
    			ans+=2;
    			k--;
    			v.back()--;
    			if(v.back()==0){
    				v.pop_back();
    				ans++;
    			}
    		}
    		while(k&&l){
    			ans+=2;
    			k--;
    			l--;
    		}
    		while(k&&f){
    			ans+=2;
    			k--;
    			f--;
    		}
    		cout<<ans<<'\n';
    	}
    }

    return 0;
}