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
			lcp[pi]=k;k=max(0,k-1);
		}

	}

};


const int maxn=2000005;
int p[maxn];
int sz[maxn];
int dp[maxn];
void clear(int n=maxn){
    rep(i,0,maxn)p[i]=i,sz[i]=1;
}
int root(int x){
   while(x!=p[x]){
       p[x]=p[p[x]];
       x=p[x];
   }
   return x;  
}
void merge(int x,int y){
    int p1=root(x);
    int p2=root(y);
    if(p1==p2)return;
    if(sz[p1]<sz[p2])swap(p1,p2);
    sz[p1]+=sz[p2];
    dp[p1]+=dp[p2];
    p[p2]=p1;
}


int solve(){
 	int n;cin>>n;
 	string s;cin>>s;
 	// ending at suffix i of s is same as starting at suffix n-i+1 of s
 	reverse(all(s));
 	vector<bool>bad(n+1);
 	int cnt=0;
 	bad[n]=1;
 	ll ans=0;
 	rep(i,0,n){
 		char c;cin>>c;
 		int x=c-48;
 		if(x==0)ans=i+1;
 		bad[n-1-i]=x;
 	}
 	if(cnt==n){
 		cout<<0<<endl;return 0;
 	}
 	clear();
 	for(int i=0;i<=n;i++){
 		dp[i]=bad[i];
 	}
 	s=s+'$';
 	suffix_array sa(s);
 	sa.build();
 	/**for(int i=0;i<=n;i++){
 		cout<<sa.p[i]<<" "<<s.substr(sa.p[i],n-sa.p[i]+1)<<endl;
 	}
 	// edge of weight lcp[i] connects p[i] ans p[i-1]
 	for(int i=1;i<=n;i++){
 		cout<<s.substr(sa.p[i],n-sa.p[i]+1)<<" "<<s.substr(sa.p[i-1],n-sa.p[i-1]+1)<<" "<<sa.lcp[i]<<endl;
 	}**/
 	vector<pii>edges;
 	for(int i=1;i<=n;i++)edges.eb(sa.lcp[i],i);
 	sort(all(edges),greater<pii>());
 	for(auto i:edges){
 		int j=i.y;
 		int u=sa.p[j];
 		int v=sa.p[j-1];
 		merge(u,v);
 		int k=sz[root(u)]-dp[root(u)];
 		maxs(ans,1LL*i.x*k);
 	}	
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
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}