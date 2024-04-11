#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
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


const int N=2e5+5;

struct suffix_array{
	string s;
	vector<int>p,c;
	vector<int>lcp,len;
	int n;
	suffix_array(string str){
		s=str;
		n=s.size();p.resize(n);
		c.resize(n);lcp.resize(n);
		len.resize(n);
	}
	void count_sort(vector<int>&p,vector<int>&c){
		int n=p.size();
		vector<int>cnt(n);
		for(auto x:c)cnt[x]++;
		vector<int>p_new(n),pos(n);pos[0]=0;
		for(int i=1;i<n;i++)pos[i]=pos[i-1]+cnt[i-1];
		for(auto x:p){
			int i=c[x];
			p_new[pos[i]]=x;pos[i]++;
		}
		p=p_new;
	}
	void build(){
		vector<pair<char,int>>a(n);
		for(int i=0;i<n;i++)a[i]={s[i],i};
		sort(all(a));
		for(int i=0;i<n;i++)p[i]=a[i].y;
		c[p[0]]=0;
		for(int i=1;i<n;i++)c[p[i]]=(a[i].x==a[i-1].x)?c[p[i-1]]:c[p[i-1]]+1;	
		int k=0;
		while((1<<k)<n){
			for(int i=0;i<n;i++)p[i]=(p[i]-(1<<k)+n)%n;
			count_sort(p,c);
			vector<int>c_new(n);
			c_new[p[0]]=0;
			for(int i=1;i<n;i++){
				pii prev={c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
				pii now={c[p[i]],c[(p[i]+(1<<k))%n]};
				if(now==prev){
					c_new[p[i]]=c_new[p[i-1]];
				}
				else{
					c_new[p[i]]=c_new[p[i-1]]+1;
				}
			}
			c=c_new;
			k++;
		}
		for(int i=0;i<n;i++){
			len[i]=n-p[i];
		}
		k=0;
		for(int i=0;i<n-1;i++){
			int pi=c[i];int j=p[pi-1];
			while(s[i+k]==s[j+k])k++;
			lcp[pi]=k;k=max(0LL,k-1);
		}

	}

};

int par[N];
int suff[N];
vector<int>g[N];
int ans=0;
int d[N];
int dp[N];
void dfs(int u=0,int p=0){
		//cout<<u<<" ";
		
		if(g[u].size()==1){
			dp[u]++;
			//cout<<suff[u]<<endl;
		}
		for(auto i:g[u]){
			if(i!=p){
				dfs(i,u);
				dp[u]+=dp[i];
			}
		}
		int len=d[u]-d[p];
		if(g[u].size()==1)len--;
		if(u)ans+=len*dp[u]*dp[u];
		
}

int solve(){
 	string s;cin>>s;
 	s=s+'#';
 	int n=s.length();
 	suffix_array sa(s);
 	sa.build();
 	//for(int i=0;i<n;i++){
 	//	cout<<sa.p[i]<<" "<<s.substr(sa.p[i],n-sa.p[i]+1)<<endl;
 	//}
 	for(int i=0;i<N;i++){
 		g[i].clear(),par[i]=0;
 		d[i]=0;suff[i]=0;
 		dp[i]=0;
 	}
 	ans=0;
 	auto add=[&](int u,int v){
 		par[v]=u;
 	};
 	int cnt=0;add(0,1);cnt+=1;
 	d[cnt]=1;
 	suff[cnt]=sa.p[0];
 	for(int i=1;i<n;i++){
 		int dep=sa.lcp[i];
 		int u=cnt;
 		int v=-1;
 		while(d[u]>dep){
 			v=u;
 			u=par[u];
 		}
 		if(d[u]==dep){
 			cnt+=1;
 			add(u,cnt);
 		 	d[cnt]=sa.len[i];
 		}
 		else{	
 			cnt+=1;
 			add(u,cnt);d[cnt]=dep;
 			add(cnt,v);u=cnt;cnt+=1;
 			add(u,cnt);d[cnt]=sa.len[i];
 		}
 		suff[cnt]=sa.p[i];
 	}
 	for(int i=1;i<=cnt;i++){
 		g[i].pb(par[i]);
 		g[par[i]].pb(i);
 	}
 	dfs();
 	cout<<ans<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}