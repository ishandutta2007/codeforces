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

const int maxn=200005;

vector<int>g[maxn];
int s1[maxn],s2[maxn];
int a[maxn];
int b[maxn];
int c[maxn];
int ans=0;
void dfs(int u=1,int p=0,int m=1e18){
     if(b[u]!=c[u]){
            if(c[u]==0)s1[u]++;
            else s2[u]++; 
     }
     mins(m,a[u]);
     for(auto i:g[u]){
     		if(i!=p){
     			dfs(i,u,m);
     			s1[u]+=s1[i];
     			s2[u]+=s2[i];
     		}
     }
     int t=min(s1[u],s2[u]);
     ans+=2*t*m;
     s1[u]-=t;
     s2[u]-=t;
}

int solve(){
	int n;cin>>n;
	rep(i,1,n+1){
		cin>>a[i]>>b[i]>>c[i];
	} 
	rep3(n-1){
		int a,b;cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs();
	if(s1[1]!=0 ||s2[1]!=0){
		cout<<-1<<endl;return 0;
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