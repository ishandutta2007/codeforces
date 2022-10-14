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
		

const int N=3e5;

vector<int>g[N];
int pre[N];
int par[N];
int suff[N];
int dp[N];
int d[N];
int L[N],R[N];
int ans[N];
int ra[N];
int in[N],out[N];
int t=0;
int aux[N];
vector<int>label;
vector<pair<pii,int>>query;
auto range_add=[&](int l,int r,int val){
 	pre[l]+=val;
 	pre[r+1]-=val;
 };

int k;
void dfs(int u=0,int p=0){
	L[u]=hell,
	R[u]=-1;
	in[u]=++t;
	if(sz(g[u])==1){
		mins(L[u],ra[u]);
		maxs(R[u],ra[u]);
		aux[t]=label[suff[u]];
		out[u]=t;
	}
	else{
		for(auto i:g[u]){
			if(i!=p){
				dfs(i,u);
				mins(L[u],L[i]);
				maxs(R[u],R[i]);
			}
		}
		if(u){
			dp[u]=d[u]-d[p];
			out[u]=t;
			query.pb({{in[u],out[u]},u});	
		}
		
	}
}

template<typename T>
struct Fenwick{
    vector<T> tree;
    Fenwick(int n){
        tree.resize(n);
    }

    T query(int i){
        int sum=0;
        while(i){
           sum+=tree[i];
           i-=i&(-i);
       }  
       return sum;
    }
    void update(int i,int n,T val){
       while(i<=n){
          tree[i]+=val;
          i+=i&(-i);
       }
    }
};



int solve(){
 	int n;cin>>n>>k;
 	vector<string>st(n+1);
 	vector<int>s;
 	rep(i,1,n+1){
 		cin>>st[i];
 		for(auto j:st[i]){
 			s.pb(j);
 			label.pb(i);
 		}
 		s.pb(-i);
 		label.pb(0);
 	}
 	//for(int i=0;i<sz(label);i++){
 	//	cout<<label[i]<<" ";
 	//}cout<<endl;
 	if(k==1){
 		rep(i,1,n+1){
 			int k=st[i].length();
 			cout<<k*(k+1)/2<<" ";
 		}
 		return 0;
 	}
 	suffix_array<vector<int>> sa(s);
 	sa.build();
 	int m=s.size();
 	//for(int i=0;i<m;i++){
 		//cout<<sa.p[i]<<endl;
 	//	for(int j=sa.p[i];j<m;j++)cout<<char(s[j])<<" ";cout<<endl;
 	//}
 	// lcp[i] connects p[i] and p[i-1] , we conside from i=2 .
 	auto add=[&](int u,int v){
 		par[v]=u;
 	};
 	int cnt=0;add(0,1);cnt+=1;
 	d[cnt]=1;
 	suff[cnt]=sa.p[0];
 	ra[cnt]=0;
 	for(int i=1;i<m;i++){
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
 		ra[cnt]=i;
 	}
 	for(int i=1;i<=cnt;i++){
 		g[i].pb(par[i]);
 		g[par[i]].pb(i);
 	}
 	dfs();
 	sort(query.begin(),query.end(),[&](pair<pii,int>p1,pair<pii,int>p2){return p1.x.y<p2.x.y;});
 	Fenwick<int>fn(t+1);
 	map<int,int>last;
 	int j=0;

 	for(int i=1;i<=t;i++){
 		if(aux[i]>0){
 			fn.update(i,t,1);
 			if(last.count(aux[i]))fn.update(last[aux[i]],t,-1);
 			last[aux[i]]=i;
 		}
 		while(j<sz(query) && query[j].x.y==i){
 			int val=fn.query(i)-fn.query(query[j].x.x-1);
 			//cout<<i<<" "<<query[j].x.x<<" "<<val<<endl;
 			if(val>=k)range_add(L[query[j].y],R[query[j].y],dp[query[j].y]);
 			j++;
 		}
 	}
 	rep(i,1,m){
 		pre[i]+=pre[i-1];
 		ans[label[sa.p[i]]]+=pre[i];
 	}
 	rep(i,1,n+1){
 		cout<<ans[i]<<" ";
 	}
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