#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

const int MOD = hell;
 
struct mod_int {
    int val;
 
    mod_int(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
 
        if (v >= MOD)
            v %= MOD;
 
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
 
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
 
        return x < 0 ? x + m : x;
    }
 
    explicit operator int() const {
        return val;
    }
 
    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
 
    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
 
    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
 
    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }
 
    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }
 
    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    mod_int operator++(int32_t) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int32_t) { mod_int before = *this; --*this; return before; }
 
    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }
 
    mod_int inv() const {
        return mod_inv(val);
    }
 
    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, mod_int &m) {
        return stream>>m.val;   
    }
};


const int N=1e5+5;

vector<int>g[N],in[N],out[N];
mod_int p[N];
pii dp[4*N][22];
int te=0,temp=0;
int tin[N],LOG[4*N],dep[N];
mod_int last=1;



void dfs(int u,int p){
	dep[u]=dep[p]+1;
	te++;
	tin[u]=te;
	dp[te][0]={dep[u],u};
	for(auto i:g[u]){
		if(i!=p){
			dfs(i,u);
			te++;
			dp[te][0]={dep[u],u};
		}
	}

}

int lca(int u,int v){
	int l=min(tin[u],tin[v]);
	int r=max(tin[u],tin[v]);
	int j=LOG[r-l+1];
	pii p=min(dp[l][j],dp[r-(1<<j)+1][j]);
	return p.y;
}

int dis(int u,int v){
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}


int ctree[N];
int sz[N];
int vis[N];
mod_int dp1[N],dp2[N];


void dfs1(int u,int par){
	 sz[u]=1;
	 temp++;
	 for(auto i:g[u]){
	 	if(i!=par && !vis[i]){
           	 	dfs1(i,u);
            		sz[u]+=sz[i];
	 	}
	 }
}
int dfs2(int u,int par){
	 for(auto i:g[u]){
	 	if(i!=par && sz[i]>temp/2 && !vis[i]){
             		return dfs2(i,u);
	 	}
	 }
	 return u;
}
void decompose(int u,int par){
	temp=0;
	dfs1(u,u);
	int centroid=dfs2(u,u);
	ctree[centroid]=par;
	vis[centroid]=1;
	for(auto i:g[centroid]){
	   	   if(vis[i])continue;
	   	   decompose(i,centroid);
	} 
}


mod_int insert(int u){
	mod_int sum=0;
	mod_int s=0;
	int i=u;
	while(i>0){
		int d=dis(u,i);		
		sum=sum+d*p[u]*(dp2[i]-s)+dp1[i]*p[u];
		s=dp2[i];
		dp2[i]=dp2[i]+p[u];
		dp1[i]=dp1[i]+p[u]*d;
		int v=ctree[i];
		if(v>0){
			int d2=dis(u,v);
			dp1[i]=dp1[i]-d2*p[u];
		}
		i=v;
	}
	return sum;
}
mod_int remove(int u){
	int i=u;
	mod_int sum=0;
	mod_int s=0;
	while(i>0){
		int d=dis(u,i);	
		sum=sum+d*p[u]*(dp2[i]-s)+dp1[i]*p[u];	
		s=dp2[i];
		dp2[i]=dp2[i]-p[u];
		dp1[i]=dp1[i]-p[u]*d;
		int v=ctree[i];
		if(v>0){
			int d2=dis(u,v);
			dp1[i]=dp1[i]+d2*p[u];
		}
		i=v;
	}
	return sum;
}





int solve(){
 	int n;cin>>n;
 	rep(i,1,n+1){
 		int l;int r;cin>>l>>r;
 		in[l].pb(i),out[r].pb(i);
 		mod_int val=r-l+1;
 		p[i]=val.inv();
 		last*=val;
 		
	}
 	rep3(n-1){
 		int u,v;cin>>u>>v;
 		g[u].pb(v);
 		g[v].pb(u);
 	}
 	dfs(1,1);
 	mod_int ans=0;
 	for(int j=1;j<=20;j++){
 		for(int i=1;i+(1<<(j-1))<=te;i++){
 			dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
 		}
 	}
 	decompose(1,0);
 	//for(int i=1;i<=n;i++)cout<<ctree[i]<<" ";cout<<endl;
 	mod_int t=0;
 	for(int i=1;i<=1e5;i++){
 		for(auto j:in[i]){
 			mod_int s=insert(j);
 			//cout<<"&"<<j<<" "<<s*last<<endl;
 			t+=s;
 		}
 		ans+=t;
 		for(auto j:out[i]){
 			mod_int s=remove(j);
 			//cout<<"%"<<j<<" "<<s*last<<endl;
 			t-=s;
 		}		
 	}
 	cout<<ans*last<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for(int i=2;i<4*N;i++){
    	LOG[i]=1+LOG[i/2];
    }
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}