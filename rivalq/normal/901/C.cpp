#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

const int N = 3e5+5;


vector<int>g[N];
vector<pii>cyc;
int vis[N],par[N];
vector<int>st;
int dp[N];
void dfs(int u,int v){
	vis[u]=1;
	par[u]=v;
	st.push_back(u);
	for(auto i:g[u]){
		if(i!=v){
			if(vis[i]==1){
				int l=hell,r=-hell;
				auto itr=st.rbegin();
				while(1){
					mins(l,*itr);
					maxs(r,*itr);
					if(*itr==i)break;
					itr++;
				}
				cyc.pb({l,r});
			}
			else if(!vis[i]){
				dfs(i,u);
			}
		}
	}
	vis[u]=2;
	st.pop_back();
}




struct Fenwick{
    vector<pii> tree;
    Fenwick(int n){
        tree.resize(n);
    }

    pii query(int i){
        pii sum={0,0};
        while(i){
           sum.x+=tree[i].x;
           sum.y+=tree[i].y;
           i-=i&(-i);
       }  
       return sum;
    }
    void update(int i,int n,pii val){
       while(i<=n){
          tree[i].x+=val.x;
          tree[i].y+=val.y;
          i+=i&(-i);
       }
    }
};

int solve(){
 		int n,m;cin>>n>>m;
 		rep(i,0,m){
 			int a,b;cin>>a>>b;
 			g[a].pb(b);
 			g[b].pb(a);
 		}
 		rep(i,1,n+1){
 			dp[i]=hell;
 			if(!vis[i]){
 				dfs(i,i);
 			}
 		}
 		for(auto i:cyc){
 			mins(dp[i.x],i.y-1);
 		}
 		int gmn=n;
 		vector<pii>v;
 		for(int i=n;i>=1;i--){
 			mins(gmn,dp[i]);
 			dp[i]=gmn;
 			v.pb({dp[i],i});
 		}
 		sort(all(v));reverse(all(v));
 		int q;cin>>q;
 		vector<int>ans(q+1);
 		Fenwick fn(n+1);
 		vector<pii>vec[n+1];
 		rep(i,1,q+1){
 			int l,r;cin>>l>>r;
 			ans[i]+=(r-l+1);
 			ans[i]-=(r*(r+1)/2);
 			ans[i]+=(l*(l-1)/2);
 			vec[r].pb({l,i});
 		}

 		rep(i,1,n+1){
 			while(!v.empty() && v.back().x==i){
 				fn.update(v.back().y,n,{i,1});
 				v.pop_back();
 			}
 			for(auto [l,j]:vec[i]){
 				int len=i-l+1;
 				pii p =fn.query(i);
 				pii p2=fn.query(l-1);
 				p.x-=p2.x;p.y-=p2.y;
 				len-=p.y;
 				ans[j]+=p.x+len*i;
 			}
 		}
 		rep(i,1,q+1){
 			cout<<ans[i]<<endl;
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