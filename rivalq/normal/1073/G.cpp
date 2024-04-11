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


const int maxn=2000005;
int p[maxn];
int sz[maxn];
int dp1[maxn];
int dp2[maxn];
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
    p[p2]=p1;
    sz[p1]+=sz[p2];
    dp1[p1]+=dp1[p2];
    dp2[p1]+=dp2[p2];
    
}    

template<typename T>
struct suffix_array{
	T s;
	vector<int>p,c;
	vector<int>lcp,len;
	int n;
	suffix_array(T str){
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
		vector<pair<int,int>>a(n);
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
const int N=4e5+5;

int st[N][21];
int LOG[N];
int solve(){
 	int n,q;cin>>n>>q;
 	string s;cin>>s;
 	s+='$';
 	suffix_array<string> sa(s);
 	sa.build();
 	//for(int i=0;i<=n;i++){
 	//	cout<<sa.p[i]<<" "<<s.substr(sa.p[i],n+1-sa.p[i])<<endl;
 	//}
 	vector<int>inv(n+1);
 	rep(i,0,n+1)inv[sa.p[i]]=i;

 	for(int i=1;i<=n;i++){
 		st[i][0]=sa.lcp[i];
 	}
 	for(int x=1;x<=18;x++){
 		for(int i=1;i+(1<<(x-1))<=n;i++){
 			st[i][x]=min(st[i][x-1],st[i+(1<<(x-1))][x-1]);
 		}
 	}
 	auto get_min=[&](int l,int r){
 		int j=LOG[r-l+1];
 		return min(st[l][j],st[r-(1<<j)+1][j]);
 	};
 	auto lcp=[&](int i,int j){
 		if(i==j)return n-i;
 		int l=min(sa.c[i]+1,sa.c[j]+1);
 		int r=max(sa.c[i],sa.c[j]);
 		return get_min(l,r);
 	};
 	rep(i,0,q){
 		int k1,k2;cin>>k1>>k2;
 		//cout<<"#"<<" "<<k1<<" "<<k2<<endl;
 		vector<pii>a;
 		int c=0;
 		map<int,int>mp1,mp2;
 		rep(j,0,k1){
 			int t;cin>>t;--t;
 			mp1[t]=c++;
 			a.pb({t,0});
 		}
 		rep(j,0,k2){
 			int t;cin>>t;--t;
 			mp2[t]=c++;
 			a.pb({t,1});
 		}
 		rep(j,0,k1){
 			p[j]=j;sz[j]=1;
 			dp1[j]=1;dp2[j]=0;
 		}
 		rep(j,k1,c){
 			p[j]=j;sz[j]=1;
 			dp2[j]=1;dp1[j]=0;
 		}
 		sort(a.begin(),a.end(),[&](pii p1,pii p2){
 			return (p1.x==p2.x)?0:inv[p1.x]<inv[p2.x];
 		});
 		vector<pair<int,pii>>edges;
 		//for(auto j:a)cout<<j.x<<" ";cout<<endl;
 		auto get=[&](pii p){
 			if(p.y==0)return mp1[p.x];
 			else return mp2[p.x];
 		};
 		for(int j=1;j<sz(a);j++){
 			int w=lcp(a[j].x,a[j-1].x);
 			int u=get(a[j-1]);
 			int v=get(a[j]);
 			//cout<<"& "<<u<<" "<<v<<endl;
 			edges.pb({w,{u,v}});
 		}
 		sort(edges.begin(),edges.end());
 		reverse(edges.begin(),edges.end());
 		int ans=0;
 		for(auto j:edges){
 			int u=root(j.y.x);
 			int v=root(j.y.y);
 			ans+=(dp1[u]*dp2[v]+dp1[v]*dp2[u])*j.x;
 			merge(u,v);
 		}
 		cout<<ans<<endl;
 	}

 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for(int i=2;i<N;i++)LOG[i]=1+LOG[i/2];
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